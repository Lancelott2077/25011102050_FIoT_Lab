# CAT10A: STM32 to Wemos D1 (ESP8266) UART Interconnect

## 🎯 Objective
Establish a reliable inter-processor communication channel between an STM32F103 host controller and an ESP8266 Wemos D1 Mini Wi-Fi SoC across a dedicated hardware UART bus.

## ⚡ Hardware Architecture & Pinout
- **Master MCU:** STM32F103C8T6
- **Wi-Fi Co-Processor:** Wemos D1 Mini (ESP8266EX)
- **Bus Interconnect:**
  - STM32 `PA2` (USART2_TX) $\longrightarrow$ Wemos `RXD` (GPIO3)
  - STM32 `PA3` (USART2_RX) $\longleftarrow$ Wemos `TXD` (GPIO1)
  - Common Ground (`GND` ↔ `GND`)

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Electrical Compatibility:** Both STM32F103 and ESP8266 operate natively on 3.3V logic, allowing direct signal routing without bidirectional level shifters.
2. **Dual Serial Architecture:** STM32 USART1 serves as user debug console to PC, while USART2 acts as an internal machine-to-machine bridge to ESP8266.
3. **Bridge Firmware:** Relays bytes received on USART1 to USART2 and vice versa, verifying transparent channel pass-through.

## 📊 Verification & Results
- Bi-directional character pass-through verified between host PC, STM32, and ESP8266 at 115200 Baud.
