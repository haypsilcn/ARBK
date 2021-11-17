/*
 * Interrupt.c
 *
 * Created: 17/11/2021 04:59:03
 * Author : haypsilcn
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>										// boolean type and values

#define LED00 PINB0
#define LED09 PINB1
#define SWITCH01 PIND2
#define SWITCH02 PIND3

volatile int on = LED00;
volatile bool blink = true;

void setupPorts() {
	DDRB = 0xff;											// Data direction register B (B0 & B1) as output
	PORTB = 0x00;
	
	DDRD = 0x00;											// Data direction register D (D0 & D1) as input
	PORTD |= (1 << SWITCH01) | (1 << SWITCH02);				// setting bit for switch
	cli();													// clear global interrupt flag: interrupts will be immediately disabled
	EICRA |= (1 << ISC11) | (1 << ISC01);					// the falling edge of INT1 or INT0 generates an interrupt request.
	EIMSK = (1 << INT0) | (1 << INT1);						// enable external interrupt request
	sei();													// set global interrupt enable
}

ISR(INT0_vect) {
	if (on == LED00) {										// if D0 is already on, switching from blink to steady light or vice versa
		blink = !blink;
	} else {												// else D9 is on, turn off D9 and turn on D0
		PORTB = (1 << LED00);
	}
	on = LED00;
}

ISR(INT1_vect) {
	if (on == LED09) {
		blink = !blink;
	} else {
		PORTB = (1 << LED09);
	}
	on = LED09;
}


int main(void)
{
	/* Replace with your application code */
	setupPorts();
	while(1){
		if (blink) {
			PORTB ^= (1 << on);
		} else {
			PORTB = (1 << on);
		}
		_delay_ms(200);
	}
}