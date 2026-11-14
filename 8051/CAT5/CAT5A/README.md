# CAT5A: Hardware Timer0 Interrupt & Low-Power IDLE Mode

## 🎯 Objective
Achieve drift-free 1-second LED toggling using 8051 hardware Timer0 in 16-bit mode, offloading timing entirely from the CPU and placing the core into low-power IDLE sleep.

## ⚡ Hardware Architecture & Pinout
- **MCU:** AT89S52 (11.0592 MHz)
- **Target Pin:** `P1^0` connected to status LED.
- **Timer Peripheral:** Timer 0, Mode 1 (16-bit Timer/Counter).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Timer Reload Calculation:**
   $$	ext{Machine Cycle} = rac{12}{11.0592 	ext{ MHz}} = 1.08507 	ext{ µs}$$
   $$	ext{Counts for 10 ms} = rac{10000 	ext{ µs}}{1.08507 	ext{ µs}} pprox 9216 	ext{ counts (0x2400)}$$
   $$	ext{Preload Value} = 65536 - 9216 = 56320 = 	ext{0xDC00} \implies 	ext{TH0}=0xDC, 	ext{TL0}=0x00$$
2. **Interrupt Service Routine (ISR):** Vector 1 (`0x000B`) reloads `TH0`/`TL0` and increments a software counter. At count 100 (100 × 10 ms = 1.0 s), `P1^0` is inverted.
3. **Power Management:** Main loop executes `PCON |= 0x01` to halt the CPU core until the next timer tick wakes it up, minimizing dynamic power consumption.

## 📊 Verification & Results
- 1.0 Hz square wave verified with zero timing jitter compared to software loops.
