# CAT4 - 4x3 Matrix Keypad Scanning & 7-Segment Display

**EXP:** CAT4

**DATE:** 03/08/26

**NAME OF EXP:** Matrix Keypad Scanning with 7-Segment Display and LED Pattern Control

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52 (11.0592 MHz)
- **4x3 Matrix Keypad (Port 2):**
  - Row lines: P2.7 (Row 1), P2.6 (Row 2), P2.5 (Row 3), P2.4 (Row 4) — Driven as Outputs
  - Column lines: P2.3 (Col 1), P2.2 (Col 2), P2.1 (Col 3) — Read as Inputs with pull-ups
- **7-Segment Display (Port 0):** Common-cathode display connected to P0.0–P0.7 (Segments a–g, dp) with external 10 kΩ pull-up resistor pack
- **Pattern Indicator LEDs (Port 1):** Pins P1.1–P1.4 connected to animation LEDs

**TASK NO:**
1. Implement active-LOW matrix scanning across the 4 rows and 3 columns of the keypad.
2. Decode pressed keys into numerical values (0–9) and display them using a 7-segment lookup table on Port 0.
3. Map designated function keys (5, 6, 7, 8) to unique LED animation routines on Port 1.
4. Ensure animation routines periodically sample the keypad to allow immediate interruption when a new key is pressed.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Scanning Technique:**
  1. Drive Row 1 LOW (`P2 = 0x7F`) and sample column pins (P2.3, P2.2, P2.1). If any column reads 0, record key 1, 2, or 3.
  2. Repeat for Row 2 (`0xBF` for keys 4, 5, 6), Row 3 (`0xDF` for keys 7, 8, 9), and Row 4 (`0xEF` for key 0).
  3. Reset Port 2 to idle state (`0xFF`).
- **7-Segment Segment Encoding:**
  Common-cathode segment mapping (Active-HIGH segments):
  `code unsigned char seg_table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};`
- **Interruptible Animation:**
  Animation loops check `keypad_scan()` between timing delays. If a new key is pressed, the current routine terminates immediately and returns execution to the main command dispatcher.

**INFERENCE:**
Multiplexing a 4x3 matrix reduced the I/O requirement from 12 individual lines down to 7 GPIO pins. Storing cathode bitmasks in code ROM eliminated runtime arithmetic decoding overhead. Non-blocking polling inside long-running visual animations preserved system responsiveness to user inputs.
