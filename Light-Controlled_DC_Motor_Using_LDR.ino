#include "arduino_secrets.h"

// Define pins
const int LDRPin = A0;  // LDR connected to analog pin A0
const int motorPin = 9;  // Motor control pin connected to transistor base

void setup() {
  // Initialize motor pin as output
  pinMode(motorPin, OUTPUT);
  
  // Start serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the LDR value (light intensity)
  int LDRValue = analogRead(LDRPin);
  
  // Print LDR value to serial monitor
  Serial.println(LDRValue);
  
  // Map the LDR value to motor control (e.g., turning the motor on at a certain threshold)
  if (LDRValue > 600) {  // Adjust the threshold based on your LDR's behavior
    digitalWrite(motorPin, HIGH);  // Turn on the motor
  } else {
    digitalWrite(motorPin, LOW);   // Turn off the motor
  }
  
  delay(100);  // Small delay for stability
}
