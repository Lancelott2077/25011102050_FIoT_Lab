CAT4 - Keypad Scanning & 7-Segment Display

EXP: CAT4
DATE: 03/08/2026
NAME OF EXP: Matrix Keypad with 7-Segment Display

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52 | Keypad: 4x3 matrix on P2 | 7-Seg: P0 | LEDs: P1

TASK
1. 4x3 matrix keypad scanning
2. 7-segment digit display
3. LED pattern animations on special keys

CORE LOGIC
- Drive rows LOW one at a time, read columns to detect key
- Map key value to 7-segment encoding table

INFERENCE
Keypad scanning and 7-segment display driven directly from 8051 GPIO.
