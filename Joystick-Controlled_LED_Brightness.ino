#include "arduino_secrets.h"

int joystickX = A0;   // Joystick X-axis connected to A0
int joystickY = A1;   // Joystick Y-axis connected to A1
int ledPin = 9;       // LED connected to pin 9
int joystickValue = 0; // Variable to store joystick reading
int ledBrightness = 0; // LED brightness level (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start serial communication for debugging
}

void loop() {
  joystickValue = analogRead(joystickX);  // Read joystick X-axis value
  ledBrightness = map(joystickValue, 0, 1023, 0, 255);  // Map joystick value to 0-255 range

  analogWrite(ledPin, ledBrightness);  // Set LED brightness based on joystick value

  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print("  LED Brightness: ");
  Serial.println(ledBrightness);

  delay(10);  // Small delay for smooth control
}
/*
int joystickX = A0;    // Joystick X-axis connected to A0
int joystickY = A1;    // Joystick Y-axis connected to A1
int ledPin1 = 9;       // LED1 connected to pin 9
int ledPin2 = 10;      // LED2 connected to pin 10
int joystickValue = 0; // Variable to store joystick reading
int ledBrightness = 0; // LED brightness level (0-255)
int switchThreshold = 512; // Threshold for left/right movement detection (middle of joystick range)

void setup() {
  pinMode(ledPin1, OUTPUT);  // Set LED1 pin as output
  pinMode(ledPin2, OUTPUT);  // Set LED2 pin as output
  Serial.begin(9600);        // Start serial communication for debugging
}

void loop() {
  joystickValue = analogRead(joystickX);  // Read joystick X-axis value
  
  if (joystickValue < switchThreshold) {
    // If joystick is on the left side (less than threshold)
    ledBrightness = map(joystickValue, 0, switchThreshold - 1, 0, 255);  // Map brightness for LED1
    analogWrite(ledPin1, ledBrightness);  // Set LED1 brightness
    analogWrite(ledPin2, 0);  // Turn off LED2
  } else {
    // If joystick is on the right side (greater than threshold)
    ledBrightness = map(joystickValue, switchThreshold, 1023, 0, 255);  // Map brightness for LED2
    analogWrite(ledPin2, ledBrightness);  // Set LED2 brightness
    analogWrite(ledPin1, 0);  // Turn off LED1
  }

  // Debugging output to the Serial Monitor
  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print("  LED1 Brightness: ");
  Serial.print(ledBrightness);
  Serial.print("  LED2 Brightness: ");
  Serial.println(ledBrightness);

  delay(10);  // Small delay for smooth control
}
*/
/*
int joystickX = A0;    // Joystick X-axis connected to A0
int joystickY = A1;    // Joystick Y-axis connected to A1
int ledPin1 = 9;       // LED1 connected to pin 9
int ledPin2 = 10;      // LED2 connected to pin 10
int joystickButton = 2; // Joystick button (MS) connected to pin 2
int joystickValue = 0; // Variable to store joystick reading
int ledBrightness = 0; // LED brightness level (0-255)
int switchThreshold = 512; // Threshold for left/right movement detection (middle of joystick range)
bool led1Selected = true; // Flag to track which LED is selected (true = LED1, false = LED2)

void setup() {
  pinMode(ledPin1, OUTPUT);  // Set LED1 pin as output
  pinMode(ledPin2, OUTPUT);  // Set LED2 pin as output
  pinMode(joystickButton, INPUT_PULLUP); // Set joystick button pin as input with internal pull-up resistor
  Serial.begin(9600);        // Start serial communication for debugging
}

void loop() {
  // Check if joystick button is pressed (LOW means pressed)
  if (digitalRead(joystickButton) == LOW) {
    delay(200); // Debounce delay to avoid multiple triggers
    led1Selected = !led1Selected; // Toggle between LED1 and LED2
    while (digitalRead(joystickButton) == LOW) {
      // Wait until button is released
    }
  }

  joystickValue = analogRead(joystickX);  // Read joystick X-axis value
  
  if (led1Selected) {
    // If LED1 is selected
    ledBrightness = map(joystickValue, 0, 1023, 0, 255);  // Map brightness for LED1
    analogWrite(ledPin1, ledBrightness);  // Set LED1 brightness
    analogWrite(ledPin2, 0);  // Turn off LED2
  } else {
    // If LED2 is selected
    ledBrightness = map(joystickValue, 0, 1023, 0, 255);  // Map brightness for LED2
    analogWrite(ledPin2, ledBrightness);  // Set LED2 brightness
    analogWrite(ledPin1, 0);  // Turn off LED1
  }

  // Debugging output to the Serial Monitor
  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print("  LED1 Brightness: ");
  Serial.print(ledBrightness);
  Serial.print("  LED2 Brightness: ");
  Serial.println(ledBrightness);

  delay(10);  // Small delay for smooth control
}*/

