# CAT11B – Node-RED HTTP Client Integration

**EXP:** CAT11B

**DATE:** 14/10/26

**NAME OF EXP:** Node-RED as HTTP Client of STM32/ESP8266 Server

**HARDWARE SETUP / PLATFORM:**
- **Embedded Node:** STM32F103 + ESP8266 HTTP Server (IP: `192.168.x.x`, Port 80)
- **Analytics Host:** PC running Node-RED flow engine and Node-RED Dashboard UI

**TASK NO:**
1. Program the STM32 web server to serve telemetry formatted as a JSON string object.
2. Build a Node-RED flow that polls the embedded server endpoint at a periodic interval.
3. Parse the JSON response in Node-RED and plot live telemetry on digital dashboard gauges and trend charts.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **JSON Telemetry Payload:**
  ```json
  {
    "device_id": "STM32F103_25011102050",
    "uptime_sec": 412,
    "led_status": 1,
    "system_state": "ACTIVE"
  }
  ```
- **Node-RED Flow Architecture:**
  - **Inject Node:** Recurring timer trigger configured for 2-second intervals.
  - **HTTP Request Node:** Configured for method `GET` targeting `http://<ESP_IP>/status`.
  - **JSON Parser Node:** Converts incoming string into JavaScript object properties (`msg.payload`).
  - **UI Chart & Gauge Nodes:** Displays `msg.payload.uptime_sec` and `msg.payload.led_status` visually.

**INFERENCE:**
RESTful HTTP polling between an IoT edge server and an external Node-RED dashboard was verified. Data acquired by the STM32 was successfully serialized into JSON and visualized on a web dashboard in real time.
