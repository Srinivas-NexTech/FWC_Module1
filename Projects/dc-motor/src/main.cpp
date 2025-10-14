#include<Arduino.h>
// Define pin numbers
#define ENA 9        // PWM pin to enable motor
#define IN1 8        // Motor direction pin 1
#define IN2 7        // Motor direction pin 2
#define JOY_X A0     // Joystick X-axis (not used here for single motor)
#define JOY_Y A1     // Joystick Y-axis

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(JOY_X, INPUT);
    pinMode(JOY_Y, INPUT);
}

void loop() {
    int joyY = analogRead(JOY_Y);
    int speed = map(joyY, 0, 1023, -255, 255);

    if (speed > 10) {
        // Move forward
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        analogWrite(ENA, speed);
    } else if (speed < -10) {
        // Move backward
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 1);
        analogWrite(ENA, -speed);
    } else {
        // Stop
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 0);
        analogWrite(ENA, 0);
    }
}
