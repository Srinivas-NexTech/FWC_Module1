#include <Arduino.h>
#include <LiquidCrystal.h>

// Initialize LCD: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 14, 27, 26,25);  // Update pins according to your wiring

void setup() {
  pinMode(4, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);

  lcd.begin(16, 2);       // 16 columns, 2 rows
  lcd.print("F = ");      // Static text
}

void loop() {
  int P = digitalRead(4);
  int Q = digitalRead(16);
  int R = digitalRead(17);

  // XOR / parity logic
  int F = (!P && !Q && R) || (!P && Q && !R) || (P && !Q && !R) || (P && Q && R);

  // Move cursor and display F
  lcd.setCursor(0, 0);// Column 4, row 0
  lcd.print("P Q R:");
  lcd.setCursor(8,0);
  lcd.print(P);
  lcd.setCursor(9,0);
  lcd.print(Q);
  lcd.setCursor(10,0);
  lcd.print(R);
  lcd.setCursor(0,1);
  lcd.print("F:");
  lcd.setCursor(4,1);
  lcd.print(F);

  delay(100);  // Small delay to avoid flicker
  lcd.clear();
}
