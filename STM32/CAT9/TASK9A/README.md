# CAT9A – STM32 USART Character Echo & Serial Communication

**EXP:** CAT9A

**DATE:** 28/09/26

**NAME OF EXP:** STM32 UART Communication and Character Echo

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** STM32F103C8T6 (72 MHz)
- **UART Peripheral:** USART1
  - PA9 $\implies$ USART1_TX (Alternate Function Push-Pull)
  - PA10 $\implies$ USART1_RX (Input Floating)
- **Serial Parameters:** 115200 Baud, 8 Data Bits, 1 Stop Bit, No Parity (8N1)
- **Host Link:** USB-to-UART CP2102 module connected to PC serial terminal

**TASK NO:**
1. Configure USART1 on the STM32F103 at 115200 baud using STM32CubeMX HAL.
2. Transmit an initial welcome message banner to the host PC upon system reset.
3. Implement full-duplex character reception and immediate loopback echo to the terminal.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **USART1 Configuration:**
  Configured `huart1.Init.BaudRate = 115200`, `WordLength = UART_WORDLENGTH_8B`, `StopBits = UART_STOPBITS_1`, `Parity = UART_PARITY_NONE`, `Mode = UART_MODE_TX_RX`.
- **Transmission & Echo Loop:**
```c
uint8_t welcome[] = "STM32F103 USART1 Echo Initialized\r\n";
HAL_UART_Transmit(&huart1, welcome, sizeof(welcome)-1, 100);

uint8_t rx_char;
while (1) {
    if (HAL_UART_Receive(&huart1, &rx_char, 1, HAL_MAX_DELAY) == HAL_OK) {
        HAL_UART_Transmit(&huart1, &rx_char, 1, 10); // Echo character back
    }
}
```

**INFERENCE:**
High-speed asynchronous serial communication was verified at 115200 baud. The hardware Baud Rate Generator (BRG) maintained accurate bit timing against the 72 MHz APB2 peripheral clock, producing instantaneous terminal loopback with zero character corruption.
