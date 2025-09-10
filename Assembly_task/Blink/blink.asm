; ATmega328P Assembly - f = P XOR Q XOR R -> LED on PB0
.include "m328pdef.inc"

.org 0x00
rjmp RESET

RESET:
    ; Set PB0 as output
    sbi DDRB, 0
    ; Set PD2,PD3,PD4 as inputs
    cbi DDRD, 2
    cbi DDRD, 3
    cbi DDRD, 4

MAIN:
    ; Read inputs
    in r16, PIND
    lsr r16            ; shift PD2 -> carry
    lsr r16            ; now PD2 in C
    mov r17, r16
    andi r17, 0x01     ; P = bit2
    mov r18, r16
    andi r18, 0x02     ; Q = bit3
    lsr r18
    mov r19, r16
    andi r19, 0x04     ; R = bit4
    lsr r19
    lsr r19

    ; f = P XOR Q XOR R
    eor r17, r18
    eor r17, r19

    ; Output to PB0
    cpi r17, 0
    breq LED_OFF
    sbi PORTB, 0
    rjmp MAIN

LED_OFF:
    cbi PORTB, 0
    rjmp MAIN

