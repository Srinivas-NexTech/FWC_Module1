#include<Arduino.h>
#define SERVO_PIN 9     // Connect servo signal pin here
#define JOY_X_PIN A0    // Joystick X-axis to analog pin A0
long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void setup() {
    pinMode(SERVO_PIN, OUTPUT);
    pinMode(JOY_X_PIN, INPUT);
}

void loop() {
    int joyVal = analogRead(JOY_X_PIN);             // Range: 0-1023
    int pulseLen = map(joyVal, 0, 1023, 1000, 2000); // 1000us (0°) to 2000us (180°)

    digitalWrite(SERVO_PIN, HIGH);
    delayMicroseconds(pulseLen);        // pulse for the correct "angle"
    digitalWrite(SERVO_PIN, LOW);
    delay(18);                          // repeat about every 20 ms
}
