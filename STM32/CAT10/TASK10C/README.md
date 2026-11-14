# CAT10C – Wemos ESP8266 Wi-Fi Station Association

**EXP:** CAT10C

**DATE:** 05/10/26

**NAME OF EXP:** Connect Wemos ESP8266 to Wi-Fi Network

**HARDWARE SETUP / PLATFORM:**
- Host MCU: STM32F103C8T6
- Wi-Fi Modem: ESP8266 Wemos D1 Mini
- Network: 2.4 GHz 802.11 b/g/n Wi-Fi Access Point (WPA2-PSK)

**TASK NO:**
1. Configure ESP8266 in Wi-Fi Station mode (`AT+CWMODE=1`).
2. Join a local Wi-Fi network using `AT+CWJAP="SSID","PASSWORD"`.
3. Query assigned IP address and MAC address with `AT+CIFSR`.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Command `AT+CWMODE=1
` sets client station mode.
- Command `AT+CWJAP="SSID","PASS"
` connects to the access point.
- STM32 monitors response stream for `WIFI CONNECTED` and `WIFI GOT IP`.
- Command `AT+CIFSR
` fetches the assigned station IP address for display on the debug terminal.

**INFERENCE:**
The ESP8266 successfully authenticated and associated with the local Wi-Fi router, obtaining a valid DHCP IP address.
