# CAT12C: Nucleo SysTick Short vs. Long Press Detection

## 🎯 Objective
Develop a non-blocking button duration classifier on the Nucleo-F401RE using `HAL_GetTick()` to execute distinct operational modes on user button B1 short-press vs. long-press.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F401RET6
- **Input:** User Button `B1` (`PC13`).
- **Indicator:** Green LED `LD2` (`PA5`).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Temporal Capture:**
   - Falling edge captures start time: `press_start = HAL_GetTick()`.
   - Rising edge captures end time: `duration = HAL_GetTick() - press_start`.
2. **Mode Dispatcher:**
   - **Short Press (< 1000 ms):** Toggles LED state once (Standard Latch Mode).
   - **Long Press (≥ 1000 ms):** Initiates a rapid 10 Hz strobe alarm sequence for 3 seconds before restoring idle state.

## 📊 Verification & Results
- Instantaneous and accurate discrimination between momentary taps and sustained holds.
