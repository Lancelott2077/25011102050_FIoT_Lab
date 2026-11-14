# CAT5B.3 - Timer PWM Servo Motor Sweep

**EXP:** CAT5B.3

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - Servo Motor Angular Sweep

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52 (11.0592 MHz)
- Output Pin: Port 1 Pin 0 (P1.0) connected to servo signal wire
- Actuator: SG90 / TowerPro Micro Servo (5V)
- Power: External regulated 5V supply with common ground

**TASK NO:**
1. Generate standard 50 Hz (20 ms period) RC servo control pulses using 8051 timers.
2. Modulate pulse width between 1.0 ms (-90°) and 2.0 ms (+90°).
3. Implement a continuous back-and-forth angular sweep of the servo horn.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- The servo requires a 20 ms repeating frame.
- High-time duration determines position:
  - 1.0 ms $\implies$ -90 degrees
  - 1.5 ms $\implies$ 0 degrees (neutral)
  - 2.0 ms $\implies$ +90 degrees
- Timer0 tracks high-pulse and low-pulse durations to maintain an accurate 50 Hz frame rate.

**INFERENCE:**
The AT89S52 generated stable 50 Hz PWM control pulses. The servo arm tracked the command signal cleanly across its full 180° range without jitter.
