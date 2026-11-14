CAT6B - UART Full-Duplex TX + RX Echo

EXP: CAT6B
DATE: 24/08/2026
NAME OF EXP: UART Full-Duplex Communication

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52 | Baud: 9600 (TH1=0xFA) | Crystal: 11.0592 MHz

TASK
1. UART TX: transmit initial character
2. UART RX: receive and echo back any character

CORE LOGIC
- Single ISR handles both TI (transmit) and RI (receive+echo)

INFERENCE
Full-duplex UART implemented with one ISR handling TX and RX simultaneously.
