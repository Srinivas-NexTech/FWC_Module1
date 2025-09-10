#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void) {
    DDRC = 0x0F;
    while(1){
        uint8_t val = (PIND>>2)&0x07;   // RQP
        PORTC = (PORTC & 0xF0) | val;
    }
}

