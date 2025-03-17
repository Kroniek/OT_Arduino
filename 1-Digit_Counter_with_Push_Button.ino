#include "arduino_secrets.h"

// Pin assignments for each segment
const int a = 4;
const int b = 5;
const int c = 8;
const int d = 7;
const int e = 6;
const int f = 3;
const int g = 2;
const int buttonPin = 10;  // Pin for push button

int counter = 0;  // Initialize counter to start at 0
int lastButtonState = LOW;  // Track last button state
unsigned long debounceDelay = 200;   // Debounce delay for button

// Segment patterns for digits 0-9 (no decimal point)
const bool digits[10][7] = {
  {LOW, LOW, LOW, LOW, LOW, LOW,HIGH},   // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},       // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},    // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},    // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},     // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},    // 5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},   // 6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},      // 7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},  // 8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}    // 9
};

void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(buttonPin, INPUT);  // Button input
  displayDigit(counter);  // Show initial value 0
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Check if the button has been pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(debounceDelay);  // Debounce delay
    counter = (counter + 1) % 10;  // Increment and wrap around at 10
    Serial.println(counter);
    displayDigit(counter);  // Display updated counter value
  }
  lastButtonState = buttonState;  // Update last button state
}

// Function to display a digit on the 7-segment display
void displayDigit(int num) {
  digitalWrite(a, digits[num][0]);
  digitalWrite(b, digits[num][1]);
  digitalWrite(c, digits[num][2]);
  digitalWrite(d, digits[num][3]);
  digitalWrite(e, digits[num][4]);
  digitalWrite(f, digits[num][5]);
  digitalWrite(g, digits[num][6]);
}
