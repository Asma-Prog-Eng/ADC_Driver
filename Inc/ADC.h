/*
 * ADC.h
 *
 *  Created on: Jul 14, 2025
 *      Author: asmae
 */

#ifndef ADC_H_
#define ADC_H_


uint16_t ADC1_read(void) ;

void GPIOA_Init(void);

int ADC_resolution_calculation(int ADC_bit_resolution );

#endif /* ADC_H_ */
