#include "arduino_secrets.h"

int flameSensor = 2; // Flame sensor connected to D2
int buzzer = 9;      // Buzzer connected to D9
int flameDetected;   // Variable to store flame sensor status

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  flameDetected = digitalRead(flameSensor);

  if (flameDetected == LOW) { // Flame detected (typically LOW signal)
    digitalWrite(buzzer, HIGH); // Activate buzzer
    Serial.println("Flame detected! Alert!");
  } else {
    digitalWrite(buzzer, LOW); // Turn off buzzer
    Serial.println("No flame detected.");
  }

  delay(100); // Delay for stability
}
