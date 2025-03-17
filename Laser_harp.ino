#include "arduino_secrets.h"

// Pin Definitions
const int ledPin = 13;
const int buzzerPin = A5;
const int ldrPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, A0, A1};  // 13 LDRs connected to these pins

// Corresponding frequencies for each LDR (C4 to C5)
const int noteFrequencies[] = {
  240,  // SA
  270,  // RE
  300,  // GA
  320,  // MA
  360,  // PA
  400,  // DHA
  450,  // NI
  245,  // S#A
  415,  // G#4
  440,  // A4
  466,  // A#4
  494,  // B4
  523   // C5
};

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Set each LDR pin as input
  for (int i = 0; i < 13; i++) {
    pinMode(ldrPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 13; i++) {
    int ldrStatus = digitalRead(ldrPins[i]);

    if (ldrStatus == HIGH) {
      tone(buzzerPin, noteFrequencies[i]);  // Play the corresponding note
      digitalWrite(ledPin, HIGH);
      Serial.print("LDR ");
      Serial.print(i + 1);
      Serial.println(" ACTIVATED - Playing Note");
      //delay(500);  // Duration of the note
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    } else {
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
    }
  }
  //delay(100);  // Small delay before checking the LDRs again
}
