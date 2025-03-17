#include "arduino_secrets.h"

int potPin = A0;    // Analog pin connected to potentiometer
int ledPin = 9;     // PWM-capable digital pin connected to LED
int potValue = 0;   // Variable to store the potentiometer value
int ledBrightness = 0; // Variable to store LED brightness

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  Serial.println(potValue);
  potValue = analogRead(potPin);          // Read the potentiometer
  ledBrightness = map(potValue, 0, 1023, 0, 255); // Map potentiometer range to PWM range
  analogWrite(ledPin, ledBrightness);     // Set LED brightness
  delay(10);                              // Small delay for stability
}
