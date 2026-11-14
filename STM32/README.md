# STM32 ARM Cortex-M & IoT Edge Systems

This directory contains embedded firmware modules targeting **STM32F103 (Cortex-M3)** and **STM32F401 (Cortex-M4)** microcontrollers developed with STM32CubeMX HAL and Keil MDK-ARM.

---

## 📑 Module Index

| Category | Task | Experiment Title | Hardware & Protocols |
|:---|:---|:---|:---|
| **CAT8** | [TASK8A](CAT8/TASK8A/README.md) | GPIO Output Bring-Up | STM32F103C8T6, PC13 Active-LOW LED, HAL_GPIO |
| | [TASK8B](CAT8/TASK8B/README.md) | Event-Driven Switch Debouncing | External tactile switch, transition filter, state latch |
| | [TASK8C](CAT8/TASK8C/README.md) | Short vs. Long Press Detection | Time-domain button classifier (`<1s` vs `>1s`) |
| **CAT9** | [TASK9A](CAT9/TASK9A/README.md) | USART1 Character Loopback | USART1 (PA9/PA10, 115200 Baud), interactive terminal |
| | [TASK9B](CAT9/TASK9B/README.md) | USART String Command Parser | ASCII command parser (`ON`, `OFF`, `TOGGLE`) |
| **CAT10** | [TASK10A](CAT10/TASK10A/README.md) | Dual-MCU UART Bus | STM32 USART2 (PA2/PA3) ↔ ESP8266 Wemos D1 Mini |
| | [TASK10B](CAT10/TASK10B/README.md) | ESP8266 AT Command Probe | Automated modem initialization (`AT`, `AT+GMR`, `AT+RST`) |
| | [TASK10C](CAT10/TASK10C/README.md) | Wi-Fi Station Association | Station mode configuration (`AT+CWMODE=1`, `AT+CWJAP`) |
| **CAT11** | [TASK11A](CAT11/TASK11A/README.md) | Embedded TCP/HTTP Server | Port 80 listener (`AT+CIPSERVER`), static HTML payload |
| | [TASK11B](CAT11/TASK11B/README.md) | Node-RED HTTP Client Integration | REST polling endpoint, JSON telemetry to dashboard |
| **CAT12** | [TASK12A](CAT12/TASK12A/README.md) | Nucleo-64 User LED Bring-Up | STM32F401RE Nucleo-64, LD2 (PA5) green LED |
| | [TASK12B](CAT12/TASK12B/README.md) | Button B1 Memory Latch | User Button B1 (PC13), interrupt/debounced state toggle |
| | [TASK12C](CAT12/TASK12C/README.md) | SysTick Temporal Button Engine | `HAL_GetTick()` duration classifier, mode switcher |
| **CAT13** | [TASK13](CAT13/README.md) | BME280 Environmental HTTP Stream | I2C1 sensor acquisition, compensation math, HTTP telemetry |
| **CAT14** | [TASK14](CAT14/README.md) | BME280 MQTT Cloud Telemetry | MQTT client library, pub/sub architecture to Node-RED |
