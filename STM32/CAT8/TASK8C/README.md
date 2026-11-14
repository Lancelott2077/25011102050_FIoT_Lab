# CAT8C – STM32 Short Press vs. Long Press Classification

**EXP:** CAT8C

**DATE:** 18/09/26

**NAME OF EXP:** STM32 Temporal Button Press Classification (Short vs. Long Press)

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: STM32F103C8T6 (Blue Pill)
- Input: Normally-open tactile button with pull-up
- Output: LED indicator on PC13

**TASK NO:**
1. Measure the duration of a button press using `HAL_GetTick()`.
2. Classify the press as either a Short Press (< 1000 ms) or Long Press (≥ 1000 ms).
3. Execute different LED actions depending on the classified press duration.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Detect falling edge when the button is pressed and record $t_{	ext{start}} = 	ext{HAL\_GetTick()}$.
- Wait until button is released, then record $t_{	ext{stop}} = 	ext{HAL\_GetTick()}$.
- Calculate duration $\Delta t = t_{	ext{stop}} - t_{	ext{start}}$:
  - If $\Delta t < 1000 	ext{ ms}$: Short Press $\implies$ Toggle LED once.
  - If $\Delta t \ge 1000 	ext{ ms}$: Long Press $\implies$ Trigger a 5-blink rapid burst.

**INFERENCE:**
Using SysTick timestamps allowed reliable differentiation between a momentary click and a sustained hold on a single button, doubling its functional utility.
