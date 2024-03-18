#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t val = 1;

int main(void){
	cli();
	DDRB |= (1<<5);
	DDRD |= (1<<2);
	EICRA |= (1<<ISC01) | (1<<ISC00);
	EIMSK |= (1<<INT0);
	sei();

	while(1){
		_delay_ms(200);
		PORTB = (val<<5);	
	}
	return 0;
}

ISR(INT0_vect){
	val = !val;	
}
