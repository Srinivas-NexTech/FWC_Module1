#include <Arduino.h>
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(13, a); 
  digitalWrite(12, b); 
  digitalWrite(14, c); 
  digitalWrite(27, d); 
  digitalWrite(26, e); 
  digitalWrite(25, f);     
  digitalWrite(33, g); 
}
void setup() {
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(4,INPUT); 
  pinMode(16,INPUT); 
  pinMode(17,INPUT);   
}
void loop() {
  int P=digitalRead(4);
  int Q=digitalRead(16);
  int R=digitalRead(17);
  int F= (!P && !Q && R) || (!P && Q && !R) || (P && !Q && !R) || (P && Q && R);
  if(F==1)
  {
    sevenseg(1,0,0,1,1,1,1); 
  }
  else
    sevenseg(0,0,0,0,0,0,1);

}