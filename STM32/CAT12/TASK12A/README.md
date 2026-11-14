# CAT12A: Nucleo-F401RE Board Bring-Up & On-Board LED

## 🎯 Objective
Bring up the high-performance STMicroelectronics NUCLEO-F401RE development board (ARM Cortex-M4 with FPU) and drive the on-board green user LED (LD2) at 1 Hz.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F401RET6 (ARM Cortex-M4 @ 84 MHz, 512 KB Flash, 96 KB SRAM)
- **LED:** On-board Green LED `LD2` connected to `PA5`.
- **Debugger:** On-board ST-LINK/V2-1 with Virtual COM Port (VCP).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Clock Tree Configuration:** Configures Phase-Locked Loop (PLL) from 16 MHz internal HSI clock to achieve peak 84 MHz core CPU frequency with 2 wait states for Flash.
2. **GPIO Driver Configuration:** Initialized `PA5` with `GPIO_MODE_OUTPUT_PP`, `GPIO_NOPULL`, and `GPIO_SPEED_FREQ_LOW`.
3. **Execution Loop:** Calls `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5)` inside the main application loop spaced by 500 ms delays.

## 📊 Verification & Results
- Verified 84 MHz core frequency and precise 1 Hz flashing on green LED LD2.
