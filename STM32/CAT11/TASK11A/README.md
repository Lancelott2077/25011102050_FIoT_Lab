# CAT11A – ESP8266 Embedded TCP/HTTP Server

**EXP:** CAT11A

**DATE:** 14/10/26

**NAME OF EXP:** Configure ESP8266 TCP Server & Static HTTP Response

**HARDWARE SETUP / PLATFORM:**
- **Host MCU:** STM32F103C8T6
- **Wi-Fi Gateway:** ESP8266 Wemos D1 Mini connected to local Wi-Fi network
- **Network Protocol:** TCP/IP on Port 80 (HTTP)
- **Client:** Web browser running on PC / smartphone on the same subnet

**TASK NO:**
1. Configure multi-connection socket multiplexing on the ESP8266 (`AT+CIPMUX=1`).
2. Launch a TCP server listening on port 80 (`AT+CIPSERVER=1,80`).
3. Parse incoming HTTP `GET /` requests and serve a static HTML response page with HTTP 200 OK headers.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Server Startup Sequence:**
  `AT+CIPMUX=1` $ightarrow$ `AT+CIPSERVER=1,80`.
- **Request Trapping:**
  When a browser connects, the modem outputs: `+IPD,<channel_id>,<len>:GET / HTTP/1.1...`
- **Response Transmission:**
  1. Prepare response body:
     ```html
     HTTP/1.1 200 OK
Content-Type: text/html
Connection: close


     <html><body><h1>STM32 + ESP8266 Embedded Server</h1><p>Node Status: OK</p></body></html>
     ```
  2. Issue `AT+CIPSEND=<channel_id>,<byte_count>`.
  3. When the modem responds with `>`, send the HTML payload.
  4. Terminate connection with `AT+CIPCLOSE=<channel_id>`.

**INFERENCE:**
The combined STM32 and ESP8266 system functioned as an embedded HTTP web server. Client web browsers on the local network navigated to the ESP8266 IP address and rendered the served HTML status page.
