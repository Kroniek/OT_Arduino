#include "arduino_secrets.h"


#include <IRremote.h>

const int recv_pin = 2;  // Pin where the IR receiver is connected
const int led_pin = 13;  // Pin where the LED is connected

IRrecv irrecv(recv_pin);  // Create an IR receiver object
decode_results results;   // Object to hold the decoded data

bool ledState = false;    // Track the LED state (on/off)
unsigned long lastPress = 0; // To prevent multiple detections for the same button press
const int debounceDelay = 300; // Time delay to avoid multiple presses

void setup() {
  Serial.begin(9600);      // Start serial communication
  irrecv.enableIRIn();     // Start the IR receiver
  pinMode(led_pin, OUTPUT); // Set LED pin as output
}

void loop() {
  if (irrecv.decode(&results)) {  // Check if IR signal is received
    long int decCode = results.value;  // Decode the signal
    Serial.println(decCode);  // Print the received code to the serial monitor

    // Check if it's the Power button (replace 0xFF30CF with your actual Power button code)
    if (decCode == 0x1FE48B7 && (millis() - lastPress) > debounceDelay) {
      lastPress = millis();  // Update the last press time

      if (ledState == false) {  // LED is OFF, so turn it ON and blink twice
        blinkLED();  // Blink LED twice
        digitalWrite(led_pin, HIGH);  // Turn LED ON
        ledState = true;  // Update LED state
      } else {  // LED is ON, so turn it OFF
        digitalWrite(led_pin, LOW);  // Turn LED OFF
        ledState = false;  // Update LED state
      }
    }

    irrecv.resume();  // Prepare for the next signal
  }
}

// Function to blink the LED twice
void blinkLED() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(led_pin, HIGH);  // Turn LED ON
    delay(500);  // Wait for 500ms
    digitalWrite(led_pin, LOW);  // Turn LED OFF
    delay(500);  // Wait for 500ms
  }
}

/* // To get remote button value
#include <IRremote.h>

const int recv_pin = 2;  // Pin where the IR receiver is connected

IRrecv irrecv(recv_pin);  // Create an IR receiver object
decode_results results;   // Object to hold the decoded data

void setup() {
  Serial.begin(9600);      // Start serial communication
  irrecv.enableIRIn();     // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {  // Check if IR signal is received
    Serial.println(results.value, HEX);  // Print the received IR code in HEX format
    irrecv.resume();  // Prepare for the next signal
  }
}
*/
/*
#include <IRremote.h>

const int recv_pin = 2;  // Pin where the IR receiver is connected
const int ledPins[] = {3, 4, 5, 6, 7};  // Pins for LEDs (LED 1-5)
const int numLeds = 5;  // Total number of LEDs

IRrecv irrecv(recv_pin);  // Create an IR receiver object
decode_results results;   // Object to hold the decoded data

bool ledState[] = {false, false, false, false, false};  // Track the state of each LED (on/off)
unsigned long lastPress = 0;  // To prevent multiple detections for the same button press
const int debounceDelay = 300; // Time delay to avoid multiple presses

void setup() {
  Serial.begin(9600);      // Start serial communication
  irrecv.enableIRIn();     // Start the IR receiver

  // Initialize LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Make sure LEDs are off initially
  }
}

void loop() {
  if (irrecv.decode(&results)) {  // Check if IR signal is received
    Serial.println(results.value, HEX);  // Print the received IR code in HEX format

    // Check if the power button is pressed
    if (results.value == 0x1FE48B7 && (millis() - lastPress) > debounceDelay) {  // Replace with actual Power button code
      lastPress = millis();  // Update the last press time
      toggleLED();  // Toggle the LED with blinking effect
    } 
    
    // Check if buttons 1-5 are pressed and toggle the respective LED
    else if (results.value == 0x1FE50AF && (millis() - lastPress) > debounceDelay) {  // Button "1" (replace with actual value)
      lastPress = millis();  // Update the last press time
      toggleLed(0);  // Toggle LED 1
    }
    else if (results.value == 0x1FED827 && (millis() - lastPress) > debounceDelay) {  // Button "2" (replace with actual value)
      lastPress = millis();  // Update the last press time
      toggleLed(1);  // Toggle LED 2
    }
    else if (results.value == 0x1FEF807 && (millis() - lastPress) > debounceDelay) {  // Button "3" (replace with actual value)
      lastPress = millis();  // Update the last press time
      toggleLed(2);  // Toggle LED 3
    }
    else if (results.value == 0x1FE30CF && (millis() - lastPress) > debounceDelay) {  // Button "4" (replace with actual value)
      lastPress = millis();  // Update the last press time
      toggleLed(3);  // Toggle LED 4
    }
    else if (results.value == 0x1FEB04F && (millis() - lastPress) > debounceDelay) {  // Button "5" (replace with actual value)
      lastPress = millis();  // Update the last press time
      toggleLed(4);  // Toggle LED 5
    }
    // Check if button "0" is pressed to turn off all LEDs
    else if (results.value == 0x1FEE01F && (millis() - lastPress) > debounceDelay) {  // Button "0" (replace with actual value)
      lastPress = millis();  // Update the l
      turnOffAllLeds();  // Turn off all LEDs
    }

    irrecv.resume();  // Prepare for the next signal
  }
}

// Function to toggle LED (blink twice and then turn on/off)
void toggleLED() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPins[0], HIGH);  // Turn LED ON
    delay(500);  // Wait for 500ms
    digitalWrite(ledPins[0], LOW);  // Turn LED OFF
    delay(500);  // Wait for 500ms
  }
  
  // After blinking, turn the LED on or off based on the current state
  if (ledState[0]) {
    digitalWrite(ledPins[0], LOW);  // Turn off the LED
    ledState[0] = false;
  } else {
    digitalWrite(ledPins[0], HIGH);  // Turn on the LED
    ledState[0] = true;
  }
}

// Function to toggle a specific LED (turn it on/off based on the current state)
void toggleLed(int ledIndex) {
  if (ledState[ledIndex]) {
    digitalWrite(ledPins[ledIndex], LOW);  // Turn off the LED
    ledState[ledIndex] = false;
  } else {
    digitalWrite(ledPins[ledIndex], HIGH);  // Turn on the LED
    ledState[ledIndex] = true;
  }
}

// Function to turn off all LEDs
void turnOffAllLeds() {
  int ledIndex;
  for (int i = 0; i < numLeds; i++) {

    if (ledState[ledIndex]) {
      digitalWrite(ledPins[ledIndex], LOW);
      digitalWrite(ledPins[i], LOW);  // Turn off each LED
      ledState[i] = false;  // Update the state of each LED to OFF
    }
    else {
      digitalWrite(ledPins[ledIndex], HIGH);  // Turn on the LED
      digitalWrite(ledPins[i], HIGH);  // Turn ON each LED
      ledState[i] = true;  // Update the state of each LED to OFF
    }
  }
}
*/
