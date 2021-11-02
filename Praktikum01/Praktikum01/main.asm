;
; Praktikum01.asm
;
; Created: 02/11/2021 06:57:35
; Author : haypsilcn
;


; Replace with your application code
.include "m328pdef.inc"

.org 0x000
rjmp		start

start:
	ldi		r16, LOW(RAMEND)			; Stack einrichten für Befehle
	out		SPL, r16
	ldi		r16, HIGH(RAMEND)
	out		SPH, r16

	ldi		r17, 0b1111_1111
	out		DDRD, r17					; Data direction register D (D0-D7) as output
	ldi		r17, 0b0000_0001			; fängt mit Led D0 ein

	ldi		r18, 0b0000_0011
	out		DDRB, r18					; Data direction register B (B0-B1) as output

left_shift:								; Led läuft nach links
	out		PORTD, r17					; D0 leutet
	rcall	delay
	lsl		r17
	cpi		r17, 0b0000_0000			
	brne	left_shift					; weiter nach links verschieben, ob D7 noch nicht leutet

	out		PORTD, r17					; wenn D7 erreicht, schaltet Port D aus
	ldi		r18, 0b0000_00001
	out		PORTB, r18					; D8 leutet
	rcall	delay
	lsl		r18

portB_shift:							; Led läuft weiter
	out		PORTB, r18
	rcall	delay
	lsr		r18
	cpi		r18, 0b0000_0000
	brne	portB_shift

	out		PORTB, r18					
	ldi		r17, 0b1000_0000

right_shift:							; Led läuft nach rechts
	out		PORTD, r17
	rcall	delay
	lsr		r17
	cpi		r17, 0b0000_0001			; mit D0 vergleichen
	brne	right_shift					; weiter nach rechts verschieben, wenn D0 noch nicht erreicht
	jmp		left_shift					; sonst läuft Led nach links

delay:
    ldi  r19, 17
    ldi  r20, 60
    ldi  r21, 204

L1: dec  r21                   
    brne L1                    
    dec  r20                   
    brne L1                     
    dec  r19                    
    brne L1                     
    ret
