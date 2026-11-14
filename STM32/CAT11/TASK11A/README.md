# CAT11A – ESP8266 Embedded TCP/HTTP Server

**EXP:** CAT11A

**DATE:** 14/10/26

**NAME OF EXP:** Configure ESP8266 TCP Server & Static HTTP Response

**HARDWARE SETUP / PLATFORM:**
- Host MCU: STM32F103C8T6
- Wi-Fi Server: ESP8266 Wemos D1 Mini (Port 80)
- Client: Web browser / HTTP client on the same local network

**TASK NO:**
1. Enable multi-connection socket multiplexing on ESP8266 (`AT+CIPMUX=1`).
2. Start an internal TCP server listening on Port 80 (`AT+CIPSERVER=1,80`).
3. Intercept incoming `GET /` requests and return an HTTP 200 OK HTML response page.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- Server startup commands: `AT+CIPMUX=1` followed by `AT+CIPSERVER=1,80`.
- When a client connects, the ESP8266 emits `+IPD,<link_id>,<len>:GET / HTTP/1.1`.
- STM32 prepares the response payload:
  ```html
  HTTP/1.1 200 OK
Content-Type: text/html


  <h1>STM32 + ESP8266 IoT Web Server</h1><p>System Status: Active</p>
  ```
- Send data using `AT+CIPSEND=<link_id>,<length>` followed by payload, then close socket with `AT+CIPCLOSE=<link_id>`.

**INFERENCE:**
The STM32 and ESP8266 operated as a lightweight standalone web server. Typing the ESP8266 IP address in a computer browser rendered the status webpage correctly.
