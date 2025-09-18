#include<Arduino.h>
int A,B,C;
int F;
void setup()
{
        pinMode(2,INPUT);
        pinMode(3,INPUT);
        pinMode(4,INPUT);
        pinMode(7,OUTPUT);
	pinMode(13,OUTPUT);
}
void loop()
{
	A=digitalRead(2); //msb //inputs of expression in quetion ABC
	B=digitalRead(3);
        C=digitalRead(4);//lsb
        F=(A&&B) || (A&&!C) || (B&&!C);
        if(F==1)
        {
                digitalWrite(7,HIGH);
        }
        else{
               digitalWrite(7,LOW);
             }
	digitalWrite(13,HIGH);
	delay(500);
	digitalWrite(13,LOW);
	delay(500);
}
