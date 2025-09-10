; 7474.s - ATmega328P - compute f and pulse clock to latch into external 74xx74
.include "m328pdef.inc"

.def tmp = r16
.def a = r17
.def b = r18
.def c = r19

.org 0x00
    rjmp RESET

RESET:
    ; PB0 = D output, PB1 = clock output, PB2 optional read from 7474 Q (input)
    sbi DDRB, 0
    sbi DDRB, 1
    cbi DDRB, 2  ; PB2 as input to read Q (if connected)

    ; PD2..PD4 inputs
    cbi DDRD, 2
    cbi DDRD, 3
    cbi DDRD, 4

MAIN:
    in tmp, PIND
    andi tmp, 0x1C
    lsr tmp
    lsr tmp
    mov a, tmp       ; a bits: b0=P, b1=Q, b2=R

    ; extract P
    mov b, a
    andi b, 0x01     ; b = P
    ; extract Q
    mov c, a
    lsr c
    andi c, 0x01     ; c = Q
    ; compute b = P xor Q
    eor b, c
    ; extract R
    mov c, a
    lsr c
    lsr c
    andi c, 0x01
    ; final f = (P xor Q) xor R
    eor b, c         ; b now = f (0/1)

    ; drive D on PB0
    tst b
    breq D_ZERO
    sbi PORTB, 0
    rjmp DOCLK

D_ZERO:
    cbi PORTB, 0

DOCLK:
    ; pulse PB1 (CLK)
    sbi PORTB, 1
    nop
    nop
    cbi PORTB, 1

    ; optional: small delay
    ldi tmp, 50
DELAY:
    dec tmp
    brne DELAY

    rjmp MAIN
