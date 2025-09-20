#include<Arduino.h>
int P,Q,R;
int F;
void setup(){
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(7,OUTPUT);
}
void loop(){
P=digitalRead(2);
Q=digitalRead(3);
R=digitalRead(4);
F=(P&&Q) || (Q&&!R) ||(P&&!R);  //realized using K-Map
if(F==1){
digitalWrite(7,HIGH);
delay(1000);
}
else{
digitalWrite(7,LOW);
delay(1000);
}
}
