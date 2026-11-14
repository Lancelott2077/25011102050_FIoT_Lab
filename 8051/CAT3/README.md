# CAT3 - Tactile Switch Debouncing & 4-State LED Controller

**EXP:** CAT3

**DATE:** 27/07/26

**NAME OF EXP:** Switch Logic and Multi-State LED Pattern Controller

**HARDWARE SETUP / PLATFORM:**
- **Microcontroller:** AT89S52 (11.0592 MHz)
- **Input Switch:** Tactile pushbutton switch connected to Pin P2.6 (Active-LOW with internal pull-up)
- **Ground Reference Pin:** Pin P2.3 configured and driven LOW (0 V reference line)
- **Output Indicators:** 4 Red LEDs connected to Port 1 lower nibble:
  - LED 0 $\implies$ P1.0
  - LED 1 $\implies$ P1.1
  - LED 2 $\implies$ P1.2
  - LED 3 $\implies$ P1.3
- **Resistor Network:** $4 	imes 330 	ext{ Ω}$ current-limiting resistors in series with LED anodes

**TASK NO:**
1. Interface a momentary mechanical pushbutton to an 8051 digital input pin.
2. Implement software debouncing to suppress contact bounce transients during switch transitions.
3. Design a Finite State Machine (FSM) cycling through four visual display patterns upon consecutive button presses:
   - State 0: Running LED sequence (P1.0 to P1.3)
   - State 1: 4-bit binary up-counter (0x0 to 0xF)
   - State 2: Alternating complementary flashing (0b0101 $\leftrightarrow$ 0b1010)
   - State 3: Synchronous all-LED strobe (0b1111 $\leftrightarrow$ 0b0000)

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Debounce Algorithm:**
  1. Poll input pin: `if (prt26 == 0)` detects initial contact.
  2. Software settling delay: Wait 20 ms to bypass mechanical bounce noise.
  3. Confirmation & Hold: If `prt26 == 0`, enter `while(prt26 == 0);` to hold execution until complete mechanical release.
  4. State Increment: Advance `state = (state + 1) % 4` on clean release.
- **State Logic Snippet:**
```c
void state_running(void) {
    static unsigned char pos = 0;
    P1 = (P1 & 0xF0) | (0x01 << pos); // Update lower nibble, preserve upper
    pos = (pos + 1) % 4;
    delay_ms(500);
}

void state_counter(void) {
    static unsigned char count = 0;
    P1 = (P1 & 0xF0) | (count & 0x0F);
    count = (count + 1) % 16;
    delay_ms(500);
}

void state_alternating(void) {
    static unsigned char toggle = 0;
    P1 = (P1 & 0xF0) | (toggle ? 0x05 : 0x0A);
    toggle = !toggle;
    delay_ms(500);
}

void state_all_flash(void) {
    static unsigned char flash = 0;
    P1 = (P1 & 0xF0) | (flash ? 0x0F : 0x00);
    flash = !flash;
    delay_ms(500);
}
```

**INFERENCE:**
Mechanical contact bounce typically causes multiple spurious transitions within a 5–15 ms window. The 20 ms software delay coupled with the blocking release barrier (`while(prt26 == 0)`) ensured that exactly one state transition occurred per physical press. The FSM cycled deterministically through the four LED modes while bitwise masking (`P1 & 0xF0`) prevented unintended alteration of upper Port 1 pins.
