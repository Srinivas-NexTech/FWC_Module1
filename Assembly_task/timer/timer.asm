; timer_logic.asm – ATmega328P (Arduino Uno)
; Function: F = m1+m2+m4+m7 evaluated inside Timer1 ISR
; Inputs: PB0=P, PB1=Q, PB2=R
; Output: PD7 (LED ON when F=1)

.include "m328pdef.inc"

.def temp   = r16
.def bits   = r17
.def result = r18

.org 0x0000
    rjmp RESET               ; Reset vector

.org 0x001A
    rjmp TIMER1_COMPA_ISR    ; Timer1 Compare Match A vector

; -------------------
; RESET
; -------------------
RESET:
    ; Inputs: PB0..PB2 as input
    cbi DDRB, 0
    cbi DDRB, 1
    cbi DDRB, 2

    ; Output: PD7
    sbi DDRD, 7

    ; ---- Timer1 setup ----
    ; Compare match at ~100ms (16MHz/1024 → 156.25 Hz)
    ; OCR1A = 15624/10 = 1562 for ~100ms
    ldi temp, high(1562)
    sts OCR1AH, temp
    ldi temp, low(1562)
    sts OCR1AL, temp

    ; CTC mode (WGM12 = 1)
    ldi temp, (1<<WGM12)
    sts TCCR1B, temp

    ; Prescaler = 1024
    ldi temp, (1<<CS12)|(1<<CS10)|(1<<WGM12)
    sts TCCR1B, temp

    ; Enable Timer1 Compare A interrupt
    ldi temp, (1<<OCIE1A)
    sts TIMSK1, temp

    sei                         ; enable global interrupts

MAIN:
    rjmp MAIN                   ; main loop idle

; -------------------
; ISR: TIMER1 COMPA
; -------------------
TIMER1_COMPA_ISR:
    ; Read inputs PB0..PB2
    in temp, PINB
    andi temp, 0x07       ; keep only PB0..PB2
    mov bits, temp

    ; Default F=0
    clr result

    ; Check for minterms 1,2,4,7
    cpi bits, 1
    breq SET_F
    cpi bits, 2
    breq SET_F
    cpi bits, 4
    breq SET_F
    cpi bits, 7
    breq SET_F
    rjmp UPDATE

SET_F:
    ldi result, 1

UPDATE:
    ; Drive LED
    tst result
    breq LED_OFF

LED_ON:
    sbi PORTD, 7
    reti

LED_OFF:
    cbi PORTD, 7
    reti
