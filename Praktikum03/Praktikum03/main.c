/*
 * Praktikum03.c
 *
 * Created: 29/11/2021 08:37:07
 * Author : haypsilcn
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include <avr/interrupt.h>

#define LED PIND0

volatile uint32_t systemClk = 0;

void setUp_Timer0() {
	TCCR0A = (1 << WGM01);					// enable CTC mode of Timer/Counter 0 Control Register A
	TCCR0B |= (1 << CS01) | (1 << CS00);	// set Prescaler 64 
	OCR0A = 249;							// set up Output Comparison Register A for Timer0 to generate an interrupt when timer counter and OCR0A are equals
											// F_TimerInterrupt = F_clk / ( (prescaler) x (OCR + 1) )
											// => OCR = F_clk / (F_TimerInterrupt x prescaler) - 1 = ( 16MHz/(1000Hz x 64) ) - 1 = 249
	TIMSK0 = (1 << OCIE0A);					// enable interrupt
}

ISR(TIMER0_COMPA_vect) {
	systemClk++;
}

void waitFor(uint32_t ms) {
	uint32_t currentTime = systemClk + ms;
	while (systemClk < currentTime) {} 		
}

void waitUntil(uint32_t ms) {
	while (systemClk <= ms) {}
}

int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xff;							// Data direction register D (D0) as output
	PORTD = 0x00;
	setUp_Timer0();
	sei();									// set global interrupt enable
	
	waitUntil(5000);						// wait until 5s from the beginning then turn on LED
	PORTD |= (1 << LED);					// setting bit for LED
    while (1) 
    {
		waitFor(200);						// wait for 0.2s then toggle LED
		PORTD ^= (1 << LED);				// toggling LED
    }
}



