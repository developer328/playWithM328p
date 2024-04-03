/*
 * DOESN'T WORKS!!! :)
 */

#include <avr/io.h>
#define F_CPU 16000000UL 
#include <avr/interrupt.h>
//#include <util/delay.h>
/*
volatile uint8_t max = 0, min = 0;

int main(void){
	DDRD |= (1<<6);
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02) | (1<<CS00);
	TIMSK0 |= (1<<OCIE0A);
	TCNT0 = 0;
	OCR0A = 156;
	SREG |= (1<<7);

	while(1){
		PORTD |= (1<<6);
		for(volatile uint8_t h = 0; h <= max; h++){
		_delay_ms(1);
		}
		PORTD &= ~(1<<6);
		for(volatile uint8_t d = 0; d <= min; d++){
		_delay_ms(1);
		}

		max++;
		min = (20-max);
		if(max >= 20){
			max = 0;
		}
	}
	return 0;
}

ISR(TIMER0_COMPA_vect){
	PORTD |= (1<<6);
	_delay_ms(10);
	PORTD &= ~(1<<6);
	_delay_ms(10);
	OCR0A = 156;	
}



#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
*/
#define SERVO_PIN PD6

volatile uint16_t servo_pulse_width_us = 2000; // Initial pulse width for servo center position

int main(void) {
    // Set servo pin as output
    DDRD |= (1 << SERVO_PIN);

    // Timer/Counter 0 configuration for 50Hz PWM signal
    TCCR0A |= (1 << WGM01); // Set CTC mode
    TCCR0B |= (1 << CS01) | (1 << CS00); // Set prescaler to 64
    OCR0A = 249; // Set TOP value for 50Hz frequency (16000000Hz / (64 * 50Hz) - 1)

    // Enable Timer/Counter 0 output compare match A interrupt
    TIMSK0 |= (1 << OCIE0A);

    // Enable global interrupts
    sei();

    while (1) {
        /* You can modify servo_pulse_width_us here to change servo position
   	servo_pulse_width_us += 1;
	if(servo_pulse_width_us >= 2000){
		servo_pulse_width_us = 1000; 
	}
	_delay_ms(15);*/
    }
    
    return 0;
}

ISR(TIMER0_COMPA_vect) {
    // Toggle servo pin
    PORTD ^= (1 << SERVO_PIN);

    // Set the next compare match value for the desired pulse width
    OCR0B = (uint8_t)(servo_pulse_width_us / 64) - 1;
}
