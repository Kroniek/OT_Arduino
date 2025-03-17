#include "arduino_secrets.h"

// Pin Definitions
const int rainSensorPin = A0;  // Raindrop sensor connected to analog pin A0
const int buzzerPin = 9;       // Buzzer connected to digital pin 9

// Threshold for rain detection (adjust based on your sensor)
const int rainThreshold = 300;

void setup() {
  pinMode(buzzerPin, OUTPUT);        // Set buzzer pin as output
  Serial.begin(9600);                // Start the serial communication
}

void loop() {
  int rainSensorValue = analogRead(rainSensorPin);  // Read the value from the raindrop sensor
  
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainSensorValue);  // Print sensor value to Serial Monitor

  // Check if the sensor detects rain (sensor value above the threshold)
  if (rainSensorValue > rainThreshold) {
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
  }

  delay(100);  // Delay to avoid overwhelming the sensor
}
