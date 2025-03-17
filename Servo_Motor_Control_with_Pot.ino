#include "arduino_secrets.h"

#include <Servo.h>

Servo myServo;  // Create servo object

int potPin = A0;  // Analog pin connected to potentiometer
int potVal;       // Variable to store potentiometer value
int angle;        // Variable to store mapped angle for servo

void setup() {
  myServo.attach(9);  // Attach the servo on pin 9
  Serial.begin(9600); // Begin serial communication for debugging
}

void loop() {
  potVal = analogRead(potPin);                // Read potentiometer value
  angle = map(potVal, 0, 1023, 0, 180);       // Map to range of servo angle
  myServo.write(angle);                       // Set servo to angle
  Serial.println("Potentiometer Value: " + String(potVal) + " | Servo Angle: " + String(angle));
  delay(15);                                  // Small delay for stability
}
