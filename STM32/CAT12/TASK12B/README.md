# CAT12B: Nucleo Pushbutton Control with State Memory Latch

## 🎯 Objective
Interface the Nucleo-64 on-board blue user pushbutton (B1) on PC13 and implement a robust persistent state memory latch that controls the green user LED (PA5).

## ⚡ Hardware Architecture & Pinout
- **MCU:** STM32F401RET6 (Nucleo-F401RE)
- **Input:** User Button `B1` connected to `PC13` (Active-LOW with external hardware RC filter).
- **Output:** User LED `LD2` connected to `PA5`.

![Circuit Diagram](circuit.png)

## 🧠 Engineering Implementation
1. **Input Conditioning:** `PC13` configured as `GPIO_MODE_INPUT` with `GPIO_NOPULL` (Nucleo board includes external pull-up).
2. **State Memory Logic:**
   - Polls button pin for falling edge.
   - Applies software validation window (25 ms) to confirm stable mechanical state.
   - Inverts persistent software boolean flag `led_latch`.
   - Updates `PA5` output register based on latch state.
   - Holds until button release to prevent multiple toggle events per click.

## 📊 Verification & Results
- Clean, reliable toggle-on / toggle-off operation with zero contact bounce.
