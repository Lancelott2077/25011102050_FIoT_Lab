# 8051 Microcontroller (AT89S52) Experiments

This directory contains bare-metal firmware modules developed for the **Atmel AT89S52** 8-bit microcontroller using the Keil µVision C51 compiler and simulator.

---

## 📑 Module Index

| Lab Module | Experiment Title | Core Focus / Peripheral |
|:---|:---|:---|
| **CAT2** | [Bare-Metal LED Blink](CAT2/README.md) | Direct SFR bit addressing (`sbit`), clock-calibrated software delay |
| **CAT3** | [Switch Logic & State Machine](CAT3/README.md) | Active-LOW button debounce, 4-state visual sequence machine |
| **CAT4** | [4x3 Keypad & 7-Segment Display](CAT4/README.md) | Row-column scan multiplexing, 7-segment lookup table decoding |
| **CAT5A** | [Timer0 1s Interrupt Blink](CAT5/CAT5A/README.md) | Timer0 Mode 1 (16-bit), ISR vector `0x000B`, IDLE mode sleep |
| **CAT5B.1** | [Software PWM Breathing LED](CAT5/CAT5B/CAT5B.1/README.md) | High-frequency (~100µs) timer ISR, 10-step duty modulation |
| **CAT5B.2** | [PWM Motor Speed Regulation](CAT5/CAT5B/CAT5B.2/README.md) | DC motor speed control via variable duty ratio |
| **CAT5B.3** | [PWM Servo Angular Sweep](CAT5/CAT5B/CAT5B.3/README.md) | 50Hz frame timing, pulse-width positioning (1ms to 2ms) |
| **CAT5C** | [Stepper Motor Control](CAT5/CAT5C/README.md) | 4-phase unipolar full-step sequence with ULN2003 driver |
| **CAT6A** | [UART Interrupt Transmission](CAT6/CAT6A/README.md) | Timer1 Mode 2 auto-reload (9600 baud), interrupt vector `0x0023` |
| **CAT6B** | [Full-Duplex UART Echo](CAT6/CAT6B/README.md) | Concurrent TX streaming and RX character loopback |
| **CAT7A** | [16x2 LCD & Keypad Navigation](CAT7/CAT7A/README.md) | HD44780 4-bit nibble interface, keypad directional cursor control |
| **CAT7B** | [16x2 LCD Multi-Line Messages](CAT7/CAT7B/README.md) | DDRAM address management (`0x80` & `0xC0`), line-wrapping |
| **CAT7C** | [Real-Time UART-to-LCD Display](CAT7/CAT7C/README.md) | Asynchronous serial reception mapped directly to visual LCD cells |
