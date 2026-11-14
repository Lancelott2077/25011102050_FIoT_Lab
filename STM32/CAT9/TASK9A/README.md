# CAT9A – STM32 USART Character Echo & Serial Communication

**EXP:** CAT9A

**DATE:** 28/09/26

**NAME OF EXP:** STM32 UART Communication and Character Echo

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: STM32F103C8T6 (72 MHz)
- UART Peripheral: USART1 (PA9 = TX, PA10 = RX)
- Serial Settings: 115200 Baud, 8 Data Bits, 1 Stop Bit, No Parity (8N1)
- Host Link: USB-UART converter connected to PC

**TASK NO:**
1. Configure USART1 on the STM32F103 using STM32CubeMX HAL.
2. Transmit an initial welcome banner to the host PC terminal.
3. Receive incoming characters from the terminal and immediately echo them back.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Initialized `huart1` at 115200 baud with word length 8 bits.
- Welcome message sent via `HAL_UART_Transmit(&huart1, msg, len, 100)`.
- Interactive Echo Loop:
  ```c
  uint8_t rx_byte;
  while(1) {
      if (HAL_UART_Receive(&huart1, &rx_byte, 1, HAL_MAX_DELAY) == HAL_OK) {
          HAL_UART_Transmit(&huart1, &rx_byte, 1, 10); // Echo character back
      }
  }
  ```

**INFERENCE:**
Full-duplex serial communication was established at 115200 baud. Characters typed in the PC terminal appeared back on screen with zero observable latency or frame errors.
