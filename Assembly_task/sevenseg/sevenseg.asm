; sevenseg_CA_blink.s - ATmega328P
; Inputs: P=PB0, Q=PB1, R=PB2
; Segments -> PORTD: PD0=a .. PD6=g
; LED on PB5 blinks if F=1
; F = 1 for m1, m2, m4, m7

.include "m328pdef.inc"

.def temp   = r16
.def bits   = r17
.def idx    = r18
.def outval = r19

.org 0x00
    rjmp RESET

RESET:
    ; Setup: PD0..PD6 outputs for 7-seg
    ldi temp, 0x7F
    out DDRD, temp

    ; Inputs PB0..PB2
    cbi DDRB, 0
    cbi DDRB, 1
    cbi DDRB, 2

    ; LED on PB5 -> output
    sbi DDRB, 5

; 7-seg patterns (common anode, active LOW)
ldi r20, 0b1000000 ; "0"
ldi r21, 0b1111001 ; "1"
ldi r22, 0b0100100 ; "2"
ldi r23, 0b0110000 ; "3"
ldi r24, 0b0011001 ; "4"
ldi r25, 0b0010010 ; "5"
ldi r26, 0b0000010 ; "6"
ldi r27, 0b1111000 ; "7"

MAIN:
    in temp, PINB
    andi temp, 0x07      ; mask PB0..PB2
    mov bits, temp       ; store inputs (0..7)

    ; --- truth table: F=1 for m1,2,4,7 ---
    ldi outval, 0
    cpi bits, 1
    breq SETF
    cpi bits, 2
    breq SETF
    cpi bits, 4
    breq SETF
    cpi bits, 7
    breq SETF
    rjmp SHOW
SETF:
    ldi outval, 1

SHOW:
    ; select 7seg digit = just display input pattern
    cpi bits, 0
    breq OUT0
    cpi bits, 1
    breq OUT1
    cpi bits, 2
    breq OUT2
    cpi bits, 3
    breq OUT3
    cpi bits, 4
    breq OUT4
    cpi bits, 5
    breq OUT5
    cpi bits, 6
    breq OUT6
    rjmp OUT7

OUT0: mov idx, r20
      rjmp WRITE
OUT1: mov idx, r21
      rjmp WRITE
OUT2: mov idx, r22
      rjmp WRITE
OUT3: mov idx, r23
      rjmp WRITE
OUT4: mov idx, r24
      rjmp WRITE
OUT5: mov idx, r25
      rjmp WRITE
OUT6: mov idx, r26
      rjmp WRITE
OUT7: mov idx, r27

WRITE:
    out PORTD, idx     ; show digit

    ; blink LED if F=1
    tst outval
    breq LED_OFF
LED_ON:
    sbi PORTB, 5       ; LED high
    rcall DELAY
    cbi PORTB, 5       ; LED low
    rcall DELAY
    rjmp MAIN
LED_OFF:
    cbi PORTB, 5
    rjmp MAIN

; simple delay for LED blink
DELAY:
    ldi temp, 0xFF
L1: ldi idx, 0xFF
L2: dec idx
    brne L2
    dec temp
    brne L1
    ret
