# CAT11B – Node-RED HTTP Client Integration

**EXP:** CAT11B

**DATE:** 14/10/26

**NAME OF EXP:** Node-RED as HTTP Client of STM32/ESP8266 Server

**HARDWARE SETUP / PLATFORM:**
- Edge Node: STM32F103 + ESP8266 Web Server
- Dashboard Host: PC running Node-RED runtime

**TASK NO:**
1. Format sensor/status telemetry on the STM32 as a JSON string payload.
2. Configure a Node-RED flow to poll the STM32 HTTP server periodically.
3. Parse the received JSON and display live gauges and status cards on a web dashboard.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- STM32 responds to HTTP GET requests with JSON:
  `{"status":"OK","uptime":245,"led":1}`
- Node-RED Flow:
  - **Inject Node:** Sends a trigger event every 2 seconds.
  - **HTTP Request Node:** Issues `GET http://<ESP_IP>/api/data`.
  - **JSON Node:** Parses the response string into a JavaScript object.
  - **Dashboard Gauge / Text Nodes:** Binds object fields to visual widgets.

**INFERENCE:**
Integration between the embedded microcontroller server and an external Node-RED dashboard was verified over HTTP. Telemetry was retrieved and visualized in real time.
