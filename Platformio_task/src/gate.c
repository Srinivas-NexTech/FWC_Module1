/*#include<Arduino.h>
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
// F=(!P&&Q&&!R) || (P&&!Q&&!R) || (P&&Q&&!R) || (P&&Q&&R); //just to blink ledd with given expression
F=(P&&Q) || (Q&&!R) ||(P&&!R);  //realized using K-Map
if(F==1){
digitalWrite(7,HIGH);
delay(1000);
}
else
digitalWrite(7,LOW);
delay(1000);
}
*/

//displaying output on sevensegment display using 7447 display decoder
/*
int P,Q,R;
int  D,C,B,A;
int F;
void disp_7447(int D,int C,int B,int A){
digitalWrite(8,D);
digitalWrite(9,C);
digitalWrite(10,B);
digitalWrite(11,A);
}
void setup(){
pinMode(2,INPUT);//lsb
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
void loop(){
P=digitalRead(2);
Q=digitalRead(3);
R=digitalRead(4);
D=0;
C=P;
B=Q;
A=R;
disp_7447(D,C,B,A);
F=(P&&Q) || (Q&&!R) || (P&&!R);
if(F==1){
digitalWrite(5,HIGH);
delay(1000);
}
else
digitalWrite(5,LOW);
delay(1000);
}
*/

//realizing the same problem  with help of 7474 Dflipflop 

int P=0,Q=0,R=0;
int  D,C,B,A;
int F;
void disp_7447(int D,int C,int B,int A){
digitalWrite(8,D);
digitalWrite(9,C);
digitalWrite(10,B);
digitalWrite(11,A);
}
void setup(){
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(13,OUTPUT);
}
void loop(){
P=digitalRead(2);
Q=digitalRead(3);
R=digitalRead(4);
D=0;
C=(P&&!Q) || (P&&!R) || (!P&&Q&&R);
B=(!Q&&R) || (Q&&!R);
A=(!R);
disp_7447(D,C,B,A);
F=(!P&&R) || (P&&Q&&!R) || (!Q&&R);
if(F==1){
digitalWrite(5,HIGH);
}
else{
digitalWrite(5,LOW);
}
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
}
