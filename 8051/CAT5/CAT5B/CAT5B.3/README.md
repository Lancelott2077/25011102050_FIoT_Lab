# CAT5B.3: PWM Servo Motor Angular Sweep

## 🎯 Objective
Implement standard 50 Hz RC servo control signaling with pulse durations between 1.0 ms (-90°) and 2.0 ms (+90°) using Timer0 interrupt timing.

## ⚡ Hardware Architecture & Pinout
- **MCU:** AT89S52 (11.0592 MHz)
- **Output:** `P1^0` connected to Servo Control wire.
- **Power:** External +5V regulated DC supply (common ground with 8051).

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Frame Timing:** Synthesizes a 20 ms total cycle time (50 Hz repetition rate).
2. **Pulse-Width Steering:** Generates active HIGH pulses from 1.0 ms to 2.0 ms, steering the servo shaft smoothly across its full 180° displacement range.
3. **Position Sweep:** Implements timed angular increments to execute sweeping motions without mechanical overshoot.

## 📊 Verification & Results
- Continuous jitter-free angular sweeps verified on standard SG90/MG995 servo motors.
