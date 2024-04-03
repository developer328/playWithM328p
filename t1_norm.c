/*
 * 3-APR-2024
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t val = 0;

int main(void){
	DDRB |= (1<<5);
	TCCR1A |= 0;


//	TCCR1B |= (1<<CS11); 

	/* 16000000hz/8 = 2000000hz
	 * 1/2000000hz*65535 = 0.032s(32ms)
	 */


//	TCCR1B |= (1<<CS11) | (1<<CS10);

	/* 16000000hz/64 = 250000hz 
	 * 1/250000hz*65535 = 0.262s(262ms)
	 */


 	TCCR1B |= (1<<CS12);

	/* 16000000hz/256 = 62500hz
	 * 1/62500hz*65535 = 1.048s
	 */


//	TCCR1B |= (1<<CS12) | (1<<CS10);

	/* 16000000hz/1024 = 15624hz
	 * 1/15625hz*65535 = 4.194s
	 */

	TIMSK1 |= (1<<TOIE0);
	SREG |= (1<<7);	

	while(1){
		_delay_ms(1000);
	}
	return 0;
}

ISR(TIMER1_OVF_vect){
	val = !val;
	PORTB = (val<<5) | (PORTB & ~(1<<5));
}
