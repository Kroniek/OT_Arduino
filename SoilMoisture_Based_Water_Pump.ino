#include "arduino_secrets.h"

const int moistureSensorPin = A0; // Soil moisture sensor analog pin
const int relayPin = 7;           // Relay connected to digital pin 7
int moistureThreshold = 400;      // Adjust this threshold as per your sensor's readings

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);      // Set relay pin as output
  digitalWrite(relayPin, HIGH);   // Turn off pump initially (HIGH means off in this setup)
}

void loop() {
  int sensorValue = analogRead(moistureSensorPin); // Read soil moisture sensor value
  Serial.print("Soil Moisture Level: ");
  int srvalue = 1023-sensorValue;
  Serial.println(srvalue);

  if (srvalue < moistureThreshold) {
    digitalWrite(relayPin, LOW);  // Turn on pump (LOW means on in this setup)
    Serial.println("Water Pump ON");
  } else {
    digitalWrite(relayPin, HIGH); // Turn off pump
    Serial.println("Water Pump OFF");
  }

  delay(1000); // Delay for 2 seconds before next reading
}
