#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
enum state {S0,S1,S2,S3,S4,S5,S6,S7};
enum state current;
int main(void){
    DDRB |= (1<<PB0);
    while(1){
        uint8_t val = (PIND>>2)&0x07; // RQP
        current = (enum state)val;

        switch(current){
            case S0: // 000 => f=1
            case S1: // 001 => f=1 (P=1, Q=0,R=0)
                PORTB |= (1<<PB0);
                break;
            default: // others => f=0
                PORTB &= ~(1<<PB0);
                break;
        }
    }
}
