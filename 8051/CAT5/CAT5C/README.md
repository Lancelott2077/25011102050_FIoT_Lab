# CAT5C - 4-Phase Stepper Motor Full-Step Control

**EXP:** CAT5C

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - Stepper Motor Full-Step Sequencer

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Output Pins: Port 1 lower nibble (P1.0 - P1.3)
- Driver IC: ULN2003A Darlington Transistor Array
- Actuator: 28BYJ-48 5V Unipolar Stepper Motor (64:1 reduction ratio)

**TASK NO:**
1. Connect the 8051 GPIO pins to a 28BYJ-48 stepper motor via a ULN2003 driver board.
2. Implement a 4-step excitation sequence in firmware.
3. Control the direction of rotation and shaft stepping speed.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- 4-Phase Full-Step Sequence:
  - Step 1: Coil A ON (`0x01` on P1)
  - Step 2: Coil B ON (`0x02` on P1)
  - Step 3: Coil C ON (`0x04` on P1)
  - Step 4: Coil D ON (`0x08` on P1)
- Reversing the sequence reverses shaft rotation.
- Inter-step delay controls the stepping frequency and rotational speed.

**INFERENCE:**
The ULN2003 properly buffered the 8051 pins from the motor coil currents. The stepper motor rotated smoothly at controlled speeds in both clockwise and counter-clockwise directions without skipping steps.
