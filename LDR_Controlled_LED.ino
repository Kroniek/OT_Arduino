#include "arduino_secrets.h"

int ledPin = 9;         // LED connected to digital pin 9
int ldrPin = A0;        // LDR connected to analog pin A0
int threshold = 160;    // Threshold value to turn the LED on

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read the LDR value
  Serial.println(ldrValue);           // Print the LDR value for calibration
  
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn LED on if it's dark
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off if it's bright
  }
  delay(100);  // Delay for stability
}
