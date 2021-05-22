#include "adc.h"

void adc_init(){
	ADCSRA = (1 << ADEN)|(1 << ADPS1)|(1 << ADPS0); // Enable ADC, prescaler 64
}

uint16_t check_pot(){
	
	ADMUX = (1 << MUX1); //PB4 select
	ADCSRA |= (1 << ADSC); //start conversion
	
	while((ADCSRA & (1 << ADSC))); //wait for conversion
	
	return (uint16_t)ADC;
}

uint16_t check_sens(){
	
	ADMUX = (1 << MUX0)|(1 << MUX1); //PB3 select
	ADCSRA |= (1 << ADSC); //start conversion
		
	while((ADCSRA & (1 << ADSC))); //wait for conversion
		
	return (uint16_t)ADC;
}