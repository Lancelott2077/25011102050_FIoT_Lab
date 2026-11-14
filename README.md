# Foundations of IoT (FIoT) Lab Portfolio

**Student ID:** `25011102050`  
**Course:** Foundations of Internet of Things + Embedded Systems Lab  
**GitHub Repository:** [25011102050_FIoT_Lab](https://github.com/Lancelott2077/25011102050_FIoT_Lab)

---

## 📌 Executive Summary

This repository houses an end-to-end embedded systems and IoT engineering portfolio spanning bare-metal 8-bit microcontrollers up to modern 32-bit ARM Cortex-M processors integrated with wireless edge gateways and cloud analytics platforms.

The project progression covers:
1. **Bare-Metal 8051 (AT89S52):** Low-level register programming, bit-addressable GPIO manipulation, hardware timers, software PWM synthesis, interrupt-driven UART, and character LCD control.
2. **ARM Cortex-M3 (STM32F103):** STM32 HAL architecture, clock configuration (APB/AHB), event-driven debouncing, command line serial parser, and dual-MCU bus interfacing.
3. **Wi-Fi Edge Networking (ESP8266):** AT modem protocol state machine, station network association, embedded lightweight HTTP server, and REST API delivery.
4. **ARM Cortex-M4 (STM32F401RE Nucleo-64):** High-performance peripheral interfacing, SysTick temporal press analysis, and digital sensor buses.
5. **IoT Telemetry & Analytics (I2C / HTTP / MQTT / Node-RED):** BME280 sensor data acquisition, calibration algorithms, JSON serialization, and real-time dashboard analytics over HTTP and MQTT.

---

## 📂 Repository Navigation

```
├── 8051/                          # 8-bit AT89S52 Microcontroller Experiments
│   ├── CAT2/                      # Bare-Metal GPIO & Software Delay
│   ├── CAT3/                      # Switch Debounce & Multi-State Machine
│   ├── CAT4/                      # Matrix Keypad & 7-Segment Display
│   ├── CAT5/                      # Timers, Software PWM & Stepper Control
│   ├── CAT6/                      # Interrupt-Driven Serial Communication
│   └── CAT7/                      # HD44780 16x2 Character LCD Interfacing
│
└── STM32/                         # 32-bit ARM Cortex-M3/M4 Experiments
    ├── CAT8/                      # STM32F103 GPIO, Debounce & Press Timing
    ├── CAT9/                      # STM32F103 USART Echo & Command Parser
    ├── CAT10/                     # Dual-MCU UART & ESP8266 Wi-Fi Setup
    ├── CAT11/                     # Embedded TCP Server & Node-RED HTTP Client
    ├── CAT12/                     # Nucleo-F401RE Bring-Up & Button Latches
    ├── CAT13/                     # BME280 Sensor via HTTP Telemetry
    └── CAT14/                     # BME280 Sensor via MQTT Cloud Broker
```

---

## 🛠️ Toolchains & Platforms

| Platform | Core Architecture | Toolchain / IDE | Hardware Target |
|:---|:---|:---|:---|
| **8051** | 8-bit MCS-51 (11.0592 MHz) | Keil µVision (C51 Compiler) | AT89S52 Dev Board |
| **STM32F1** | 32-bit ARM Cortex-M3 (72 MHz) | STM32CubeMX + Keil MDK-ARM | STM32F103C8T6 (Blue Pill) |
| **STM32F4** | 32-bit ARM Cortex-M4 (84 MHz, FPU) | STM32CubeMX + Keil MDK-ARM | NUCLEO-F401RE |
| **Wi-Fi SoC** | 32-bit Tensilica L106 (80 MHz) | ESP AT Command Set 1.7+ | Wemos D1 Mini (ESP8266) |
| **IoT Cloud** | Event-Driven Node.js Runtime | Node-RED Flow Engine | Local / Cloud Broker (MQTT) |
