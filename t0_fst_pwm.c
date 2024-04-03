/*
 * 27-MAR-2024
 * Doesn't works
 * 29-MAR-2024
 * Works incorrectly
 * 1-APR-2024
 * Works
 */

#include <avr/io.h>
#define F_CPU 16000000L 
#include <avr/interrupt.h>
#include <util/delay.h>

#define MAX 255
#define MIN 0

volatile uint16_t val = 0;

int main(void){
	DDRD |= (1<<6);
	TCCR0A |= (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);
	TCCR0B |= (1<<CS01) | (1<<CS00);
	TCNT0 = 0;
	SREG |= (1<<7);

	while(1){
		for(val = MIN; val <= MAX; val++){
			OCR0A = val;
			_delay_ms(15);
		}
		for(val = MAX; val >= MIN; val--){
			OCR0A = val;
			_delay_ms(20);
		}
	}
	return 0;
}

