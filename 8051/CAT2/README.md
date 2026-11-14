# CAT2: 8051 Bare-Metal LED Blink & Delay Calibration

## 🎯 Objective
Bring up the Atmel AT89S52 8-bit microcontroller by configuring a general-purpose I/O pin as a digital output and toggling an LED at a deterministic frequency using a calibrated software loop.

## ⚡ Hardware Architecture & Pinout
- **MCU:** AT89S52 (MCS-51 Architecture)
- **Clock Source:** 11.0592 MHz External Quartz Crystal
- **Operating Voltage:** 5.0 V DC
- **Target Pin:** Port 1 Pin 0 (`P1^0`) connected to LED anode via a 330Ω current-limiting resistor.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Direct SFR Addressing:** Utilized the `sbit` compiler keyword to map a dedicated symbol (`LED`) directly to `P1^0`.
2. **Delay Loop Calibration:** Built a nested loop function `delay_ms(unsigned int ms)`. At 11.0592 MHz, 1 machine cycle is 12 clock cycles (1.085 µs). The inner loop count (120 iterations) produces approximately 1.0 ms per step.
3. **Continuous Execution:** A non-terminating `while(1)` loop inverts `LED` state (`LED = ~LED`) followed by a 500 ms delay, resulting in a symmetric 1 Hz square wave.

## 📊 Verification & Results
- Verified symmetric 500 ms HIGH / 500 ms LOW duty cycle on hardware.
- Generated hex output verified via simulator logic analyzer.
