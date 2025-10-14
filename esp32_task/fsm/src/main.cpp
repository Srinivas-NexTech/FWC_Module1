#include<Arduino.h>
int P=0,Q=0,R=0,F;
int A,B,C,D;
void disp(int A,int B,int C,int D)
{
	digitalWrite(8,A);
	digitalWrite(9,B);
	digitalWrite(10,C);
	digitalWrite(11,D);
}
void setup()
{
	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT);
	pinMode(7,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
	pinMode(13,OUTPUT);
}
void loop()
{
	P=digitalRead(2);
	Q=digitalRead(3);
	R=digitalRead(4);
	A=!R;
	B=(!Q&&R)||(Q&&!R);
	C=(P&&!R)||(P&&!Q)||(!P&&Q&&R);
	D=0;
	disp(A,B,C,D);
	F=(!P&&!Q)||(!P&&Q&&R)||(P&&Q&&!R); //ouput expression from state transition tabel
	if(F==1)
		digitalWrite(7,HIGH);
	else
		digitalWrite(7,LOW);
	digitalWrite(13,HIGH);
	delay(500);
	digitalWrite(13,LOW);
	delay(500);

}