#include<Arduino.h>
#define IR_PIN    7   // OUT pin of IR receiver to Arduino D7
#define RELAY_PIN 8   // Relay module IN to Arduino D8

void setup() {
    pinMode(IR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); // Relay OFF (lamp OFF) initially
}

void loop() {
    int irState = digitalRead(IR_PIN);

    // For a basic IR module: HIGH means something is detected
    if(irState == HIGH) {
        digitalWrite(RELAY_PIN, HIGH); // Turn ON relay (lamp ON)
    } else {
        digitalWrite(RELAY_PIN, LOW);  // Turn OFF relay (lamp OFF)
    }
}
