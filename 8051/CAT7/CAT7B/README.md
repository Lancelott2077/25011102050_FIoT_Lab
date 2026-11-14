# CAT7B - 16x2 LCD Multi-Line Text Formatting & Display

**EXP:** CAT7B

**DATE:** 24/08/26

**NAME OF EXP:** LCD Interfacing and Display Control - Multi-Line Messages and Scrolling

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Display: 16x2 Character LCD in 4-bit mode (RS=P3.2, EN=P3.3, D4-D7=P3.4-P3.7)

**TASK NO:**
1. Build modular LCD driver functions for strings and commands (`lcd_cmd`, `lcd_data`, `lcd_print`).
2. Display formatted two-line text messages on the screen.
3. Implement text scrolling across rows using HD44780 shift commands.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Modular driver files: `lcd.c` and `lcd.h`.
- Command `0x01`: Clears display and resets cursor address to 0.
- Command `0x0C`: Sets display ON with cursor OFF for clean text viewing.
- Command `0x18`: Shifts entire display contents one column to the left for banner marquee effects.

**INFERENCE:**
Clean modular drivers allowed text strings to be printed on specific rows without manual byte packing. Multi-line message display and automatic row selection were verified.
