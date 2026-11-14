# CAT8A: STM32F103 GPIO Output Bring-Up

## 🎯 Objective
Configure an ARM Cortex-M3 microcontroller GPIO pin in push-pull output mode using the STM32Cube HAL framework and implement deterministic LED toggling.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F103C8T6 (ARM Cortex-M3, 72 MHz)
- **Target Pin:** `PC13` connected to on-board LED (Active-LOW circuit).
- **Clock Configuration:** Internal HSI / HSE with PLL generating 72 MHz SYSCLK.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Peripheral Clock Enabling:** Asserts clock gate for GPIOC via `__HAL_RCC_GPIOC_CLK_ENABLE()`.
2. **Pin Initialization:** Configures `GPIO_PIN_13` with `GPIO_MODE_OUTPUT_PP`, `GPIO_NOPULL`, and `GPIO_SPEED_FREQ_LOW`.
3. **HAL Toggle Execution:** `HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13)` toggles the pin state, followed by `HAL_Delay(500)` SysTick millisecond delay.

## 📊 Verification & Results
- Measured 1.0 Hz square wave on oscilloscope at PC13.
- On-board LED alternates state every 500 ms cleanly.
