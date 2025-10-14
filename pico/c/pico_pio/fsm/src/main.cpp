#include<Arduino.h>
int A=0,B=0,C=0,F;
int a,b,c,d=0;
void disp(int a,int b,int c,int d)
{
	digitalWrite(8,a);
	digitalWrite(9,b);
	digitalWrite(10,c);
	digitalWrite(11,d);
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
	A=digitalRead(2);
	B=digitalRead(3);
	C=digitalRead(4);
	a=!C;
	b=(!B&&C)||(B&&!C);
	c=(A&&!B)||(A&&!C)||(!A&&B&&C);
	d=0;
	disp(a,b,c,d);
	F=!C; //ouput expression from state transition tabel
	if(F==1)
		digitalWrite(7,HIGH);
	else
		digitalWrite(7,LOW);
	digitalWrite(13,HIGH);
	delay(500);
	digitalWrite(13,LOW);
	delay(500);

}