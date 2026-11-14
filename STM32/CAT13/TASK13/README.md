# CAT13: BME280 Environmental Sensor & HTTP Telemetry Stream

## 🎯 Objective
Interface a high-precision Bosch BME280 environmental sensor via I2C to the STM32F401RE, compute calibrated temperature, humidity, and barometric pressure, and stream data over Wi-Fi to a Node-RED dashboard via HTTP POST.

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F401RET6 Nucleo-64
- **Sensor:** Bosch BME280 Multi-Sensor (I2C address: `0x76` / `0x77`).
  - `PB8` $\implies$ I2C1_SCL
  - `PB9` $\implies$ I2C1_SDA
- **Wi-Fi Bridge:** ESP8266 on USART1 (`PA9` TX, `PA10` RX).
- **Dashboard:** Node-RED HTTP Receiver & Visual Gauge UI.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Sensor Calibration Mathematics:**
   Reads factory trimming parameters from BME280 NVM registers (`0x88`–`0xA1`, `0xE1`–`0xF0`) and executes Bosch 32-bit compensation formulas for true floating-point measurements.
2. **I2C HAL Driver:** Uses `HAL_I2C_Mem_Read()` and `HAL_I2C_Mem_Write()` to configure forced measurement mode with 16x oversampling.
3. **HTTP Client Pipe:** Serializes environmental readings into a structured JSON payload and commands the ESP8266 via AT commands to perform an HTTP POST request to the Node-RED endpoint.

## 📊 Verification & Results
- Accurate temperature (±0.5°C), humidity (±3% RH), and atmospheric pressure (±1 hPa) plotted live on Node-RED charts.
