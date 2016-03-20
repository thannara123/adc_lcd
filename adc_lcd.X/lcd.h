/* 
 * File:   lcd.h
 * Author: Krishna
 *
 * Created on September 27, 2015, 6:28 AM
 */

#ifndef LCD_H
#define	LCD_H
#include <xc.h>
#ifdef	__cplusplus
extern "C" {
#endif
// LCD Conections
//#define _XTAL_FREQ 200000000 // 20Mh
#define LCDPORT PORTB
#define RS RB2
#define E RB3
#define LINE2 lcd_cmd(0xc0)
#define CLEAR lcd_cmd(0x01);
//#define clear_Lcd lcd_cmd(0x01);

/***************************************************
			F U N C T I O N S
****************************************************/
void latch(void);
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char c);
void lcd_data(unsigned char c);
void lcd_init();
void string(const char *q);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

