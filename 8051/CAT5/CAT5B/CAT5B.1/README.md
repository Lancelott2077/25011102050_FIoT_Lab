# CAT5B.1 - High-Frequency Timer0 Software PWM Breathing LED

**EXP:** CAT5B.1

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - Software PWM Breathing LED

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52 (11.0592 MHz)
- Output Pin: Port 1 Pin 0 (P1.0) connected to an LED through a 330 Ω resistor
- Timer: Timer 0 configured for ~100 µs interrupt interval

**TASK NO:**
1. Configure Timer0 in Mode 1 to trigger periodic interrupts every ~100 µs.
2. Implement a 10-step software PWM generator on pin P1.0.
3. Create a smooth LED breathing effect by sweeping the duty cycle up and down.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Timer0 reloaded with `TH0 = 0xFF, TL0 = 0xA4` inside the ISR for a ~100 µs period.
- A PWM counter steps from 0 to 9 (1 kHz carrier frequency):
  - If `count < duty`, output pin is HIGH.
  - Else, output pin is LOW.
- A speed counter updates the `duty` variable every 500 ISR cycles:
  - If ramping up, `duty++` until 10.
  - If ramping down, `duty--` until 0.

**INFERENCE:**
A 1 kHz software PWM signal was successfully produced on a general-purpose 8051 pin without dedicated PWM hardware. The gradual ramp of the duty cycle produced a smooth and visually appealing LED breathing effect.
