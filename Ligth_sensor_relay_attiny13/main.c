#define F_CPU 9600000

#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

uint16_t sensor_val = 0;
uint16_t pot_val = 0;
uint16_t hysteresis = 15;

int main(void)
{
	//relay output
	DDRB |= (1 << DDB1);
	PORTB |= (1 << DDB1);
	
	adc_init();
	
    while (1) 
    {
		
		sensor_val = check_sens();
		pot_val = check_pot();
		
		pot_val = check_pot();
		
		if (sensor_val > (pot_val + hysteresis))
		{
			PORTB |= (1 << DDB1);
		}
		
		if (sensor_val < (pot_val - hysteresis))
		{
			PORTB &= ~(1 << DDB1);
		}
		
    }
}

