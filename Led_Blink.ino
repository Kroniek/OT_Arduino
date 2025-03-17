#include "arduino_secrets.h"

// Basic LED Blink code

// Set LED_BUILTIN as the LED pin
const int ledPin = 13;

void setup() {
  // Initialize digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 1 second
  
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  delay(1000); // Wait for 1 second
}
