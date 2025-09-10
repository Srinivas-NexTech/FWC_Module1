; memory.asm – ATmega328P
; Function: F = m1 + m2 + m4 + m7
; Inputs: PB0=P, PB1=Q, PB2=R
; Output: PD7 (LED)

.include "m328pdef.inc"

.def temp = r16
.def bits = r17
.def result = r18

.org 0x0000
    rjmp RESET

; -------------------
; Reset / Init
; -------------------
RESET:
    ; Set PB0..PB2 as inputs
    cbi DDRB, 0
    cbi DDRB, 1
    cbi DDRB, 2

    ; Set PD7 as output
    sbi DDRD, 7

    ; Init Z pointer to point to LUT in SRAM
    ldi r30, low(RAMTABLE)   ; ZL
    ldi r31, high(RAMTABLE)  ; ZH

MAIN:
    ; Read inputs PB0..PB2
    in temp, PINB
    andi temp, 0x07      ; mask PB0..PB2
    mov bits, temp       ; bits = 0..7

    ; Z = RAMTABLE + bits
    ldi r30, low(RAMTABLE)
    ldi r31, high(RAMTABLE)
    add r30, bits
    adc r31, r1          ; r1 is always zero

    ; Load F from LUT
    ld result, Z

    ; Output result to PD7
    cpi result, 0
    breq LED_OFF
LED_ON:
    sbi PORTD, 7
    rjmp MAIN

LED_OFF:
    cbi PORTD, 7
    rjmp MAIN

; -------------------
; LUT in SRAM
; Truth table: F = m1+m2+m4+m7
; Minterms: 1,2,4,7
; -------------------
RAMTABLE:
    .db 0 ; m0 -> F=0
    .db 1 ; m1 -> F=1
    .db 1 ; m2 -> F=1
    .db 0 ; m3 -> F=0
    .db 1 ; m4 -> F=1
    .db 0 ; m5 -> F=0
    .db 0 ; m6 -> F=0
    .db 1 ; m7 -> F=1

