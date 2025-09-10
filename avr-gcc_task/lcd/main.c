/*
  AVR program for ATmega328P (Arduino Uno)
  - Inputs: P -> PD2, Q -> PD3, R -> PD4  (R is MSB, P LSB)
  - 7-seg (via 7447 BCD driver): PC0..PC3 -> A,B,C,D (BCD)
  - Drive LED f on PB0  (f = (P+Q+R)')
  - Pulse 7474 clock pins PD5, PD6 (optional external FF latch)
  - LCD 16x2 (HD44780) in 4-bit mode: RS PB1, EN PB2, D4..D7 PB3..PB6
  - FSM: cycles through states reading inputs and showing result
  - Compile: avr-gcc -mmcu=atmega328p -Os main.c -o main.elf
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/* ---------- LCD low-level (4-bit) ---------- */
/* LCD pins mapping */
#define LCD_RS_PORT PORTB
#define LCD_RS_DDR  DDRB
#define LCD_RS_PIN  (1)   // PB1

#define LCD_EN_PORT PORTB
#define LCD_EN_DDR  DDRB
#define LCD_EN_PIN  (2)   // PB2

#define LCD_DATA_PORT PORTB
#define LCD_DATA_DDR  DDRB
// PB3..PB6 -> D4..D7

static void lcd_pulse_en(void) {
    LCD_EN_PORT |= (1 << LCD_EN_PIN);
    _delay_us(2);
    LCD_EN_PORT &= ~(1 << LCD_EN_PIN);
    _delay_us(50);
}

static void lcd_write4(uint8_t nibble) {
    // nibble is lower 4 bits -> D4..D7
    // Clear PB3..PB6
    LCD_DATA_PORT &= ~((1<<3)|(1<<4)|(1<<5)|(1<<6));
    // Put bits
    if (nibble & 0x01) LCD_DATA_PORT |= (1<<3);
    if (nibble & 0x02) LCD_DATA_PORT |= (1<<4);
    if (nibble & 0x04) LCD_DATA_PORT |= (1<<5);
    if (nibble & 0x08) LCD_DATA_PORT |= (1<<6);
    lcd_pulse_en();
}

static void lcd_cmd(uint8_t cmd) {
    LCD_RS_PORT &= ~(1 << LCD_RS_PIN);
    lcd_write4(cmd >> 4);
    lcd_write4(cmd & 0x0F);
    _delay_ms(2);
}

static void lcd_data(uint8_t d) {
    LCD_RS_PORT |= (1 << LCD_RS_PIN);
    lcd_write4(d >> 4);
    lcd_write4(d & 0x0F);
    _delay_ms(2);
}

static void lcd_init(void) {
    // Configure LCD pins as outputs
    LCD_RS_DDR |= (1<<LCD_RS_PIN);
    LCD_EN_DDR |= (1<<LCD_EN_PIN);
    LCD_DATA_DDR |= (1<<3)|(1<<4)|(1<<5)|(1<<6);

    _delay_ms(40);
    // Initialize 4-bit mode
    LCD_RS_PORT &= ~(1<<LCD_RS_PIN);
    // According to HD44780 init sequence
    lcd_write4(0x03);
    _delay_ms(5);
    lcd_write4(0x03);
    _delay_us(150);
    lcd_write4(0x03);
    lcd_write4(0x02); // 4-bit mode
    // Function set: 4-bit, 2-line, 5x8 dots
    lcd_cmd(0x28);
    // Display on, cursor off
    lcd_cmd(0x0C);
    // Clear
    lcd_cmd(0x01);
    _delay_ms(2);
    // Entry mode
    lcd_cmd(0x06);
}

static void lcd_puts(const char *s) {
    while (*s) lcd_data(*s++);
}

static void lcd_goto(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x00 : 0x40;
    addr += col;
    lcd_cmd(0x80 | addr);
}

/* ---------- Utility ---------- */
static void pulse_7474_clk1(void) {
    // PD5 as clock (active rising edge)
    PORTD |= (1<<PD5);
    _delay_us(5);
    PORTD &= ~(1<<PD5);
    _delay_us(5);
}

static void pulse_7474_clk2(void) {
    PORTD |= (1<<PD6);
    _delay_us(5);
    PORTD &= ~(1<<PD6);
    _delay_us(5);
}

/* ---------- Main ---------- */
int main(void) {
    // Configure PD2,PD3,PD4 as inputs (P,Q,R)
    DDRD &= ~((1<<PD2)|(1<<PD3)|(1<<PD4));

    // Make sure clock lines PD5,PD6 are outputs (for pulsing 7474)
    DDRD |= (1<<PD5)|(1<<PD6);
    PORTD &= ~((1<<PD5)|(1<<PD6));

    // 7-seg via 7447: outputs on PC0..PC3
    // Configure PC0..PC3 as outputs
    DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3);

    // PB0 as output for f LED
    DDRB |= (1<<PB0);

    // LCD init
    lcd_init();

    // Header on LCD
    lcd_goto(0,0);
    lcd_puts("Inputs:RQP Val:f");
    _delay_ms(800);

    while (1) {
        // Read pins (expect direct 5V or GND connected)
        uint8_t P = (PIND & (1<<PD2)) ? 1 : 0;
        uint8_t Q = (PIND & (1<<PD3)) ? 1 : 0;
        uint8_t R = (PIND & (1<<PD4)) ? 1 : 0;

        // Optionally pulse 7474 clocks so external D-FFs latch the current inputs
        pulse_7474_clk1();
        pulse_7474_clk2();

        // BCD value (RQP) where R is MSB -> value 0..7
        uint8_t bcd = (R<<2) | (Q<<1) | (P<<0);
        // Put to PC0..PC3 (D is 0)
        PORTC = (PORTC & 0xF0) | (bcd & 0x0F);  // preserve upper nibble

        // Compute f = (P+Q+R)'
        uint8_t f = !(P || Q || R);

        // Drive LED on PB0
        if (f) PORTB |= (1<<PB0);
        else    PORTB &= ~(1<<PB0);

        // Show on LCD: second row
        char buf[17];
        // Format: R Q P  val f
        // Build small string
        lcd_goto(1,0);
        // create "RQP=xyz f=x"
        // convert digits
        buf[0] = 'R';
        buf[1] = '=';
        buf[2] = (R ? '1':'0');
        buf[3] = ' ';
        buf[4] = 'Q';
        buf[5] = '=';
        buf[6] = (Q ? '1':'0');
        buf[7] = ' ';
        buf[8] = 'P';
        buf[9] = '=';
        buf[10] = (P ? '1':'0');
        buf[11] = ' ';
        buf[12] = 'v'; buf[13] = '='; buf[14] = '0' + bcd;
        buf[15] = ' ';
        buf[16] = '\0';
        // print left 16 chars
        lcd_puts(buf);
        // print f separately (so user sees f)
        lcd_goto(1,12);
        lcd_puts("f=");
        lcd_data(f ? '1' : '0');

        _delay_ms(800);
    }

    return 0;
}

/*
  K-map comment & simplification (for your record):
  - Function f = (P + Q + R)' => only 1 when P=Q=R=0 else 0
  - K-map yields single minterm m0 (P'Q'R'), others are zeros; no don't-cares used here.
  - FSM used: simple cycle through observed states; you may expand to state machine
    to test sequences, glitch testing, or debouncing.
*/

