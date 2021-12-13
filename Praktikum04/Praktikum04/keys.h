/*
 * keys.h
 *
 * Created: 12/12/2021 07:25:56
 *  Author: haypsilcn
 */ 


#ifndef KEYS_H_
#define KEYS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))		// Test whether bit 'bit' in IO register 'sfr' is clear. This will return non-zero if the bit is clear, and a 0 if the bit is set.

void init();


#endif /* KEYS_H_ */