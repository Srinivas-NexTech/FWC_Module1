#include<Arduino.h>
#define LCD_RS 9
#define LCD_E 8
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

void lcd_pulse_enable() {
    digitalWrite(LCD_E, HIGH);
    delayMicroseconds(1);
    digitalWrite(LCD_E, LOW);
    delayMicroseconds(100);
}

void lcd_write4bits(uint8_t data) {
    digitalWrite(LCD_D4, (data >> 0) & 0x01);
    digitalWrite(LCD_D5, (data >> 1) & 0x01);
    digitalWrite(LCD_D6, (data >> 2) & 0x01);
    digitalWrite(LCD_D7, (data >> 3) & 0x01);
    lcd_pulse_enable();
}

void lcd_send(uint8_t value, uint8_t mode) {
    digitalWrite(LCD_RS, mode);
    lcd_write4bits(value >> 4);   // Send high nibble
    lcd_write4bits(value & 0x0F); // Send low nibble
}

void lcd_init() {
    pinMode(LCD_RS, OUTPUT);
    pinMode(LCD_E, OUTPUT);
    pinMode(LCD_D4, OUTPUT);
    pinMode(LCD_D5, OUTPUT);
    pinMode(LCD_D6, OUTPUT);
    pinMode(LCD_D7, OUTPUT);

    delay(50); // Power up
    lcd_send(0x33, 0); // Initialization
    lcd_send(0x32, 0); // Set to 4-bit mode
    lcd_send(0x28, 0); // Function set: 2 Line, 4-bit, 5x8 dots
    lcd_send(0x0C, 0); // Display on, cursor off
    lcd_send(0x06, 0); // Entry mode
    lcd_send(0x01, 0); // Clear display
    delay(2);
}

void lcd_print(const char* str) {
    while (*str) {
        lcd_send(*str++, 1); // Send data
    }
}

void setup() {
    lcd_init();
    lcd_print("Hello LCD NoLib!");
}

void loop() {}
