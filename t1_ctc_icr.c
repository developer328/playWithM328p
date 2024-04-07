/*
 * 4-APR-2024
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t icr_led = 0, ovf_led = 0;

int main(void){
	DDRB |= (1<<1) | (1<<5);
	TCCR1A |= (1<<WGM13) | (1<<WGM12);
	TCCR1B |= (1<<CS11) | (1<<CS10) | (1<<ICNC1);
	TIMSK1 |= (1<<ICIE1) | (1<<TOIE1);
	TCNT1 = 0;
	SREG |= (1<<7);
	
	while(1){
		_delay_ms(200);
	}
	return 0;
}


ISR(TIMER1_CAPT_vect){
	icr_led = !icr_led;
	PORTB = (icr_led<<5) | (PORTB & ~(1<<5));
}

ISR(TIMER1_OVF_vect){
	ovf_led = !ovf_led;
	PORTB = (ovf_led<<1) | (PORTB & ~(1<<1));
}
