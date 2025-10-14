#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int A, B, C;
int F;

void setup() {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);

    lcd.begin(16, 2);   // 16x2 LCD
    lcd.print("K-map Demo");
    delay(1000);
    lcd.clear();
}

void loop() {
    A = digitalRead(2); // MSB
    B = digitalRead(3);
    C = digitalRead(4); // LSB

    // Minimized expression from K-map
    F = C;  

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("A=");
    lcd.print(A);
    lcd.print(" B=");
    lcd.print(B);
    lcd.print(" C=");
    lcd.print(C);

    lcd.setCursor(0, 1);
    lcd.print("F = ");
    lcd.print(F);

    delay(500);
}
