#include "arduino_secrets.h"


int ledPin = 13;        // LED connected to digital pin 13
int button1Pin = 8;     // Button 1 connected to digital pin 8
int button2Pin = 9;     // Button 2 connected to digital pin 9

int ledState = LOW;     // Initial state of the LED
bool button1Pressed = false;
bool button2Pressed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  // Check if button 1 is pressed
  if (digitalRead(button1Pin) == LOW && !button1Pressed) {
    ledState = HIGH;  // Turn on the LED
    button1Pressed = true;
  }

  // Check if button 2 is pressed
  if (digitalRead(button2Pin) == LOW && !button2Pressed) {
    ledState = LOW;  // Turn off the LED
    button2Pressed = true;
  }

  // Reset button states when released
  if (digitalRead(button1Pin) == HIGH) button1Pressed = false;
  if (digitalRead(button2Pin) == HIGH) button2Pressed = false;

  digitalWrite(ledPin, ledState);  // Update the LED
}
/* // dual switch
int ledPin = 13;        // LED connected to digital pin 13
int button1Pin = 8;     // Button 1 connected to digital pin 8
int button2Pin = 9;     // Button 2 connected to digital pin 9

int ledState = LOW;     // Initial state of the LED
bool button1LastState = HIGH;  // Previous state of Button 1
bool button2LastState = HIGH;  // Previous state of Button 2

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  // Read the current state of each button
  bool button1State = digitalRead(button1Pin);
  bool button2State = digitalRead(button2Pin);

  // Check if button 1 is pressed (falling edge detection)
  if (button1State == LOW && button1LastState == HIGH) {
    ledState = !ledState;  // Toggle the LED state
  }

  // Check if button 2 is pressed (falling edge detection)
  if (button2State == LOW && button2LastState == HIGH) {
    ledState = !ledState;  // Toggle the LED state
  }

  // Update the LED based on the ledState
  digitalWrite(ledPin, ledState);

  // Update last state of buttons
  button1LastState = button1State;
  button2LastState = button2State;
}
*/
