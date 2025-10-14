#include <Arduino.h>

void disp_7447(int D,int C,int B,int A)
{
  digitalWrite(13, A); 
  digitalWrite(12, B); 
  digitalWrite(14, C); 
  digitalWrite(27, D);
}

void setup() {
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(4, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
}

void loop() {
  int P = digitalRead(4);
  int Q = digitalRead(16);
  int R = digitalRead(17);

  int F = (!P && !Q && R) || (!P && Q && !R) || (P && !Q && !R) || (P && Q && R);

  if (F == 1)
  {
    disp_7447(0,0,0,1);   // example pattern for “something like 1”
  }
  else
  {
    disp_7447(0,0,0,0);   // all off except g segment
  }
}
