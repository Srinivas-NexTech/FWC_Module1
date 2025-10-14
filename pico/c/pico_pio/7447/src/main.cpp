#include<Arduino.h>
int A,B,C;
int a,b,c,d;
int F;
void disp(int a, int b, int c, int d)
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
}
void loop()
{
        A=digitalRead(2); //inputs of expression in quetion ABC
        B=digitalRead(3);
        C=digitalRead(4);
	a=A;
	b=B;
	c=C;
	d=0;
	disp(a,b,c,d); //displyas input min term on 7 seg.
        //the expression of F from truth table
        F = (!A&&!B&&C)||(!A&&B&&C)||(A&&!B&&C)||(A&&B&&C);
        if(F==1)
        {
                digitalWrite(7,HIGH);
        }
        else
                digitalWrite(7,LOW);
}