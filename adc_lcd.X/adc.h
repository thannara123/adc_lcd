/* 
 * File:   adc.h
 * Author: Krishna
 *
 * Created on September 27, 2015, 6:50 AM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
//#define _XTAL_FREQ 200000000 // 20Mh
void adc_init();
unsigned int read_adc(unsigned char ch_selection);


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

