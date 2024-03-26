//CTC

/*
 * 26-MAR-2024
 * 27-MAR-2024 - toggle pin6 on timer0
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t Lval = 0, B_flag = 0, M_flag = 0;

int main(void){
	DDRB |= (1<<5);// | (1<<1);
	DDRD |= (1<<6);
	TCCR0A |= (1<<WGM01) | (1<<COM0A0);
	TCCR0B |= (1<<CS02) | (1<<CS00);
	TIMSK0 |= (1<<OCIE0A);
	OCR0A = 0;
	TCNT0 = 0;
	SREG |= (1<<7);

	while(1){
		PORTB = (1<<5) | (PORTB & ~(1<<5));
		_delay_ms(500);
		PORTB &= ~(1<<5);
		_delay_ms(500);
	}
	return 0;
}

ISR(TIMER0_COMPA_vect){
//	Lval = !Lval;
//	PORTB = (Lval<<1) | (PORTB & ~(1<<1));

	if(OCR0A >= 255){
		B_flag = 0;
		M_flag = 1;
	}else if(OCR0A <= 0){
		M_flag = 0;
		B_flag = 1;
	}
	if(M_flag == 1){
		OCR0A -= 1;
	}else if(B_flag == 1){
		OCR0A += 1;	
	}
}
