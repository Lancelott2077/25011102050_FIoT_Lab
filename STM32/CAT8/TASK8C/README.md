# CAT8C: STM32 Temporal Press Classifier (Short vs. Long Press)

## 🎯 Objective
Implement time-domain classification on a single pushbutton to distinguish between a transient tap (Short Press, < 1s) and sustained hold (Long Press, > 1s) to trigger distinct operational modes.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F103C8T6
- **Input:** Pushbutton with pull-up resistor.
- **Outputs:** System indicator LEDs / Serial debug output.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **SysTick Timestamping:** On falling edge, records start time $t_{\text{press}} = \text{HAL\_GetTick()}$.
2. **Duration Calculation:** On rising edge, calculates $\Delta t = t_{\text{release}} - t_{\text{press}}$.
3. **Classification Tree:**
   - $\Delta t < 1000 \text{ ms}$: Short Press $\implies$ Toggle primary LED mode.
   - $\Delta t \ge 1000 \text{ ms}$: Long Press $\implies$ Enter continuous strobe alert mode.

## 📊 Verification & Results
- Distinct visual responses reliably triggered based on user press duration.
