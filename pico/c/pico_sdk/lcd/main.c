#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LCD_RS 6
#define LCD_E  7
#define DAT4   8
#define DAT5   9
#define DAT6   10
#define DAT7   11

// Pulse enable
static void PulseEnableLine() {
    gpio_put(LCD_E, 1);
    sleep_us(2);
    gpio_put(LCD_E, 0);
    sleep_us(50);
}

// Send 4 bits
static void SendNibble(uint8_t data) {
    gpio_put(DAT4, (data & (1<<4)) ? 1 : 0);
    gpio_put(DAT5, (data & (1<<5)) ? 1 : 0);
    gpio_put(DAT6, (data & (1<<6)) ? 1 : 0);
    gpio_put(DAT7, (data & (1<<7)) ? 1 : 0);
    PulseEnableLine();
}

// Send full byte
static void SendByte(uint8_t data) {
    SendNibble(data & 0xF0);
    SendNibble((data & 0x0F) << 4);
}

void LCD_Cmd(uint8_t cmd) {
    gpio_put(LCD_RS, 0);
    SendByte(cmd);
    sleep_ms(2);
}

void LCD_Char(uint8_t ch) {
    gpio_put(LCD_RS, 1);
    SendByte(ch);
    sleep_ms(2);
}

void LCD_Init() {
    gpio_put(LCD_RS, 0);
    gpio_put(LCD_E, 0);
    gpio_put(DAT4, 0);
    gpio_put(DAT5, 0);
    gpio_put(DAT6, 0);
    gpio_put(DAT7, 0);
    sleep_ms(50);

    LCD_Cmd(0x33);
    LCD_Cmd(0x32);
    LCD_Cmd(0x28);   // 4-bit, 2 line, 5x7
    LCD_Cmd(0x0C);   // display on, cursor off
    LCD_Cmd(0x06);   // entry mode
    LCD_Cmd(0x01);   // clear display
    sleep_ms(3);
}

void LCD_Clear() {
    LCD_Cmd(0x01);
    sleep_ms(3);
}

void LCD_Message(const char *text) {
    while (*text) {
        LCD_Char((uint8_t)*text++);
    }
}

void LCD_Integer(int data) {
    char st[8];
    snprintf(st, sizeof(st), "%d", data);
    LCD_Message(st);
}

int main() {
    int X, Y, Z, f;

    // Initialize GPIO pins
    gpio_init(LCD_RS); gpio_set_dir(LCD_RS, true);
    gpio_init(LCD_E);  gpio_set_dir(LCD_E, true);
    gpio_init(DAT4);   gpio_set_dir(DAT4, true);
    gpio_init(DAT5);   gpio_set_dir(DAT5, true);
    gpio_init(DAT6);   gpio_set_dir(DAT6, true);
    gpio_init(DAT7);   gpio_set_dir(DAT7, true);

    // Inputs: GPIO 2,3,4
    gpio_init(2); gpio_set_dir(2, false);
    gpio_init(3); gpio_set_dir(3, false);
    gpio_init(4); gpio_set_dir(4, false);

    LCD_Init();
    LCD_Clear();

    while (1) {
        X = gpio_get(2);
        Y = gpio_get(3);
        Z = gpio_get(4);

        f = ((!X && !Y) || (Y && Z));

        LCD_Clear();
        LCD_Message("X="); LCD_Integer(X);
        LCD_Message(" Y="); LCD_Integer(Y);
        LCD_Message(" Z="); LCD_Integer(Z);

        LCD_Cmd(0xC0);  // move to second line
        LCD_Message("f = "); LCD_Integer(f);

        sleep_ms(500);
    }

    return 0;
}

