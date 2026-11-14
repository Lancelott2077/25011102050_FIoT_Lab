# CAT8B: STM32 Event-Driven GPIO Debouncing & State Latch

## 🎯 Objective
Design a reliable digital input filter that eliminates mechanical contact bounce from an external switch and toggles an actuator state upon valid falling-edge press events.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F103C8T6
- **Input:** Tactile pushbutton on GPIO input pin configured with internal pull-up (`GPIO_PULLUP`).
- **Output:** `PC13` LED indicator.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Switch Contact Dynamics:** Mechanical switch closure produces 5–15 ms of transient electrical noise.
2. **Debounce Logic:**
   - Detects active-LOW transition (`HAL_GPIO_ReadPin() == GPIO_PIN_RESET`).
   - Introduces a non-blocking confirmation window (20 ms).
   - Re-evaluates pin state; if confirmed valid, inverts output latch register.
   - Waits for full contact release to avoid repeated triggers.

## 📊 Verification & Results
- 100% reliable single-toggle operation per manual button press; zero bounce artifacts.
