# CAT8B – STM32 Event-Based Switch Debouncing

**EXP:** CAT8B

**DATE:** 18/09/26

**NAME OF EXP:** STM32 Event-Based Control - Pushbutton Debouncing & State Latch

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** STM32F103C8T6 (72 MHz)
- **Input Switch:** Normally-open tactile pushbutton connected to GPIO input pin with internal pull-up (`GPIO_PULLUP`)
- **Output:** On-board status LED on PC13
- **Framework:** STM32 HAL

**TASK NO:**
1. Configure a digital GPIO pin as an input with internal pull-up to read tactile button states.
2. Implement software debouncing to reject contact bounce electrical noise upon button depression.
3. Maintain a persistent state memory latch that toggles the LED output state on each valid button press.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Debounce Logic:**
  1. Sample input pin: Check if pin state is active-LOW (`GPIO_PIN_RESET`).
  2. Non-blocking filter delay: Wait 20 ms using `HAL_Delay(20)` to pass contact bounce duration.
  3. Re-sample pin: If pin remains LOW, confirm valid intentional press event.
  4. State Toggle: Invert the output LED state latch.
  5. Release Barrier: Wait in a release loop (`while(HAL_GPIO_ReadPin() == GPIO_PIN_RESET)`) so holding the button does not trigger rapid unintended toggling.

**INFERENCE:**
Mechanical switches exhibit contact bounce lasting 5–15 ms after contact closure. Implementing a 20 ms confirmation window and a release barrier eliminated false edge triggers, ensuring exactly one state change per physical press.
