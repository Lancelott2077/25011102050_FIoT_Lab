CAT3 - Switch-Based State Machine LED Control

EXP: CAT3
DATE: 27/07/2026
NAME OF EXP: Switch Logic - Multi-State LED Control

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52 | Switch: P2^6 (Active LOW) | LEDs: P1^0–P1^3

TASK
1. Button debounce logic
2. State machine: Running LED, Binary Counter, Alternating, All Flash

CORE LOGIC
- Button press cycles through 4 LED display states with software debounce

INFERENCE
4-state LED control system driven by a single push button on the AT89S52.
