# CAT10B – ESP8266 AT Command Protocol Handshake

**EXP:** CAT10B

**DATE:** 05/10/26

**NAME OF EXP:** Explore ESP8266 AT Command Interface

**HARDWARE SETUP / PLATFORM:**
- Host MCU: STM32F103C8T6 (USART2 at 115200 Baud)
- Wi-Fi Modem: ESP8266 Wemos D1 Mini running official AT firmware

**TASK NO:**
1. Dispatch basic AT test commands from the STM32 to the ESP8266.
2. Query firmware and SDK version using `AT+GMR`.
3. Verify modem responses (`OK`, `ready`) to establish a known baseline state.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Sends `AT
` and waits for `OK`.
- Sends `AT+GMR
` to read core version and AT interpreter version.
- Sends `AT+RST
` to restart modem and synchronizes with the `ready` response string.

**INFERENCE:**
The ESP8266 modem responded properly to standard AT commands. The firmware version was identified and verified over the inter-processor UART link.
