/* 
 * File:   adc.c
 * Author: Krishna
 *
 * Created on September 27, 2015, 7:14 AM
 */
#include<xc.h>
#include"adc.h"
#define _XTAL_FREQ 20000000
void adc_init()
{

   ADCON0 = 0x81;// 10000001 TAD is fosci/32 and last bit is adc poweron
   ADCON1 = 0x80; //all port selected as output ,vref= vcc,
   TRISA = 0x2f; //ENANLING AS  ANALOG INPUT
   TRISE = 0X07; // ENANLING AS  ANALOG INPUT
}

unsigned int read_adc(unsigned char ch_selection)
{
 if(ch_selection>7) // checking is  channel greater than 7
      return 0;      // yes return zero
   ADCON0 &= 0xC7; //making adcon0 clear
 ADCON0 |= ch_selection<<3;
  __delay_us(50); //adc  acquisition time as 19.72 ?s as datasheet
  GO_nDONE = 1;
 while(GO_nDONE); // after conversion GO_nDONE value become 0 autmatically.
 return((ADRESH<<8)+ADRESL);
 
}