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

#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))

void init();


#endif /* KEYS_H_ */