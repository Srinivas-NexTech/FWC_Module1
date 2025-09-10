; 7447.s - ATmega328P - output RQP to 7447 BCD inputs on PC0..PC3
.include "m328pdef.inc"

.def tmp = r16
.def val = r17

.org 0x00
    rjmp RESET

RESET:
    ; PC0..PC3 outputs
    ldi tmp, 0x0F
    out DDRC, tmp
    ; PD2..PD4 inputs
    cbi DDRD, 2
    cbi DDRD, 3
    cbi DDRD, 4

MAIN:
    in tmp, PIND
    andi tmp, 0x1C
    ; shift right twice so PD2->b0 etc.
    lsr tmp
    lsr tmp
    mov val, tmp
    ; write to PC0..PC3 (preserve PC4..PC7)
    in tmp, PORTC
    andi tmp, 0xF0
    ori val, 0x00
    or tmp, val
    out PORTC, tmp
    rjmp MAIN
