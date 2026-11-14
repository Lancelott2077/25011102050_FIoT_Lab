# Foundations of IoT (FIoT) Lab Portfolio

**Student Roll Number:** `25011102050`  
**Repository:** [https://github.com/Lancelott2077/25011102050_FIoT_Lab](https://github.com/Lancelott2077/25011102050_FIoT_Lab)  
**Hardware Platforms:** 8051 (AT89S52) & STM32 (ARM Cortex-M3 / Cortex-M4)

---

## 📌 Laboratory Schedule & Experiment Index

| Category | Lab Identifier | Experiment Title | Date | Hardware / Peripherals |
|:---|:---|:---|:---:|:---|
| **8051** | **CAT1** | 8051 Architecture & Toolchain Setup | 13/07/26 | AT89S52, Keil µVision C51 |
| | **CAT2** | Bare-Metal LED Blink & Delay Function | 20/07/26 | AT89S52, LED, P1.0 |
| | **CAT3** | Tactile Switch Debounce & 4-State LED Machine | 27/07/26 | AT89S52, Tactile Button, 4 LEDs |
| | **CAT4** | 4x3 Keypad Scanning & 7-Segment Display | 03/08/26 | AT89S52, 4x3 Keypad, 7-Segment |
| | **CAT5A** | Hardware Timer0 1s Interrupt Blink & IDLE Sleep | 10/08/26 | AT89S52, Timer0 Mode 1, LED |
| | **CAT5B.1**| Software PWM Breathing LED | 10/08/26 | AT89S52, Timer0 (~100µs ISR), LED |
| | **CAT5B.2**| Software PWM DC Motor Speed Control | 10/08/26 | AT89S52, L293D / Transistor, DC Motor |
| | **CAT5B.3**| PWM Servo Angular Sweep | 10/08/26 | AT89S52, 50 Hz PWM, SG90 Servo |
| | **CAT5C** | 4-Phase Stepper Motor Control | 10/08/26 | AT89S52, ULN2003, 28BYJ-48 Stepper |
| | **CAT6A** | Interrupt-Driven UART Serial Transmission | 17/08/26 | AT89S52, 9600 Baud 8N1, Serial ISR |
| | **CAT6B** | Full-Duplex UART Transceiver & Echo | 17/08/26 | AT89S52, TX/RX Interrupt Loopback |
| | **CAT7A** | 16x2 LCD 4-bit Mode & Keypad Navigation | 24/08/26 | AT89S52, HD44780 LCD, 4x3 Keypad |
| | **CAT7B** | 16x2 LCD Multi-Line Text Formatting | 24/08/26 | AT89S52, HD44780, Modular Driver |
| | **CAT7C** | Real-Time UART to 16x2 LCD Display Bridge | 24/08/26 | AT89S52, 9600 Baud UART, LCD |
| **STM32** | **CAT8A** | STM32 GPIO Output Bring-Up | 18/09/26 | STM32F103 (Blue Pill), PC13 LED |
| | **CAT8B** | Event-Based Switch Debouncing & Latch | 18/09/26 | STM32F103, Pushbutton, PC13 |
| | **CAT8C** | Short Press vs. Long Press Detection | 18/09/26 | STM32F103, SysTick Timer, PC13 |
| | **CAT9A** | USART1 Character Echo & Terminal Interface | 28/09/26 | STM32F103, USART1 (115200 Baud) |
| | **CAT9B** | USART String Command Parser (ON/OFF/TOGGLE)| 28/09/26 | STM32F103, String Parser, PC13 |
| | **CAT10A**| STM32 to Wemos D1 (ESP8266) UART Bridge | 05/10/26 | STM32F103, ESP8266, USART2 |
| | **CAT10B**| ESP8266 AT Command Protocol Handshake | 05/10/26 | STM32F103, ESP8266 AT Firmware |
| | **CAT10C**| Wemos ESP8266 Wi-Fi Station Association | 05/10/26 | STM32F103, ESP8266, 2.4GHz Wi-Fi |
| | **CAT11A**| ESP8266 Embedded TCP/HTTP Web Server | 14/10/26 | STM32F103, ESP8266 (Port 80 HTTP) |
| | **CAT11B**| Node-RED HTTP Telemetry Polling Client | 14/10/26 | STM32 + ESP8266, Node-RED Dashboard|
| | **CAT12A**| Nucleo-F401RE On-Board Green LED Bring-Up | 23/10/26 | STM32F401RE Nucleo-64, PA5 LD2 |
| | **CAT12B**| Nucleo Pushbutton Switch & State Latch | 23/10/26 | STM32F401RE, PC13 Button B1, PA5 |
| | **CAT12C**| Nucleo Short vs. Long Press Classification | 23/10/26 | STM32F401RE, HAL_GetTick(), PA5 |
| | **CAT13** | BME280 Environmental Sensor & HTTP Stream | 27/10/26 | STM32F401RE, BME280 (I2C), ESP8266 |
| | **CAT14** | BME280 Environmental Telemetry via MQTT | 2/11/26 | STM32F401RE, BME280, MQTT Broker |

---

## 🏗️ Repository Layout

```
Foundations_of_IoT/
├── README.md
├── .gitignore
├── 8051/
│   ├── CAT1/ .. CAT4/
│   ├── CAT5/ (CAT5A, CAT5B.1..3, CAT5C)
│   ├── CAT6/ (CAT6A, CAT6B)
│   └── CAT7/ (CAT7A, CAT7B, CAT7C)
└── STM32/
    ├── CAT8/  (TASK8A, TASK8B, TASK8C)
    ├── CAT9/  (TASK9A, TASK9B)
    ├── CAT10/ (TASK10A, TASK10B, TASK10C)
    ├── CAT11/ (TASK11A, TASK11B)
    ├── CAT12/ (TASK12A, TASK12B, TASK12C)
    ├── CAT13/ (TASK13)
    └── CAT14/ (TASK14)
```
