# CAT8A – STM32 GPIO Output Bring-Up

**EXP:** CAT8A

**DATE:** 18/09/26

**NAME OF EXP:** STM32 GPIO Input / Output - On-Board LED Bring-Up

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: STM32F103C8T6 (ARM Cortex-M3, 72 MHz)
- Board: STM32 Blue Pill development board
- Output Pin: PC13 connected to on-board LED (Active-LOW circuit)
- IDE / Framework: STM32CubeMX and Keil MDK-ARM (STM32 HAL)

**TASK NO:**
1. Generate an initial STM32CubeMX project for the STM32F103C8Tx MCU.
2. Configure pin PC13 as a GPIO push-pull output.
3. Toggle the LED inside the main loop at a 1 Hz rate using `HAL_GPIO_TogglePin` and `HAL_Delay`.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Clock Configuration: 72 MHz SYSCLK using external 8 MHz crystal and PLL.
- GPIO Init:
  ```c
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  ```
- Application Loop:
  ```c
  while (1) {
      HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
      HAL_Delay(500); // 500ms ON / 500ms OFF
  }
  ```

**INFERENCE:**
The STM32 HAL toolchain and CubeMX pin initialization were validated on the Blue Pill board. The active-LOW on-board LED toggled cleanly at exactly 1 Hz.
