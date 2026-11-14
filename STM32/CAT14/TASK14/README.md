# CAT14 – BME280 Sensor Interfacing with MQTT Telemetry

**EXP:** CAT14

**DATE:** 2/11/26

**NAME OF EXP:** Sensor Interfacing (BME280) – MQTT – Node-RED Analytics

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: STM32F401RE Nucleo-64
- Sensor: Bosch BME280 (I2C1 on PB8/PB9)
- Wi-Fi Modem: ESP8266 Wemos D1 Mini running MQTT client
- MQTT Broker: Eclipse Mosquitto / Local Broker on Port 1883
- Dashboard: Node-RED MQTT Subscriber Nodes

**TASK NO:**
1. Establish an MQTT connection from the embedded gateway to the MQTT broker.
2. Sample calibrated temperature, humidity, and pressure from the BME280 sensor.
3. Publish telemetry data under the topic `fiot/25011102050/bme280` and subscribe via Node-RED for real-time visualization.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **MQTT Connection:** Client ID `STM32F4_Client_25011102050` connects to broker on port 1883 with keepalive of 60 seconds.
- **Telemetry Assembly:**
  ```json
  {
    "device": "25011102050_NUCLEO",
    "temperature": 26.15,
    "humidity": 59.30,
    "pressure": 1011.85,
    "timestamp": 84520
  }
  ```
- **Pub/Sub Flow:** Dispatches MQTT `PUBLISH` packets. Node-RED subscribes to `fiot/25011102050/bme280` and routes data to dashboard gauges.

**INFERENCE:**
The publish/subscribe MQTT architecture provided lower network overhead and latency compared to HTTP polling. Environmental telemetry was broadcast to multiple dashboard subscribers simultaneously without packet loss.
