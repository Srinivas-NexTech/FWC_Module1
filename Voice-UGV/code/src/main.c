#include <Arduino.h>
#include "BluetoothSerial.h"


#define motor_input1 26
#define motor_input2 25
#define motor_input3 33
#define motor_input4 32
#define enableA 14
#define enableB 27
#define trigPin 2
#define echoPin 4


#define buzzerPin 13

BluetoothSerial SerialBT;
String voice;


void motorControl(int a, int b, int c, int d) {
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);
  digitalWrite(motor_input1, a);
  digitalWrite(motor_input2, b);
  digitalWrite(motor_input3, c);
  digitalWrite(motor_input4, d);
}


void stopUGV() {
  motorControl(0, 0, 0, 0);
}


long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH,30000);
  long distance = (duration * 0.0343) / 2; 

  return distance;
}

void setup() {
  Serial.begin(115200);

  
  pinMode(motor_input1, OUTPUT);
  pinMode(motor_input2, OUTPUT);
  pinMode(motor_input3, OUTPUT);
  pinMode(motor_input4, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);

  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); 
  digitalWrite(motor_input1, LOW); 
  digitalWrite(motor_input2, LOW); 
  digitalWrite(motor_input3, LOW); 
  digitalWrite(motor_input4, LOW); 
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);


  
  SerialBT.begin("ESP32");
  Serial.println("Bluetooth Voice control ready...");
}

void loop() {
  long distance = getDistance();
  if (distance > 0 && distance < 15) {
    stopUGV();
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Obstacle Detected! Stopped.");
    delay(100); 
    return;     
  } else {
    digitalWrite(buzzerPin, LOW); 
  }

  if (SerialBT.available()) {
    voice = SerialBT.readString();
    voice.trim();  

    Serial.print("Command: ");
    Serial.println(voice);

    if (voice == "forward") {
      motorControl(1, 0, 1, 0);
      Serial.println("Moving Forward");
    }
    else if (voice == "back") {
      motorControl(0, 1, 0, 1);
     Serial.println("Moving Backward");
    }
    else if (voice == "right") {
      motorControl(1, 0, 0, 1);
      Serial.println("Turning Right");
    }
    else if (voice == "left") {
      motorControl(0, 1, 1, 0);
      Serial.println("Turning Left");
    }
    else if (voice == "stop") {
      stopUGV();
      Serial.println("Stopped");
    }
    else {
      Serial.println("Invalid Command");
    }
  }
}
