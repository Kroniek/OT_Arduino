#include "arduino_secrets.h"

// Define pins
const int touchPin = 2;     // Pin for the touch sensor output
const int ledPin = 13;      // Pin for the LED

// Variables to hold LED state
bool ledState = false;      // Initial LED state is off
bool lastTouchState = LOW;  // Holds the last state of the touch sensor

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Read the current state of the touch sensor
  bool touchState = digitalRead(touchPin);

  // Check if the touch sensor has been touched
  if (touchState == HIGH && lastTouchState == LOW) {
    ledState = !ledState;  // Toggle LED state
    digitalWrite(ledPin, ledState);
    delay(300);  // Debounce delay
  }

  // Update the last state
  lastTouchState = touchState;
}

/* // Touch sensitivity based toogle
#define TOUCH_PIN 2
#define LED_PIN 13

unsigned long touchStartTime = 0;
bool isTouched = false;
int ledBrightness = 0;

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int touchState = digitalRead(TOUCH_PIN);

  if (touchState == HIGH && !isTouched) {
    // Start timing the touch
    touchStartTime = millis();
    isTouched = true;
  }

  if (touchState == LOW && isTouched) {
    // Calculate how long the touch lasted
    unsigned long touchDuration = millis() - touchStartTime;

    // Adjust LED brightness or toggle based on touch duration
    if (touchDuration < 500) {
      // Short touch: Toggle LED
      ledBrightness = ledBrightness == 0 ? 255 : 0;
    } else {
      // Long touch: Adjust brightness based on duration
      ledBrightness = map(touchDuration, 500, 2000, 0, 255); // Adjust as needed
    }

    analogWrite(LED_PIN, ledBrightness);
    isTouched = false;
  }
}
*/