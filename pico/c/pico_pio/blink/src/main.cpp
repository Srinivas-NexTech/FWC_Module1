#include<Arduino.h>
int A,B,C;
int F;
void setup()
{
        pinMode(2,INPUT);
        pinMode(3,INPUT);
        pinMode(4,INPUT);
        pinMode(7,OUTPUT);
}
void loop()
{
	A=digitalRead(2); //msb //inputs of expression in quetion ABC
	B=digitalRead(3);
        C=digitalRead(4);//lsb
        //the expression of F from truth table
        //F = (!A&&!B&&C)||(!A&&B&&C)||(A&&!B&&C)||(A&&B&&C);
        //the minimized expression of F using kmap is
        F=C;
        if(F==1)
        {
                digitalWrite(7,HIGH);
        }
        else
                digitalWrite(7,LOW);
}