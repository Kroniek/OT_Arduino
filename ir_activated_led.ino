#include "arduino_secrets.h"

// Define IR sensor pins
const int irSensor1 = 2;
const int irSensor2 = 3;
const int irSensor3 = 4;
const int irSensor4 = 5;

// Define LED pins
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

void setup() {
  // Initialize IR sensor pins as inputs
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  
  // Initialize LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Read the state of each IR sensor
  int state1 = digitalRead(irSensor1);
  int state2 = digitalRead(irSensor2);
  int state3 = digitalRead(irSensor3);
  int state4 = digitalRead(irSensor4);

  // Control LEDs based on IR sensor states
  digitalWrite(led1, state1 == LOW ? HIGH : LOW);  // Turn on LED if sensor detects object
  digitalWrite(led2, state2 == LOW ? HIGH : LOW);
  digitalWrite(led3, state3 == LOW ? HIGH : LOW);
  digitalWrite(led4, state4 == LOW ? HIGH : LOW);

  // Small delay to stabilize readings
  delay(50);
}
