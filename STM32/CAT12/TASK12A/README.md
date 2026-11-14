# CAT12A – Nucleo-F401RE On-Board LED Bring-Up

**EXP:** CAT12A

**DATE:** 23/10/26

**NAME OF EXP:** On-Board LED Bring-Up (NUCLEO-F401RE)

**HARDWARE SETUP / PLATFORM:**
- Board: STMicroelectronics NUCLEO-F401RE
- Microcontroller: STM32F401RET6 (ARM Cortex-M4 with FPU, 84 MHz)
- Target Pin: PA5 connected to on-board green LED (LD2)
- Framework: STM32Cube HAL

**TASK NO:**
1. Configure the STM32F401RE clock tree for 84 MHz operation.
2. Initialize pin PA5 as a push-pull output.
3. Toggle green LED LD2 at a 1 Hz rate in the main loop.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Clock setup: High-Speed Internal (HSI) 16 MHz clock multiplied via PLL to 84 MHz.
- GPIO Init:
  ```c
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  ```
- Application loop calls `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5)` with `HAL_Delay(500)`.

**INFERENCE:**
The Cortex-M4 Nucleo-64 board was brought up successfully. The user green LED LD2 toggled steadily at 1.0 Hz.
