# CAT7A - 16x2 Character LCD 4-Bit Interface & Keypad Navigation

**EXP:** CAT7A

**DATE:** 24/08/26

**NAME OF EXP:** LCD Interfacing and Display Control - 4-Bit Mode with Keypad Navigation

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52
- **Alphanumeric Display:** HD44780-compatible 16x2 Character LCD
  - Control lines: P3.2 connected to RS (Register Select), P3.3 connected to EN (Enable)
  - Data lines (4-bit mode): P3.4 connected to D4, P3.5 to D5, P3.6 to D6, P3.7 to D7
  - Contrast adjustment: 10 kΩ potentiometer connected to pin V0
- **Matrix Keypad:** 4x3 Keypad connected to Port 2 (Directional navigation keys: 2=Up, 8=Down, 4=Left, 6=Right)

**TASK NO:**
1. Implement the standard HD44780 4-bit nibble communication protocol to save microcontroller I/O pins.
2. Initialize display mode (4-bit, 2 lines, 5x8 font, display ON, cursor ON, blinking ON).
3. Read directional keys from the keypad and navigate an asterisk cursor (`*`) across the 2x16 character grid with boundary clamping.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **4-Bit Nibble Protocol:**
  Sending a byte in 4-bit mode requires splitting it into two 4-bit transfers:
  1. Send high nibble (`byte & 0xF0`) to P3.4–P3.7; toggle EN (High $ightarrow$ Low pulse of 1 ms).
  2. Send low nibble (`(byte << 4) & 0xF0`) to P3.4–P3.7; toggle EN.
- **Initialization Sequence:**
  Power-on delay (20 ms) $ightarrow$ Send `0x30` three times $ightarrow$ Send `0x20` to lock 4-bit mode $ightarrow$ Issue Function Set `0x28` (4-bit, 2 lines) $ightarrow$ Display ON `0x0F` $ightarrow$ Clear Display `0x01`.
- **DDRAM Addressing:**
  Row 0 base address = `0x80`; Row 1 base address = `0xC0`.
  `lcd_goto(row, col)` sends command byte `0x80 | (row == 0 ? col : 0x40 + col)`.
- **Movement Engine:**
  - Erases old position by writing `' '`.
  - Updates `row` (clamped between 0 and 1) or `column` (clamped between 0 and 15).
  - Writes `'*'` at the new coordinate.

**INFERENCE:**
Using 4-bit mode preserved 4 GPIO lines on Port 3 without degrading screen update performance. The HD44780 command structure and DDRAM addressing were verified by navigating the cursor interactively using matrix keypad directional inputs.
