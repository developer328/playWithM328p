/*
 * 7-APR-2024
 * Purpose: Read from uart and send back
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

char data = 0;
char First[6] = {'H', 'e', 'l', 'l', 'o', '!'};

int main(void){
	DDRB |= (1<<5);
	PORTB &= ~(1<<5);

	cli();
	UCSR0A |= 0;
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
	UBRR0 = 103;
	sei();
	
	for(uint8_t i = 0; i < 6; i++){
		while(!(UCSR0A & (1<<UDRE0)))
		;

		UDR0 = First[i];
	}

	while(1){
		
		while(!(UCSR0A & (1<<RXC0)))
		;

		data = UDR0;	


		while(!(UCSR0A & (1<<UDRE0)))
		;

		UDR0 = data;

		
		_delay_ms(10);
	}
	return 0;
}
