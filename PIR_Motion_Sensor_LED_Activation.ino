#include "arduino_secrets.h"

// Define pins
int pirPin = 2;     // PIR sensor connected to digital pin 2
int ledPin = 13;    // LED connected to digital pin 13

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR sensor as input
  pinMode(ledPin, OUTPUT);  // Set LED as output
  Serial.begin(9600);       // Begin serial communication for debugging
}

void loop() {
  int motionDetected = digitalRead(pirPin); // Read PIR sensor value

  if (motionDetected == HIGH) {            // If motion is detected
    digitalWrite(ledPin, HIGH);            // Turn on LED
    Serial.println("Motion Detected!");    // Print to serial monitor
    delay(5000);                           // Keep LED on for 5 seconds
  } else {
    digitalWrite(ledPin, LOW);             // Turn off LED
  }

  delay(100); // Small delay to avoid rapid LED flickering
}
