# CAT5B.1 - High-Frequency Timer0 Software PWM Breathing LED

**EXP:** CAT5B.1

**DATE:** 10/08/26

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing - Software PWM Breathing LED

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52 (11.0592 MHz)
- **Output:** High-efficiency LED connected to Port 1 Pin 0 (`P1^0`)
- **Timer:** Hardware Timer 0 configured for high-frequency (~100 µs) periodic ISR triggers

**TASK NO:**
1. Configure Timer 0 in Mode 1 to generate a recurring interrupt tick every ~100 µs.
2. Implement a 10-step software Pulse Width Modulation (PWM) signal on a general-purpose GPIO pin.
3. Implement a dynamic duty cycle sweep algorithm that smoothly brightens and dims the LED in a continuous breathing cycle.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **PWM Frame Frequency:**
  - Timer tick: ~100 µs (`TH0 = 0xFF, TL0 = 0xA4`).
  - PWM period: $10 	ext{ steps} 	imes 100 	ext{ µs} = 1.0 	ext{ ms} \implies 1 	ext{ kHz carrier frequency}$.
  - A 1 kHz frequency is well above the human eye's flicker fusion threshold (~60–80 Hz), ensuring smooth illumination.
- **Modulation Logic:**
```c
void timer0_ISR(void) interrupt 1 {
    TH0 = 0xFF;
    TL0 = 0xA4; // ~100 us reload

    if (count < duty) LED = 1;
    else              LED = 0;

    count++;
    if (count >= 10) count = 0;

    speed++;
    if (speed >= 500) { // Update duty cycle every 50 ms
        speed = 0;
        if (up) {
            duty++;
            if (duty >= 10) up = 0;
        } else {
            duty--;
            if (duty == 0) up = 1;
        }
    }
}
```

**INFERENCE:**
Pulse Width Modulation was successfully synthesized on a microcontroller lacking dedicated hardware PWM channels. The 1 kHz carrier frequency eliminated visible strobing, while the gradual automated modulation of the duty cycle from 0% to 100% produced a natural breathing visual effect.
