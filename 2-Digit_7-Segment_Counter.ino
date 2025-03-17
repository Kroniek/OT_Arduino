#include "arduino_secrets.h"

#include <Arduino.h>

// Define the segment pins for the two 7-segment displays
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8}; // A to G segments
const int digitPins[2] = {9, 10}; // Pins to select which digit is active

// Segment encoding for digits 0-9 with inverted HIGH/LOW logic
const byte digitSegments[10] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

int counter = 0; // The counter value to display

void setup() {
  // Set up segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Set up digit control pins as outputs
  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW); // Start with both digits off
  }
}

void displayDigit(int digit, int value) {
  // Set the segment pins according to the digit's segments
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (digitSegments[value] >> i) & 0x01);
  }
  
  // Turn on the selected digit
  digitalWrite(digitPins[digit], HIGH);
  delay(5); // Small delay to make the digit visible
  digitalWrite(digitPins[digit], LOW); // Turn off after delay
}

void loop() {
  int tens = counter / 10; // Tens place
  int ones = counter % 10; // Ones place
  
  // Display each digit in a multiplexed manner
  displayDigit(0, tens);  // Display the tens place
  displayDigit(1, ones);  // Display the ones place

  delay(10); // Overall refresh rate to reduce flickering

  // Update counter and reset to 0 after reaching 99
  counter++;
  if (counter > 99) {
    counter = 0;
  }
}
