.include "m328Pdef.inc"

; Setup
ldi r16, 0b11111100      ; PD2–PD7 as output
out DDRD, r16

ldi r16, 0b00000001      ; PB0 as output
out DDRB, r16

LoopDigits:
   ; Display 0
    ldi r17, 0b00000011
    out PORTD, r17
ldi r16,0b00000001
out PORTB,r16
    rcall Delay

    ; Display 1
    ldi r17, 0b11100111
    out PORTD, r17
ldi r16,0b00000001
out PORTB,r16
    rcall Delay

    ; Display 2
    ldi r17, 0b10010011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 3
    ldi r17, 0b11000011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 4
    ldi r17, 0b01100111
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 5
    ldi r17, 0b01001011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 6
    ldi r17, 0b00001011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 7
    ldi r17, 0b11100011
    out PORTD, r17
ldi r16,0b00000001
out PORTB,r16
    rcall Delay

    ; Display 8
    ldi r17, 0b00000011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    ; Display 9
    ldi r17, 0b01000011
    out PORTD, r17
ldi r16,0b00000000
out PORTB,r16
    rcall Delay

    rjmp LoopDigits

; Long Delay Routine
Delay:
    ldi r18, 0xFF        ; Outer loop
DelOuter:
    ldi r19, 0xFF        ; Middle loop
DelMiddle:
    ldi r20, 0xFF        ; Inner loop
DelInner:
    dec r20
    brne DelInner
    dec r19
    brne DelMiddle
    dec r18
    brne DelOuter
    ret
