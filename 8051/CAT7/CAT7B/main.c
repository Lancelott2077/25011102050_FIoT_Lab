#include <reg52.h>

sbit LCD_RS = P3^2;
sbit LCD_EN = P3^3;

/*========================================================
  DELAY FUNCTION
========================================================*/
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 123; j++) { }
    }
}

/*========================================================
  SEND ONE 4-BIT NIBBLE TO LCD
========================================================*/
void lcd_send_nibble(unsigned char nibble)
{
    P3 = (P3 & 0x0F) | (nibble & 0xF0);
    LCD_EN = 1;
    delay_ms(1);
    LCD_EN = 0;
    delay_ms(1);
}

/*========================================================
  SEND ONE COMPLETE BYTE (4-bit mode)
========================================================*/
void lcd_send_byte(unsigned char value)
{
    lcd_send_nibble(value & 0xF0);          // Higher 4 bits
    lcd_send_nibble((value << 4) & 0xF0);   // Lower 4 bits
}

/*========================================================
  SEND COMMAND TO LCD (RS = 0)
========================================================*/
void lcd_cmd(unsigned char command)
{
    LCD_RS = 0;
    lcd_send_byte(command);
    delay_ms(2);
}

/*========================================================
  SEND DATA / CHARACTER TO LCD (RS = 1)
========================================================*/
void lcd_data(unsigned char dataa)
{
    LCD_RS = 1;
    lcd_send_byte(dataa);
    delay_ms(2);
}

/*========================================================
  LCD INITIALIZATION
========================================================*/
void lcd_init(void)
{
    delay_ms(20);
    LCD_RS = 0;
    LCD_EN = 0;

    lcd_send_nibble(0x30); delay_ms(5);
    lcd_send_nibble(0x30); delay_ms(1);
    lcd_send_nibble(0x30); delay_ms(1);
    lcd_send_nibble(0x20); delay_ms(1);

    lcd_cmd(0x28); // 4-bit, 2 lines, 5x8 font
    lcd_cmd(0x0F); // Display ON, Cursor ON, Blink ON
    lcd_cmd(0x06); // Cursor moves right, no display shift
    lcd_cmd(0x01); // Clear Display
    delay_ms(2);
}


/* ========================================================
   TASK 7B: NEW HELPER FUNCTIONS
   ======================================================== */

/* 1. lcd_goto: Move cursor to specific row (0 or 1) and column (0 to 15) */
void lcd_goto(unsigned char row, unsigned char column)
{
    unsigned char address;

    if (row == 0)
    {
        address = 0x00 + column; // First row starts at DDRAM address 0x00
    }
    else
    {
        address = 0x40 + column; // Second row starts at DDRAM address 0x40
    }

    // The HD44780 command to "Set DDRAM Address" is 0x80 + the address
    lcd_cmd(0x80 | address);
}

/* 2. lcd_puts: Print a whole string of text at once */
void lcd_puts(char *str)
{
    // Loop through the string until we hit the "null terminator" (\0)
    while (*str != '\0')
    {
        lcd_data(*str); // Send the current character to the LCD
        str++;          // Move the pointer to the next character
    }
}

/* 3. lcd_print_number: Print an integer (0 to 65535) without libraries */
void lcd_print_number(unsigned int value)
{
    unsigned char digits[6]; // Array to hold up to 5 digits (65535) + 1 safety
    unsigned char i = 0;

    // Special case: if the number is exactly 0, just print '0'
    if (value == 0)
    {
        lcd_data('0');
        return;
    }

    // Step A: Extract digits from right to left using modulo (%)
    while (value > 0)
    {
        digits[i] = (value % 10) + '0'; // Get last digit and convert to ASCII text
        value = value / 10;             // Chop off the last digit
        i++;
    }

    // Step B: Print the digits from left to right (reverse order)
    while (i > 0)
    {
        i--;
        lcd_data(digits[i]);
    }
}

void main(void)
{
    unsigned int counter = 0; // Variable to demonstrate dynamic updating

    /* 1. Initialize the LCD */
    lcd_init();

    /* 2. Test lcd_goto and lcd_puts */
    lcd_goto(0, 0);               // Move to Row 0, Column 0
    lcd_puts("Task 7B Ready!");   // Print a static string

    lcd_goto(1, 0);               // Move to Row 1, Column 0
    lcd_puts("Count: ");          // Print a label

    /* 3. Dynamic Value Update Loop */
    while(1)
    {
        /* Move cursor to Row 1, Column 7 (right after "Count: ") */
        lcd_goto(1, 7);

        /* Optional: Print 5 spaces to "erase" old numbers if the count 
           ever shrinks (e.g., going from 100 down to 99) */
        lcd_puts("     "); 

        /* Move back and print the new number */
        lcd_goto(1, 7);
        lcd_print_number(counter);

        counter++;                // Increase the number by 1
        delay_ms(500);            // Wait 500ms so our eyes can see it change
    }
}