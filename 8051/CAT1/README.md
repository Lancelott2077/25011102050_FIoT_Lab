# CAT1 - 8051 Architecture & Toolchain Setup

**EXP:** CAT1

**DATE:** 13/07/26

**NAME OF EXP:** 8051 Architecture, Memory Organization, and Keil µVision Setup

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52 (MCS-51 Architecture)
- Clock: 11.0592 MHz Crystal Oscillator
- IDE: Keil µVision IDE (C51 Compiler)
- Programmer: USB-ISP / ISP Flash Programmer

**TASK NO:**
1. Configure the Keil µVision development environment for the AT89S52 device.
2. Study the 8051 memory map: internal RAM (128 bytes direct/indirect), SFR space (0x80 - 0xFF), and Flash ROM.
3. Verify startup code (STARTUP.A51) and standard register header inclusions (`reg51.h`).

**Circuit Diagram:**
*Hardware bring-up and toolchain verification session — development board power supply and ISP interface verified.*

**Core Logic / Pseudocode / Code Base:**
- Project creation in Keil with target AT89S52 selected.
- Adding STARTUP.A51 for clearing memory and initializing stack pointer on reset.
- Verifying compilation toolchain and output HEX file generation settings.

**INFERENCE:**
The Keil µVision IDE and C51 compiler toolchain were configured successfully. The memory architecture, Special Function Registers (SFRs), and reset vector mechanisms of the AT89S52 microcontroller were thoroughly understood.
