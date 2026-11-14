# CAT1 - 8051 Architecture & Toolchain Setup

**EXP:** CAT1

**DATE:** 13/07/26

**NAME OF EXP:** 8051 Architecture, Memory Organization, and Keil µVision Setup

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** Atmel AT89S52 (MCS-51 Architecture)
- **Clock Source:** 11.0592 MHz Quartz Crystal with dual 33 pF load capacitors
- **Power Supply:** Regulated +5.0 V DC via USB / DC Barrel Jack
- **Development Toolchain:** Keil µVision IDE with C51 Optimizing Compiler and A51 Macro Assembler
- **Flash In-System Programmer:** USB-ISP interface with 10-pin SPI ribbon cable

**TASK NO:**
1. Configure a new project workspace in Keil µVision targeting the AT89S52 microcontroller.
2. Analyze 8051 memory architecture: 128 bytes internal direct/indirect RAM, 8 KB Flash ROM, and Special Function Registers (SFRs, 0x80 - 0xFF).
3. Inspect and configure the startup assembly file (`STARTUP.A51`) to ensure proper stack pointer initialization and RAM clearing upon hardware reset.
4. Verify the generation of Intel HEX-80 output files (`Objects/*.hex`) for downstream ISP hardware flashing.

**Circuit Diagram:**
*Initial platform bring-up session — hardware verified through ISP programmer connection to AT89S52 SPI pins (MOSI P1.5, MISO P1.6, SCK P1.7, RST).*

**Core Logic / Pseudocode / Code Base:**
1. **Startup Initialization:**
   `STARTUP.A51` executes immediately upon power-on reset (Vector `0x0000`). It loops through internal memory registers clearing IDATA to `0x00` and configures the hardware stack pointer (`SP`) to address `0x07` (top of Register Bank 0) or higher.
2. **Register Header Inclusions:**
   Including `<reg51.h>` defines standard SFR addresses (such as `P0 = 0x80`, `P1 = 0x90`, `P2 = 0xA0`, `P3 = 0xB0`, `PSW = 0xD0`, `ACC = 0xE0`).
3. **Build Target Settings:**
   Target configuration specifies 11.0592 MHz system clock, Small memory model (data in internal RAM), and enables the "Create HEX File" option in the Output configuration tab.

**INFERENCE:**
The Keil µVision development toolchain was successfully established and verified for the AT89S52 microcontroller. The Harvard architecture of the 8051 family—separating program code memory (ROM) and data memory (RAM)—was analyzed alongside the role of the Special Function Register (SFR) address map. Verification of `STARTUP.A51` provided clear understanding of post-reset processor state initialization prior to branching to the C `main()` function.
