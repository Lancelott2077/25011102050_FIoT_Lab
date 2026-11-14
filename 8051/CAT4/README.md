# CAT4: 4x3 Matrix Keypad Scanning & 7-Segment Display

## 🎯 Objective
Design a matrix keypad row/column scanner that drives a common-cathode 7-segment display for numeric keys and executes non-blocking animation sequences on designated function keys.

## ⚡ Hardware Architecture & Pinout
- **MCU:** AT89S52 (11.0592 MHz)
- **Keypad Matrix (Port 2):** Rows `P2.7-P2.4` (Outputs), Columns `P2.3-P2.1` (Inputs with pull-ups).
- **7-Segment Display (Port 0):** Segments a–g and dp connected to `P0.0`–`P0.7`.
- **Status LEDs (Port 1):** Pins `P1.1`–`P1.4` for pattern animations.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Multiplexed Matrix Scanning:** Driven rows LOW sequentially; column states are read. Pin-to-key resolution converts switch closures into key codes (0–9).
2. **Lookup Table (LUT) Decoding:** Stored seven-segment cathode bitmasks in code ROM (`code unsigned char seg_table[10]`) for instant O(1) character lookup.
3. **Interruptible Animation Modes:** Keys 5, 6, 7, and 8 trigger Running, Alternating, Binary, and Flash routines with continuous scan checks to abort immediately when a new key is pressed.

## 📊 Verification & Results
- Clean single-digit rendering from 0 to 9 on 7-segment display.
- Responsive, interruptible LED visual effects upon functional key inputs.
