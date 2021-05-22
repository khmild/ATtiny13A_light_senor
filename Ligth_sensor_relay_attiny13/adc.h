#ifndef ADC_LIB
#define ADC_LIB

#include <avr/io.h>

void adc_init();
uint16_t check_pot();
uint16_t check_sens();

#endif