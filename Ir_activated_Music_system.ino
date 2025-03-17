#include "arduino_secrets.h"

// IR sensor pins
const int irSensors[] = {2, 3, 4};  // Array of 3 IR sensor pins
const int numSensors = 3;           // Number of sensors

// Buzzer pin
const int buzzer = 8;

// Notes corresponding to each IR sensor: Sa, Re, Ga
const int notes[] = {240, 400, 650};  // Corresponding notes

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  // Initialize IR sensor pins as inputs
  for (int i = 0; i < numSensors; i++) {
    pinMode(irSensors[i], INPUT);
  }
  // Initialize buzzer pin as output
  pinMode(buzzer, OUTPUT);
}

void loop() {
  bool sensorActivated = false;  // Track if any sensor is active

  // Check each IR sensor
  for (int i = 0; i < numSensors; i++) {
    int sensorState = digitalRead(irSensors[i]);  // Read the sensor state

    // Debugging: Print the sensor state
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(sensorState);

    if (sensorState == LOW) {  // If sensor is triggered (LOW signal)
      tone(buzzer, notes[i]);  // Play the corresponding note
      sensorActivated = true;  // Set the flag if a sensor is activated
    }
  }

  // If no sensor is active, stop the buzzer
  if (!sensorActivated) {
    noTone(buzzer);  // Stop the buzzer
  }

  delay(100);  // Small delay to avoid rapid re-triggering
}