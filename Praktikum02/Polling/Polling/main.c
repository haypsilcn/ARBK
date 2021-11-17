/*
 * Polling.c
 *
 * Created: 17/11/2021 04:55:34
 * Author : haypsilcn
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdbool.h>								// boolean type and values

#define LED00 PIND0
#define LED09 PIND1

#define SWITCH01 PINB0
#define SWITCH02 PINB1

int on = LED00;
int off = LED09;
bool blink = true;

void setupPorts() {
	DDRD = 0xff;										// Data direction register D (D0 & D1) as output
	PORTD = 0x00;		
	
	DDRB = 0x00;										// Data direction register B (B0 & B1) as input
	PORTB = 0xff;		
}

void pressButton() {
	if ( !(PINB & (1 << SWITCH01)) ) {
		_delay_ms(5);
		if ( !(PINB & (1 << SWITCH01)) ) {				// SW1 is pressed
			if (PIND & (1 << LED00)) {					// if D0 is on
				blink ^= (1 << 0);						// toggle D0 from blinking to steady light or vice versa
			} else if (PIND & (1 << LED09)) {			// if D9 is on then switch to D0
				off = LED09;						
				on = LED00;
			}
		}
	}
	
	if ( !(PINB & (1 << SWITCH02)) ) {
		_delay_ms(5);
		if ( !(PINB & (1 << SWITCH02))) {				// SW2 is pressed
			if (PIND & (1 << LED09)) {					// if D9 is on
				blink ^= (1 << 0);						// toggle D9 from blinking to steady light or vice versa
			} else if ( (PIND & (1 << LED00))) {		// if D0 is on then switch to D9
				off = LED00;
				on = LED09;
			}
		}
	}
}

int main(void)
{
    /* Replace with your application code */
	setupPorts();
    while (1) 
    {
		pressButton();
		if (blink) {
			PORTD &= ~(1UL << off);
			PORTD ^= (1 << on);
		} 
		else {
			PORTD &= ~(1UL << off);
			PORTD |= ( 1 << on);
		}
		_delay_ms(200);
    }
}

