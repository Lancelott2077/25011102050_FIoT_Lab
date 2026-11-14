# CAT3 - Tactile Switch Debouncing & 4-State LED Controller

**EXP:** CAT3

**DATE:** 27/07/26

**NAME OF EXP:** Switch Logic and Multi-State LED Pattern Controller

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52 (11.0592 MHz)
- Pushbutton: Tactile switch connected to P2.6 (Active-LOW, pull-up enabled)
- Reference Ground Pin: P2.3 driven LOW
- Output LEDs: 4 LEDs connected to Port 1 lower nibble (P1.0 - P1.3)
- Current-limiting resistors: 330 Ω on each LED

**TASK NO:**
1. Interface an active-LOW tactile pushbutton to an 8051 input pin.
2. Implement software debouncing to reject mechanical contact bounce.
3. Design a state machine that advances through 4 visual LED display modes on each button press.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Debounce Algorithm:** When P2.6 reads 0, wait 20 ms. If still 0, wait until the button is released (`while(P2.6 == 0)`), then increment the state counter.
- **State Machine Modes:**
  - **State 0 (Running LED):** Shifts a single active bit across P1.0 -> P1.1 -> P1.2 -> P1.3.
  - **State 1 (Binary Counter):** Displays a 4-bit binary count from 0 to 15.
  - **State 2 (Alternating Pattern):** Toggles between odd and even LEDs (0x05 <-> 0x0A).
  - **State 3 (All Flash):** Simultaneously flashes all 4 LEDs ON and OFF (0x0F <-> 0x00).

**INFERENCE:**
Mechanical contact bounce was successfully filtered using a 20 ms software delay and release detection. The state machine cycled reliably between the 4 patterns with exactly one mode change per physical press.
