# CAT10B: ESP8266 AT Command Protocol Negotiation & Handshake

## 🎯 Objective
Implement an automated handshake supervisor on STM32 that issues AT commands to the ESP8266 modem, parses response delimiters (`OK`, `ERROR`), and extracts firmware telemetry.

## ⚡ Hardware Architecture & Pinout
- **Master:** STM32F103C8T6 (USART2 at 115200 Baud)
- **Slave:** ESP8266 Wemos D1 Mini running official Espressif Non-OS AT firmware.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Modem Probe Command Sequence:**
   - `AT\r\n`: Basic connection alive check $\implies$ Expects `OK`.
   - `AT+GMR\r\n`: Queries AT version and SDK build information.
   - `AT+RST\r\n`: Executes software reboot and synchronizes state machine.
2. **Response Parser Engine:** Implements timeout-bounded string matching to detect `OK` responses and gracefully catch modem fault states.

## 📊 Verification & Results
- Verified automated modem initialization and firmware version extraction over UART bus.
