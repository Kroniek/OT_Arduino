#include "arduino_secrets.h"

int flamePin = 2;        // Pin connected to the flame sensor
int ledPin = 13;         // Pin connected to the LED

void setup() {
  pinMode(flamePin, INPUT); // Set flamePin as input
  pinMode(ledPin, OUTPUT);  // Set ledPin as output
  Serial.begin(9600);       // Begin serial communication
}

void loop() {
  int flameState = digitalRead(flamePin); // Read the state of the flame sensor
  if (flameState == LOW) { // LOW means flame detected
    digitalWrite(ledPin, HIGH); // Turn on LED
    Serial.println("Flame detected! LED ON");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("No flame detected.");
  }
  
  delay(100); // Small delay to stabilize readings
}
