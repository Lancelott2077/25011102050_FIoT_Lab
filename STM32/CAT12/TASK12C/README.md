# CAT12C – Nucleo Short-Press and Long-Press Detection

**EXP:** CAT12C

**DATE:** 23/10/26

**NAME OF EXP:** Short-Press and Long-Press Detection (NUCLEO-F401RE)

**HARDWARE SETUP / PLATFORM:**
- Board: NUCLEO-F401RE (Cortex-M4, 84 MHz)
- Input: User Button B1 (PC13)
- Indicator: Green LED LD2 (PA5)

**TASK NO:**
1. Use the SysTick timer (`HAL_GetTick()`) to measure the exact duration of a button press on PC13.
2. Classify the press into Short Press (< 1 second) or Long Press (≥ 1 second).
3. Trigger a simple LED toggle on short press, and a rapid flashing alert pattern on long press.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- On button press detected: record `t_start = HAL_GetTick()`.
- Wait for button release: record `t_end = HAL_GetTick()`.
- Duration `diff = t_end - t_start`:
  - `diff < 1000`: Short Press $\implies$ Toggles LED LD2 once.
  - `diff >= 1000`: Long Press $\implies$ Executes a rapid 10-blink alarm burst.

**INFERENCE:**
Accurate time-domain classification was achieved on a single user button. Short taps and sustained holds reliably triggered separate operational functions.
