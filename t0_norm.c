/*
 * 22-MAR-2024
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t val = 0;

int main(void){
	DDRB |= (1<<5) | (1<<1);
	TCCR0A = 0;
	TCCR0B |= (1<<CS02) | (1<<CS00);
	TIMSK0 |= (1<<TOIE0);
	TCNT0 = 0;
	SREG |= (1<<7);
	
	while(1){
		PORTB = (1<<1) | (PORTB & ~(1<<1));
		_delay_ms(1000);
		PORTB &= ~(1<<1);
		_delay_ms(1000);
	}
	return 0;
}

ISR(TIMER0_OVF_vect){
	val = !val;
	PORTB = (val<<5) | (PORTB & ~(1<<5));	
}
