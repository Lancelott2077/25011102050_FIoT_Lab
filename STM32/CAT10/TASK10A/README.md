# CAT10A – STM32 to Wemos D1 (ESP8266) UART Bridge

**EXP:** CAT10A

**DATE:** 05/10/26

**NAME OF EXP:** Establish STM32 ↔ Wemos ESP8266 UART Communication

**HARDWARE SETUP / PLATFORM:**
- **Host Controller:** STM32F103C8T6
- **Wi-Fi Co-Processor:** Wemos D1 Mini (ESP8266EX SoC)
- **Hardware Interconnect:**
  - STM32 PA2 (USART2_TX) $\implies$ Wemos RXD (GPIO3)
  - STM32 PA3 (USART2_RX) $\implies$ Wemos TXD (GPIO1)
  - Common Ground: STM32 GND connected to Wemos GND
- **PC Debug Console:** STM32 USART1 (PA9/PA10) at 115200 Baud

**TASK NO:**
1. Wire a dedicated hardware UART bus between the STM32F103 (USART2) and the ESP8266 (UART0).
2. Confirm 3.3V logic level compatibility and baud rate synchronization (115200 Baud).
3. Develop firmware creating a transparent bidirectional bridge relaying bytes between PC console and ESP8266 modem.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Both microcontrollers operate natively at 3.3 V I/O levels, allowing direct pin-to-pin wiring without level-shifting circuitry.
- Bridge Loop:
  - When a byte is received on USART1 (PC input), transmit it immediately to USART2 (ESP8266).
  - When a byte is received on USART2 (ESP8266 response), transmit it immediately to USART1 (PC terminal).

**INFERENCE:**
A transparent bidirectional dual-MCU communications link was established. Operating at 115200 baud, commands entered from the PC terminal reached the ESP8266 Wi-Fi modem and responses were displayed back with zero framing errors.
