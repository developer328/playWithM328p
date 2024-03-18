/*
 * 16-MAR-2024
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void){
	DDRB |= 0b100000;
	//PORTB |= 0b000001;//internal pull-up 
	while(1){
		if(PINB & 0b000001){
			PORTB |= 0b100000;
		}else{
			PORTB &= ~0b100000;
		}
	}
	return 0;
}
