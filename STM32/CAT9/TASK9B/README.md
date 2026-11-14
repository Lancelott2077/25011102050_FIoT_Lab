# CAT9B: STM32 USART Command Parser ("ON" / "OFF" / "TOGGLE")

## 🎯 Objective
Build a serial command-line interpreter (CLI) on STM32 USART1 that buffers incoming ASCII strings, parses command keywords, and controls hardware actuators with descriptive status acknowledgments.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F103C8T6
- **Serial Bus:** USART1 (`PA9` TX, `PA10` RX) at 115200 Baud.
- **Actuator:** On-board user LED (`PC13`).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Line Buffering:** Characters accumulate into `rx_buffer[]` until a carriage return (`\r` or `\n`) arrives.
2. **String Tokenizer & Lexer:**
   - Strips whitespace and compares against command dictionary (`strcmp`):
     - `"ON"` $\implies$ `HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET)` (LED ON)
     - `"OFF"` $\implies$ `HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET)` (LED OFF)
     - `"TOGGLE"` $\implies$ `HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13)`
   - Unrecognized strings respond with `"ERR: Unknown Command\r\n"`.
3. **Buffer Management:** Buffer resets index and null-terminates safely to prevent overflow vulnerabilities.

## 📊 Verification & Results
- Commands typed into serial terminal execute immediately with descriptive confirmation responses.
