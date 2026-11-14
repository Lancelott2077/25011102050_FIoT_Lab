  #include <reg52.h>

/*========================================================
  AMOTECH 8051 BOARD - LCD CONNECTION

  LCD RS  -> P3.2
  LCD E   -> P3.3
  LCD D4  -> P3.4
  LCD D5  -> P3.5
  LCD D6  -> P3.6
  LCD D7  -> P3.7
  LCD RW  -> GND

  LCD : 16x2 HD44780
  MCU : AT89S52
========================================================*/


/*---------------- LCD CONTROL PINS ----------------*/

sbit LCD_RS = P3^2;
sbit LCD_EN = P3^3;


/*========================================================
  DELAY
========================================================*/

void delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 123; j++)
        {
        }
    }
}


/*========================================================
  SEND ONE 4-BIT NIBBLE
========================================================*/

void lcd_send_nibble(unsigned char nibble)
{
    /*
       P3.4 - P3.7 carry LCD data.

       Keep P3.0 - P3.3 unchanged.
    */

    P3 = (P3 & 0x0F) | (nibble & 0xF0);

    LCD_EN = 1;
    delay_ms(1);

    LCD_EN = 0;
    delay_ms(1);
}


/*========================================================
  SEND ONE COMPLETE BYTE
========================================================*/

void lcd_send_byte(unsigned char value)
{
    /* Higher nibble */

    lcd_send_nibble(value & 0xF0);

    /* Lower nibble */

    lcd_send_nibble((value << 4) & 0xF0);
}


/*========================================================
  SEND COMMAND
========================================================*/

void lcd_cmd(unsigned char command)
{
    LCD_RS = 0;

    lcd_send_byte(command);

    delay_ms(2);
}


/*========================================================
  SEND DATA / CHARACTER
========================================================*/

void lcd_data(unsigned char value)
{
    LCD_RS = 1;

    lcd_send_byte(value);

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


    /* LCD initialization */

    lcd_send_nibble(0x30);
    delay_ms(5);

    lcd_send_nibble(0x30);
    delay_ms(1);

    lcd_send_nibble(0x30);
    delay_ms(1);

    /* Enter 4-bit mode */

    lcd_send_nibble(0x20);
    delay_ms(1);


    /* Function Set
       4-bit
       2 lines
       5x8 font
    */

    lcd_cmd(0x28);


    /* Display ON
       Cursor ON
       Blink ON
    */

    lcd_cmd(0x0F);


    /* Entry Mode */

    lcd_cmd(0x06);


    /* Clear Display */

    lcd_cmd(0x01);

    delay_ms(2);
}


/*========================================================
  MAIN - TASK 7A
========================================================*/

void main(void)
{
    lcd_init();


    /* Display AT89S52 */

   lcd_data('A');
   /*
   	lcd_data('T');
    lcd_data('8');
    lcd_data('9');
    lcd_data('S');
    lcd_data('5');
    lcd_data('2');
*/

    /* Move cursor to second row */

    lcd_cmd(0xC0);


    while(1)
    {
    }
}