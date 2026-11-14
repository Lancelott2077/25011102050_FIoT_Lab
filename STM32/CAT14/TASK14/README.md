# CAT14 – BME280 Sensor Interfacing with MQTT Telemetry

**EXP:** CAT14

**DATE:** 2/11/26

**NAME OF EXP:** Sensor Interfacing (BME280) – MQTT – Node-RED Analytics

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** STM32F401RE Nucleo-64 (84 MHz)
- **Sensor:** Bosch BME280 (I2C1 on PB8 SCL, PB9 SDA)
- **Wireless Modem:** ESP8266 Wemos D1 Mini running MQTT client firmware
- **MQTT Broker:** Eclipse Mosquitto running on Port 1883
- **Subscriber Dashboard:** Node-RED MQTT in-nodes connected to dashboard gauges

**TASK NO:**
1. Configure an MQTT client connection from the embedded gateway to the Mosquitto broker.
2. Acquire calibrated temperature, humidity, and pressure readings from the BME280 sensor.
3. Publish telemetry payloads under topic `fiot/25011102050/bme280` and visualize data streams in Node-RED.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **MQTT Protocol Integration:**
  - Client ID: `STM32F4_25011102050`
  - Broker Port: 1883, KeepAlive: 60 seconds
  - Topic: `fiot/25011102050/bme280`
- **Telemetry Payload Structure:**
  ```json
  {
    "device_id": "25011102050_NUCLEO_F401RE",
    "temperature": 26.42,
    "humidity": 58.15,
    "pressure": 1012.30,
    "uptime_ms": 128450
  }
  ```
- **Pub/Sub Advantages:**
  Unlike HTTP polling, MQTT publish/subscribe provides asynchronous, low-overhead binary framing. Telemetry messages are published only upon state change or scheduled telemetry intervals, reducing Wi-Fi radio airtime and power consumption.

**INFERENCE:**
The MQTT publish/subscribe architecture demonstrated significantly lower network overhead and latency compared to HTTP. Environmental sensor data published by the STM32 was instantly received by Node-RED subscribers and displayed on real-time gauges.
