
#include "stm32f4xx.h"
#include <stdio.h>
#include "ADC.h"


#define RCC_ADC1EN          (1U << 8 )

#define RCC_GPIOAEN         (1U << 0)

#define ADC_SREOC           (1U << 1)

#define ADC_CR2ADON         (1U << 0)

#define ADC_SQR3SQ1         (1U  << 0)

#define ADC_SQR1L           (1U << 20)

#define ADC_CR2SWSTART      (1U << 30)


void GPIOA_Init(void) {

 /************************Configure ADC PIO pin*******************************************/

	// enable clock access for port A ( PA1)

    RCC->AHB1ENR |= RCC_GPIOAEN ;

	// configure PA1 pin mode to analog

   GPIOA->MODER |= (0x3 << 2);


/*************************Configure ADC parameters *************************************/

	// enable clock access for ADC periph

    RCC->APB2ENR |= RCC_ADC1EN;

	// configure conversion sequence start :  single conversion- channel 1 (ADC1_1)

    ADC1->SQR3 |= ADC_SQR3SQ1;


	// configure senquence length to 1 conversion

    ADC1->SQR1 &=~ADC_SQR1L ;

	// enable ADC periph

    ADC1->CR2 |= ADC_CR2ADON;


}

uint16_t ADC1_read(void ) {

	// start conversion

	ADC1->CR2  |= ADC_CR2SWSTART ;

	// wait till conversion is done

	while (!(ADC1->SR & ADC_SREOC)) {};

   for(int i=0 ; i <10000000; i++){};
	// read data register

   return (ADC1->DR & 0xFF);


}

int ADC_resolution_calculation(int ADC_bit_resolution ) {

	int result = 1;

	int temp = ADC_bit_resolution ;

	while ( temp > 0) {

		    result *= 2;
			temp -=1;
	}

	return result;
}


