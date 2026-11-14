# CAT5A - Hardware Timer0 1-Second LED Blink & IDLE Sleep

**EXP:** CAT5A

**DATE:** 10/08/26

**NAME OF EXP:** Timer and Interrupt Programming - Hardware Timer0 1-Second LED Toggle

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52 (11.0592 MHz crystal)
- **Timer Peripheral:** Internal Hardware Timer 0 configured in Mode 1 (16-bit Timer/Counter)
- **Output:** Status LED connected to Port 1 Pin 0 (`P1^0`) via 330 Ω resistor
- **Registers Used:** `TMOD`, `TH0`, `TL0`, `TCON`, `IE`, `PCON`

**TASK NO:**
1. Configure Timer 0 in 16-bit Timer Mode 1 with hardware interrupt generation on overflow.
2. Calculate the exact 16-bit preload value (`TH0`/`TL0`) for a 10 ms overflow period under an 11.0592 MHz crystal.
3. Accumulate 100 overflow events inside the ISR to generate an exact 1.0-second delay interval.
4. Place the CPU core into low-power IDLE sleep mode between interrupt service events.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Preload Math Derivation:**
  $$	ext{Oscillator Frequency } f_{	ext{osc}} = 11.0592 	ext{ MHz}$$
  $$	ext{Timer Clock } f_{	ext{timer}} = rac{f_{	ext{osc}}}{12} = 921.6 	ext{ kHz} \implies T_{	ext{tick}} pprox 1.08507 	ext{ µs}$$
  $$	ext{Counts required for 10 ms } N = rac{10000 	ext{ µs}}{1.08507 	ext{ µs}} = 9216 	ext{ counts}$$
  $$	ext{16-bit Preload Value } = 65536 - 9216 = 56320 = 	ext{0xDC00}$$
  $$\implies 	ext{TH0} = 	ext{0xDC}, \quad 	ext{TL0} = 	ext{0x00}$$
- **Firmware Implementation:**
```c
#include <reg51.h>

sbit LED = P1^0;
unsigned char tick_count = 0;

void timer0_isr(void) interrupt 1 {
    TL0 = 0x00;        // Reload low byte
    TH0 = 0xDC;        // Reload high byte
    TF0 = 0;           // Clear overflow flag
    tick_count++;
    if(tick_count >= 100) {
        LED = ~LED;    // 100 * 10 ms = 1.0 second toggle
        tick_count = 0;
    }
}

void main(void) {
    TMOD = 0x01;       // Timer 0 in Mode 1 (16-bit timer)
    TL0 = 0x00;
    TH0 = 0xDC;
    TR0 = 1;          // Start Timer 0
    ET0 = 1;          // Enable Timer 0 Interrupt
    EA  = 1;          // Enable Global Interrupts
    while(1) {
        PCON |= 0x01; // Enter IDLE mode: CPU sleeps until next interrupt
    }
}
```

**INFERENCE:**
Hardware timer interrupts provide deterministic, drift-free timing completely independent of code execution length in the main thread. By placing the 8051 into IDLE sleep (`PCON |= 0x01`), the CPU core was halted between 10 ms ticks, significantly reducing dynamic current consumption while maintaining precise 1.0 Hz square wave generation.
