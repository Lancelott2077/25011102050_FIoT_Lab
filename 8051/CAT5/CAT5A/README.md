CAT5A - Timer Interrupt LED Blink (1 Second)

EXP: CAT5A
DATE: 10/08/2026
NAME OF EXP: Timer0 Interrupt - Precise 1 Second LED Toggle

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52 | LED: P1^0

TASK
1. Configure Timer0 Mode 1
2. 10ms ISR, count 100 overflows for 1 second
3. Toggle LED, main in IDLE mode

CORE LOGIC
- Timer0 Mode 1, preloaded for 10ms overflow
- ISR increments counter, toggles LED at 100 counts
- Main: PCON |= 0x01 (sleep)

INFERENCE
Hardware timer interrupt achieves precise 1-second LED blinking without busy-wait.
