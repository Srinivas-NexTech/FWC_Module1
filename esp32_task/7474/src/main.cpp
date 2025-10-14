#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
}

void loop() {
  int P = digitalRead(4);
  int Q = digitalRead(16);
  int R = digitalRead(17);

  int F = (!P && !Q && R) || (!P && Q && !R) || (P && !Q && !R) || (P && Q && R);

  digitalWrite(2, F);

  digitalWrite(5, HIGH);
  delay(50);
  digitalWrite(5,LOW);
  delay(50);
}
