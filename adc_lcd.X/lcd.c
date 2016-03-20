/* 
 * File:   lcd.c
 * Author: Krishna
 *
 * Created on September 27, 2015, 6:38 AM
 */
#define _XTAL_FREQ 200000000 // 20Mh
#define LCDPORT PORTB
#define RS RB2
#define E RB3
#define LINE2 lcd_cmd(0xc0)
#include<xc.h>
#include"lcd.h"
void latch(void)
{
    E = 1;
    __delay_ms(1);
    E = 0;

}
void lcd_cmd(unsigned char c)   // used to send the command / Instruction to the lcd port
{
RS = 0;    // send a '0' value to select to send command
__delay_ms(1);
LCDPORT = c & 0xf0;  //  send  the command c only 4 bit by masking the lower bit
latch();
__delay_ms(1);
LCDPORT =  (c << 4); // giving the lowerbit  by shifting the 4 bit to left
latch();
}
 void lcd_data(unsigned char c)
 {
 RS =1;    // send 1 to send data
 __delay_ms(1);
LCDPORT = c & 0xf0 | 0x4; //send  the data  only  4 bit by masking the lower bit and also making the RS pin high by giving 0x04 .
__delay_ms(1);
latch();

LCDPORT = (c << 4)| 0x4; ; // giving the lower bit  by shifting the 4 bit to left
latch();
}

 void lcd_init()
{
 __delay_ms(20);
    lcd_cmd(0x30);  //as per data sheet
  __delay_ms(20);
    lcd_cmd(0x30);    //as per data sheet
  __delay_ms(4);
    lcd_cmd(0x32);    //as per data sheet
 __delay_ms(4);
    lcd_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
    lcd_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
    lcd_cmd(0x0c);            // Make cursorinvisible
    lcd_cmd(0x6);            // Set entry Mode(auto increment of cursor)
}

 void string(const char *q)    // used to send single charcter to display the lcd
{
    while (*q) {
        lcd_data(*q++);
    }
}
