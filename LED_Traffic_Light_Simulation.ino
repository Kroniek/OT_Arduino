#include "arduino_secrets.h"

// Define LED pins
const int redLightPin = 13;
const int yellowLightPin = 12;
const int greenLightPin = 11;

// Timings for each light in milliseconds
const int greenLightTime = 5000;   // Green light on for 5 seconds
const int yellowLightTime = 2000;  // Yellow light on for 2 seconds
const int redLightTime = 5000;     // Red light on for 5 seconds

void setup() {
  // Set up each LED pin as an output
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
}

void loop() {
  // Green light sequence
  digitalWrite(greenLightPin, HIGH);  // Turn green light on
  delay(greenLightTime);               // Keep it on for 5 seconds
  digitalWrite(greenLightPin, LOW);    // Turn green light off
  
  // Yellow light sequence
  digitalWrite(yellowLightPin, HIGH);  // Turn yellow light on
  delay(yellowLightTime);              // Keep it on for 2 seconds
  digitalWrite(yellowLightPin, LOW);   // Turn yellow light off
  
  // Red light sequence
  digitalWrite(redLightPin, HIGH);     // Turn red light on
  delay(redLightTime);                 // Keep it on for 5 seconds
  digitalWrite(redLightPin, LOW);      // Turn red light off
}
