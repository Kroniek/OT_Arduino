#include "arduino_secrets.h"

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  BTSerial.begin(9600); // Bluetooth module baud rate
  Serial.begin(9600); // Monitor serial output
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();

    if (command == '1') {
      digitalWrite(ledPin, HIGH); // Turn LED on
      Serial.println("LED ON");
    } 
    else if (command == '0') {
      digitalWrite(ledPin, LOW); // Turn LED off
      Serial.println("LED OFF");
    }
  }
}
