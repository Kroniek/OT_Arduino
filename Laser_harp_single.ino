#include "arduino_secrets.h"

const int ledPin = 13;
const int buzzerPin = A5;
const int ldrPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  }

void loop() {
  int ldrStatus = digitalRead(ldrPin);
  if (ldrStatus == 1) {
    tone(buzzerPin, 523);
    digitalWrite(ledPin, HIGH);
    delay(100);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    //delay(100);
    Serial.println(" ALARM ACTIVATED ");
    }
    else {
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
      Serial.println("ALARM DEACTIVATED");
      }
      Serial.println( ldrStatus );
      delay(10);
      }

/*
const int sensorPin = 2;  // Digital pin connected to the sensor's OUT pin

void setup() {
  pinMode(sensorPin, INPUT);   // Set sensor pin as input
  Serial.begin(9600);          // Initialize serial communication
}

void loop() {
  int sensorState = digitalRead(sensorPin);  // Read the sensor's output

  if (sensorState == HIGH) {
    Serial.println("1");  // Laser beam detected
  } else {
    Serial.println("0");  // Laser beam interrupted
  }

  delay(100);  // Short delay for stability
}
*/