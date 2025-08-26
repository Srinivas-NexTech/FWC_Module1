/*
#include<Arduino.h>
 void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); //MSB

}                                                                                                                                            // the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
disp_7447(0,1,0,1);
}
*/
/*
//Declaring all variables as integers
int Z=0,Y=0,X=0,W=0;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  A=(!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
  B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

disp_7447(D,C,B,A);
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
*/
//Declaring all variables as integers
/*
int Z,Y,X,W;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);

}

// the loop function runs over and over again forever
void loop() {

W = digitalRead(6);//LSB
X = digitalRead(7);
Y = digitalRead(8);
Z = digitalRead(9);//MSB

disp_7447(Z,Y,X,W);
}
*/
/*
#include<Arduino.h>
int Z,Y,X,W;
int D,C,B,A;
void disp_7447(int D,int C,int B,int A)
{
digitalWrite(2,A);
digitalWrite(3,B);
digitalWrite(4,C);
digitalWrite(5,D);
}
void setup(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
}
void loop(){
W=digitalRead(6);
X=digitalRead(7);
Y=digitalRead(8);
Z=digitalRead(9);
A=(!W&&!Z) || (!W&&!X&&!Y);
B=(W&&!X&&!Z) || (!W&&X&&!Z);
C=(W&&X&&!Y&&!Z) || (!X&&Y&&!Z) || (!W&&Y&&!Z);
D = (W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
disp_7447(D,C,B,A);
} */
#include<Arduino.h>
int Z,Y,X,W;
int D,C,B,A;
void disp_7447(int D,int C,int B,int A)
{
digitalWrite(2,A);
digitalWrite(3,B);
digitalWrite(4,C);
digitalWrite(5,D);
}
void setup(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
}
void loop(){
W=digitalRead(6);
X=digitalRead(7);
Y=digitalRead(8);
Z=digitalRead(9);
A =(!W);
B=(W&&!X&&!Z) || (!W&&X);
C=(!X&&Y) || (!W&&Y) || (W&&X&&!Y);
D=(!W&&Z) || (W&&X&&Y);
disp_7447(D,C,B,A); }

