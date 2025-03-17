#include "arduino_secrets.h"

#include <TM1637Display.h>

// Define connections to TM1637
#define CLK 2  // CLK pin connected to D2
#define DIO 3  // DIO pin connected to D3

TM1637Display display(CLK, DIO);

const int buttonPin = 4; // Push button connected to D4
int counter = 0;         // Initialize counter
int lastButtonState = LOW; // Variable to hold the last button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for button
  display.setBrightness(0x0f);      // Set display brightness (0x0f is max brightness)
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed and released (debounce)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50); // Debounce delay
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      counter++; // Increment counter
      if (counter > 9999) counter = 0; // Reset to 0 after reaching 9999
    }
  }
  
  lastButtonState = buttonState;

  // Display the current counter value on the 4-digit 7-segment display
  display.showNumberDec(counter, true); // Display the number with leading zeroes if necessary
}
