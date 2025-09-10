#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRC = 0x0F;         // PC0..PC3 -> 7447 BCD inputs
    DDRB |= (1<<PB0);    // PB0 -> LED for f

    while (1) {
        uint8_t P = (PIND & (1<<PD2))?1:0;
        uint8_t Q = (PIND & (1<<PD3))?1:0;
        uint8_t R = (PIND & (1<<PD4))?1:0;

        uint8_t val = (R<<2)|(Q<<1)|P;   // RQP value
        PORTC = (PORTC & 0xF0) | (val & 0x0F); // Show on 7-seg via 7447

        uint8_t f = !(Q || R);   // corrected function

        if(f) PORTB |= (1<<PB0);
        else  PORTB &= ~(1<<PB0);

        _delay_ms(100);
    }
}
