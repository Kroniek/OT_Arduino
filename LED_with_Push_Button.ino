#include "arduino_secrets.h"

// Define pin numbers
const int ledPin = 9;
const int buttonPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);     // Set LED as output
  pinMode(buttonPin, INPUT);    // Set button as input
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read button state
  //delay(1000);
  Serial.println(buttonState);
  if (buttonState == HIGH) {   // If button is pressed
    digitalWrite(ledPin, HIGH);  // Turn LED on
  } 
  else {
    digitalWrite(ledPin, LOW);   // Turn LED off
  }
}
