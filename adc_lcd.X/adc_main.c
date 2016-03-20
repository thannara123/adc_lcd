/* 
 * File:   adc_main.c
 * Author: Krishna
 *
 * Created on September 27, 2015, 6:24 AM
 */


// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include"lcd.h"
#include"adc.h"
#include <stdlib.h>
#define _XTAL_FREQ 20000000 // 20Mh
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)


void main()
{   unsigned char volt[5] ,current[5];
    int v,i;
    TRISB = 0X00;  // output for the 8 bit
    TRISA =0XFF;
    int adc_value=0x00;
    unsigned char digits[5];
    lcd_init();   // lcd initialization
    adc_init();   // adc initialization
   
    string("gElectron ");
        
    while(1)

    {
      LINE2;
	
      CLEAR
	//while(1)

	//{
   v =   read_adc(0);  // reading voltage
   i =   read_adc(1);  // reading voltage for current
   v = (v * 4.89 * 2.4)/10;
   i = (i * 2.92);
   i = ((i*4.89)/0.47)/10;



   if(v< 1200)
   {
   volt[0] = ((v /1000)%10)+0x30;
   volt[1] = ((v /100) % 10) + 0x30;
   volt[2] = '.';
   volt[3] = ((v/ 10) %10) + 0x30;
   volt[4] = (v % 10) + 0x30 ;


   string("Volt    : ");
   for(int i =0; i<5;i++)
  lcd_data(volt[i]); // just displaying ADC value
  string("V");
  }
  else
  {

   string("Over Voltage");
    }
	LINE2;
	if(i<3100)
	{
	current[0] =((i /1000)%10)+0x30;
	current[1] = '.';
	current[2] = ((i /100) % 10) + 0x30;
	current[3] = ((i/ 10) %10) + 0x30;
	string("Current : ");
	for(int i =0; i<4;i++)
	lcd_data(current[i]);
	string("A");

	}
	else
	{

		string("Over Current");
	}
	__delay_ms(600);
	CLEAR
	}


    }




