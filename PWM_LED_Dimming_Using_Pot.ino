#include "arduino_secrets.h"

int potPin = A0;        // Analog pin connected to potentiometer
int ledPin1 = 9;         // PWM-capable pin connected to first LED
int ledPin2 = 10;        // PWM-capable pin connected to second LED

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);           // Read potentiometer value (0-1023)
  
  // Map potentiometer value to the PWM range (0-255)
  int brightness1 = map(potValue, 0, 1023, 255, 0); // LED1 dims as potValue increases
  int brightness2 = map(potValue, 0, 1023, 0, 255); // LED2 gets brighter as potValue increases

  // Apply brightness to LEDs
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);
  
  delay(10); // Small delay for stability
}
