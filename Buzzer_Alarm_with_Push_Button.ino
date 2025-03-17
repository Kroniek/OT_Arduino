#include "arduino_secrets.h"

const int buttonPin = 2;  // Pin connected to the push button
const int buzzerPin = 9;  // Pin connected to the buzzer

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);   // Set button pin as an input
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as an output
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Read the button state

  if (buttonState == HIGH) {
    Serial.println(buttonState);
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
  }
}
