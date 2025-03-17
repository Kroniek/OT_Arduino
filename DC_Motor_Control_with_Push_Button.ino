#include "arduino_secrets.h"

const int motorPin = 9;      // Pin connected to the transistor base
const int buttonPin = 2;     // Pin connected to one side of the button

int buttonState = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state

  if (buttonState == HIGH) {
    digitalWrite(motorPin, HIGH);       // Turn on the motor
  } else {
    digitalWrite(motorPin, LOW);        // Turn off the motor
  }
}
