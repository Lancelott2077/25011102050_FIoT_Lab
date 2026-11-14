# CAT5B.2 - Software PWM DC Motor Speed Control

**EXP:** CAT5B.2

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - PWM DC Motor Speed Regulation

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52
- **Output Pin:** Port 1 Pin 0 (`P1^0`) delivering PWM control signal
- **Driver Interface:** Transistor driver / L293D dual H-bridge motor driver IC
- **Actuator:** 5V Small DC Toy Motor with 1N4007 flyback diode connected across motor terminals

**TASK NO:**
1. Generate variable-duty PWM waveforms from the 8051 using Timer 0 interrupts.
2. Interface the PWM output pin to an external motor driver circuit to protect MCU pins from motor current draw.
3. Observe and measure rotational speed variation across stepped duty ratios (25%, 50%, 75%, 100%).

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- The average voltage applied to the motor is directly proportional to the duty cycle ratio:
  $$V_{	ext{motor(avg)}} = V_{	ext{supply}} 	imes rac{T_{	ext{ON}}}{T_{	ext{ON}} + T_{	ext{OFF}}}$$
- The driver circuit buffers the 8051 pin (which can sink/source only ~10–20 mA) and handles the motor's higher inductive running current (~150–250 mA).
- A flyback diode placed antiparallel to the motor terminals clamps inductive back-EMF voltage spikes generated during PWM off-switching.

**INFERENCE:**
Regulating the average voltage delivered to the motor through variable-duty PWM provided smooth speed regulation without requiring analog voltage dividers. The inductive clamping diode and driver stage prevented electrical noise and back-EMF transients from resetting the microcontroller.
