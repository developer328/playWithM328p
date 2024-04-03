/*
 * 4-APR-2024
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){
	DDRB |= (1<<1) | (1<<5);
	TCCR1A |= (1<<COM1A0) | (1<<WGM12);
	TCCR1B |= (1<<CS11) | (1<<CS10);
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 62000;
	TCNT1 = 0;
	SREG |= (1<<7);
	
	while(1){
		PORTB |= (1<<5);
		_delay_ms(200);
		PORTB = (PORTB & ~(1<<5));
		_delay_ms(200);
	}
	return 0;
}


ISR(TIMER1_COMPA_vect){
	/*nothing*/
}
