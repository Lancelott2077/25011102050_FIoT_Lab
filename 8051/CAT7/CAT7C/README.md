# CAT7C - Real-Time UART to 16x2 LCD Display Bridge

**EXP:** CAT7C

**DATE:** 24/08/26

**NAME OF EXP:** LCD Interfacing and Display Control - Real-Time UART to LCD Bridge

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Serial Input: P3.0 (RXD) at 9600 Baud
- LCD Output: 16x2 Character LCD on Port 3 (RS=P3.2, EN=P3.3, D4-D7=P3.4-P3.7)

**TASK NO:**
1. Configure UART reception at 9600 baud.
2. Interface the 16x2 LCD on Port 3 without interfering with the serial pins on P3.0/P3.1.
3. Receive characters sent from a PC serial terminal and display them live on the LCD screen.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- UART receiver captures characters incoming on P3.0 into a buffer.
- Port 3 is shared carefully: P3.0/P3.1 handles serial communication, while P3.2-P3.7 drives LCD control and data.
- Special character handling: Carriage return (``) moves cursor to the second line (`0xC0`); clear command resets the screen.

**INFERENCE:**
A functional hardware serial-to-LCD bridge was demonstrated. Characters typed in a terminal on the host computer were displayed immediately on the physical LCD.
