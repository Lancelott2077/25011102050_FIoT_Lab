# CAT5B.2 - Software PWM DC Motor Speed Control

**EXP:** CAT5B.2

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - PWM DC Motor Speed Regulation

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Output Pin: Port 1 Pin 0 (P1.0)
- Motor Driver: Transistor / L293D driver with flyback diode
- Actuator: 5V DC Toy Motor

**TASK NO:**
1. Generate a variable-duty PWM signal using Timer0 interrupts.
2. Interface the PWM output to a motor driver circuit.
3. Verify speed variation across different duty cycle thresholds.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Timer0 ISR generates the base PWM timing intervals.
- The average voltage delivered to the motor terminals is proportional to the duty cycle ratio ($	ext{V}_{	ext{avg}} = 	ext{V}_{	ext{supply}} 	imes 	ext{Duty}$).
- Speed ramps smoothly by adjusting the duty ratio from 20% to 100% to prevent high starting current surges.

**INFERENCE:**
Timer0-generated PWM successfully varied the rotational speed of the DC motor. The driver circuit isolated motor inductive spikes from resetting the microcontroller.
