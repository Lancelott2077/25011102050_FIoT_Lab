# CAT7A - 16x2 Character LCD 4-Bit Interface & Keypad Navigation

**EXP:** CAT7A

**DATE:** 24/08/26

**NAME OF EXP:** LCD Interfacing and Display Control - 4-Bit Mode with Keypad Navigation

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Display: 16x2 Alphanumeric LCD (HD44780 controller)
- LCD Connections (Port 3): RS = P3.2, EN = P3.3, Data lines D4-D7 = P3.4-P3.7
- 4x3 Keypad (Port 2): Keys 2 (Up), 8 (Down), 4 (Left), 6 (Right)

**TASK NO:**
1. Interface a 16x2 LCD using a 4-bit nibble data transfer mode to save pins.
2. Initialize display settings (4-bit, 2-line, 5x8 font, display ON, cursor ON).
3. Read directional keys from the keypad and move an asterisk cursor (`*`) across the 2x16 screen.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **4-Bit Nibble Mode:** Byte output sends high 4 bits first, toggles EN high-to-low, then sends low 4 bits and toggles EN again.
- **DDRAM Addressing:** Line 1 starts at 0x80; Line 2 starts at 0xC0. `lcd_goto(row, col)` writes command `0x80 | (row ? 0x40 + col : col)`.
- **Keypad Movement:**
  - Key 2: Decrements row (clamped to 0).
  - Key 8: Increments row (clamped to 1).
  - Key 4: Decrements column (clamped to 0).
  - Key 6: Increments column (clamped to 15).
  - Old position is erased with a space `' '` before drawing `'*'` at the new coordinate.

**INFERENCE:**
Operating the LCD in 4-bit mode reduced required data lines from 8 down to 4. Cursor position was navigated interactively across both rows and all 16 columns using the matrix keypad.
