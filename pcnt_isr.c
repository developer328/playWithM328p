#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

volatile uint8_t val = 0;

int main(void){
	DDRB |= (1<<5);
	PCICR |= (1<<PCIE0);
	PCMSK0 |= (1<<PCINT0);
	SREG |= (1<<7);

	while(1){
		PORTB ^= (val<<5);
	}
	return 0;
}

ISR(PCINT0_vect){
	val = !val;
}
