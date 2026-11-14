# CAT7B: 16x2 LCD Multi-Line Text Display & Dynamic Banners

## 🎯 Objective
Develop an abstracted LCD driver library for multi-line string rendering, automated text wrapping, and continuous horizontal message scrolling across both display lines.

## ⚡ Hardware Architecture & Pinout
- **MCU:** AT89S52
- **Display:** 16x2 HD44780 LCD (4-bit data bus on `P3.4-P3.7`, RS=`P3.2`, EN=`P3.3`).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **String Print Primitives:** `lcd_print(char *str)` streams null-terminated character arrays directly to display DDRAM.
2. **Row Switching Architecture:** Automatically routes characters exceeding column 15 to the second row base address (`0xC0`).
3. **Display Shift Commands:** Implements command `0x18` (Shift entire display left) combined with controlled delay cycles to yield a smooth marquee banner effect.

## 📊 Verification & Results
- Formatted two-line system status messages displayed without character corruption.
