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

#define MAX 150
#define MIN 30

volatile uint8_t val = 0;

int main(void){
//	cli();
	DDRD |= (1<<6);
	TCCR0A = 0b10000011;//(1<<COM0A0) | (0<<COM0A1) | (1<<WGM00) | (1<<WGM01);
	TCCR0B = 0b00000100;//(1<<WGM02) | (1<<CS02);// | (1<<CS00);
//	TIMSK0 |= (1<<TOIE0);
	TCNT0 = 0;
//	SREG |= (1<<7);
	sei();

	while(1){
		//TCCR0A = 0b10000011;
		for(val = MIN; val <= MAX; val++){
			OCR0A = val;
			_delay_ms(15);
		}
		for(val = MAX; val >= MIN; val--){
			OCR0A = val;
			_delay_ms(15);
		}
	}
	return 0;
}

