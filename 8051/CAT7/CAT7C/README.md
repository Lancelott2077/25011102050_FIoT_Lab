# CAT7C - Real-Time UART to 16x2 LCD Display Bridge

**EXP:** CAT7C

**DATE:** 24/08/26

**NAME OF EXP:** LCD Interfacing and Display Control - Real-Time UART to LCD Bridge

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52
- **Serial Input:** Port 3 Pin 0 (RXD) configured for 9600 Baud communication
- **Display Output:** 16x2 Character LCD wired on Port 3 pins P3.2–P3.7
- **Host Link:** PC Terminal emulator sending ASCII text stream

**TASK NO:**
1. Configure UART reception at 9600 baud alongside 4-bit LCD pin mappings on Port 3.
2. Ingest characters arriving asynchronously over serial and display them in real time on the LCD.
3. Handle control characters like carriage return (``) to wrap text to the second row.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Port 3 Dual-Function Assignment:**
  - P3.0: Serial RX input (Hardware UART peripheral)
  - P3.2: LCD RS
  - P3.3: LCD Enable
  - P3.4–P3.7: LCD Data Nibble
- Serial reception occurs via interrupt. Arriving bytes are checked:
  - If printable ASCII (`0x20` to `0x7E`): Write character directly using `lcd_data()`.
  - If `` or `
`: Advance cursor to Row 1 (`lcd_goto(1, 0)`).
  - If screen fills (32 characters): Clear display (`lcd_cmd(0x01)`) and reset cursor to (0, 0).

**INFERENCE:**
A functional hardware serial-to-visual bridge was demonstrated. Port 3 successfully hosted both serial communications and LCD strobe control lines without bus contention, rendering terminal keystrokes directly on the physical display in real time.
