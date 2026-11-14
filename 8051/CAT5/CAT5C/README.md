# CAT5C - 4-Phase Stepper Motor Full-Step Control

**EXP:** CAT5C

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - Stepper Motor Full-Step Sequencer

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52
- **Output Port:** Port 1 lower nibble: P1.0 (Coil A), P1.1 (Coil B), P1.2 (Coil C), P1.3 (Coil D)
- **Driver Module:** ULN2003A Darlington Transistor Array board
- **Motor:** 28BYJ-48 5V Unipolar 4-Phase Stepper Motor with internal 64:1 reduction gearbox

**TASK NO:**
1. Interface the 4-phase unipolar stepper motor to 8051 GPIOs through a ULN2003 driver board.
2. Implement a 4-step excitation wave sequence to drive motor coils sequentially.
3. Control the direction of shaft rotation (clockwise vs. counter-clockwise) and regulate speed via delay adjustments.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **4-Phase Full-Step Drive Sequence:**
  - Step 1: Coil A energized $\implies$ `P1 = 0x01` (`0b00000001`)
  - Step 2: Coil B energized $\implies$ `P1 = 0x02` (`0b00000010`)
  - Step 3: Coil C energized $\implies$ `P1 = 0x04` (`0b00000100`)
  - Step 4: Coil D energized $\implies$ `P1 = 0x08` (`0b00001000`)
- **Direction & Speed Control:**
  - Forward rotation executes sequence: Step 1 $ightarrow$ Step 2 $ightarrow$ Step 3 $ightarrow$ Step 4.
  - Reverse rotation executes sequence in opposite order: Step 4 $ightarrow$ Step 3 $ightarrow$ Step 2 $ightarrow$ Step 1.
  - Delay between step transitions (typically 5–20 ms) sets rotation speed; too short a delay causes rotor stalls due to mechanical inertia.

**INFERENCE:**
The ULN2003 Darlington array effectively amplified weak 8051 pin currents to the 200 mA level needed to energize the motor windings, while internal clamping diodes dissipated inductive coil discharge. The motor rotated with high positional accuracy and holding torque in both directions.
