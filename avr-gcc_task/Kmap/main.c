#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD &= ~((1<<PD2) | (1<<PD3));
    DDRB |= (1<<PB0);

    while(1) {
        uint8_t Q = (PIND & (1<<PD2))?1:0;
        uint8_t R = (PIND & (1<<PD3))?1:0;

        uint8_t f = !(Q||R);

        if(f) PORTB |= (1<<PB0); else PORTB &= ~(1<<PB0);
    }
}

