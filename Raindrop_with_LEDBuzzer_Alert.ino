#include "arduino_secrets.h"

// Pin assignments
int sensorPin = 2;  // Raindrop sensor digital output pin
int ledPin = 13;    // LED output pin
int buzzerPin = 12; // Buzzer output pin

void setup() {
  pinMode(sensorPin, INPUT);   // Set raindrop sensor pin as input
  pinMode(ledPin, OUTPUT);     // Set LED pin as output
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
  Serial.begin(9600);          // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = digitalRead(sensorPin);  // Read sensor value

  if (sensorValue == LOW) { // When raindrop detected
    digitalWrite(ledPin, HIGH);  // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
    Serial.println("Raindrop detected!"); // Print message to Serial Monitor
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    digitalWrite(buzzerPin, LOW); // Deactivate buzzer
    Serial.println("No raindrop detected."); // Print message to Serial Monitor
  }

  delay(500); // Wait for 500ms before checking again
}
