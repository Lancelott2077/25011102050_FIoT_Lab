CAT6A - UART Interrupt-Driven Transmit

EXP: CAT6A
DATE: 24/08/2026
NAME OF EXP: UART Serial Communication - Transmit

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52 (reg52.h) | Baud: 9600 | Crystal: 11.0592 MHz

TASK
1. UART Mode 1, 8-bit async
2. Timer1 Mode 2 for baud rate
3. Transmit: "Foundations of IoT - Dr.Dinesh G" via ISR

CORE LOGIC
- TI flag in serial ISR sends one character at a time

INFERENCE
Complete interrupt-driven UART transmit chain on 8051.
