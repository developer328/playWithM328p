/*
 * 16-MAR-2024
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void){
	DDRB = 0b100000;

	while(1){
		PORTB |= 0b100000;
		_delay_ms(100);
		PORTB &= ~0b100000;
		_delay_ms(100);
	}
	return 0;
}


