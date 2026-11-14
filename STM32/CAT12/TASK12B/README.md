# CAT12B – Nucleo Pushbutton Control with State Memory

**EXP:** CAT12B

**DATE:** 23/10/26

**NAME OF EXP:** On-Board Switch Control with State Remembrance

**HARDWARE SETUP / PLATFORM:**
- **Board:** NUCLEO-F401RE
- **Input:** On-board Blue User Button (`B1`) connected to Pin PC13 (Active-LOW circuit with external RC pull-up)
- **Output:** Green User LED (`LD2`) connected to Pin PA5

**TASK NO:**
1. Configure pin PC13 as a digital input to read blue button B1.
2. Implement software debouncing to reject contact bounce on button press.
3. Maintain a persistent state memory latch that toggles the LED state on each press and remembers it after release.

**Circuit Diagram:**

![Circuit Diagram](circuit.png)

**Core Logic / Pseudocode / Code Base:**
- **Persistent State Memory Logic:**
```c
uint8_t led_latch = 0;

while (1) {
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
        HAL_Delay(25); // Debounce delay
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            led_latch = !led_latch; // Invert memory latch
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_latch ? GPIO_PIN_SET : GPIO_PIN_RESET);
            while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET); // Wait for release
        }
    }
}
```

**INFERENCE:**
The persistent state memory latch operated reliably. Pressing blue button B1 toggled green LED LD2, and the system remembered the latched state indefinitely until the next button press occurred.
