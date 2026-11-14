# CAT10C – Wemos ESP8266 Wi-Fi Station Association

**EXP:** CAT10C

**DATE:** 05/10/26

**NAME OF EXP:** Connect Wemos ESP8266 to Wi-Fi Network

**HARDWARE SETUP / PLATFORM:**
- **Host MCU:** STM32F103C8T6
- **Wi-Fi Module:** ESP8266 Wemos D1 Mini
- **Network Environment:** 2.4 GHz IEEE 802.11 b/g/n Access Point with WPA2-PSK security

**TASK NO:**
1. Put the ESP8266 into Wi-Fi Station (STA) client mode using `AT+CWMODE=1`.
2. Connect to a local Wi-Fi network using credentials dispatched via `AT+CWJAP`.
3. Query and display the assigned station IP address and MAC address using `AT+CIFSR`.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Execution Steps:
  1. Set Mode: `AT+CWMODE=1
` enforces Station-only mode, disabling SoftAP to conserve power.
  2. Join AP: `AT+CWJAP="SSID","PASSWORD"
` initiates association and 4-way WPA2 handshake.
  3. Monitor events: Look for `WIFI CONNECTED` followed by `WIFI GOT IP` and final `OK`.
  4. Query Network Parameters: `AT+CIFSR
` retrieves assigned station IP (e.g. `192.168.1.x`) and MAC address.

**INFERENCE:**
The ESP8266 successfully associated with the wireless local area network and obtained a valid dynamic IPv4 lease via DHCP. The STM32 host confirmed network connectivity by parsing modem status responses.
