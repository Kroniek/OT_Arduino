#include "arduino_secrets.h"

// Define pins
const int sensorPin = A0;   // Soil Moisture Sensor pin
const int greenLED = 9;     // Green LED pin
const int yellowLED = 10;   // Yellow LED pin
const int redLED = 11;      // Red LED pin

void setup() {
  Serial.begin(9600);       // Initialize serial monitor
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  int moistureValue = analogRead(sensorPin); // Read moisture sensor value

  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);  // Print moisture level to Serial Monitor

  // LED Indicator Logic
  if (moistureValue > 800) {           // Very Dry
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);        // Turn on Red LED
  } else if (moistureValue > 500) {    // Moderate
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);     // Turn on Yellow LED
    digitalWrite(redLED, LOW);
  } else {                             // Sufficiently Wet
    digitalWrite(greenLED, HIGH);      // Turn on Green LED
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  
  delay(1000); // Wait for 1 second before the next reading
}
