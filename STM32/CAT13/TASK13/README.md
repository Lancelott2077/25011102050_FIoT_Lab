# CAT13 – BME280 Environmental Sensor & HTTP Telemetry

**EXP:** CAT13

**DATE:** 27/10/26

**NAME OF EXP:** Sensor Interfacing (BME280) – STM32 Debug – ESP8266 Wi-Fi HTTP – Node-RED Analytics

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: STM32F401RE Nucleo-64
- Environmental Sensor: Bosch BME280 (I2C address: 0x76)
  - PB8 -> I2C1_SCL
  - PB9 -> I2C1_SDA
- Wi-Fi Gateway: ESP8266 Wemos D1 connected to STM32 USART1 (PA9/PA10)
- Analytics Platform: Node-RED dashboard on local host

**TASK NO:**
1. Interface the BME280 sensor to STM32 via I2C and read factory trimming calibration coefficients.
2. Measure uncompensated temperature, humidity, and barometric pressure, then calculate compensated floating-point values.
3. Transmit formatted JSON telemetry over Wi-Fi via HTTP POST requests to a Node-RED flow dashboard.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **I2C Sensor Driver:** Reads compensation registers from `0x88` to `0xA1` and `0xE1` to `0xF0`.
- **Compensation Formulas:** Executes Bosch integer compensation equations to obtain accurate °C, %RH, and hPa values.
- **HTTP Payload Streaming:** Formats JSON string `{"temp": 25.4, "hum": 62.1, "press": 1013.2}` and uses ESP8266 AT commands to issue HTTP POST requests to the Node-RED endpoint.

**INFERENCE:**
The entire sensor-to-dashboard IoT pipeline was validated. Real-time ambient temperature, humidity, and atmospheric pressure were acquired via I2C, transmitted wirelessly, and plotted on Node-RED live graphs.
