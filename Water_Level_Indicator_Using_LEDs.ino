#include "arduino_secrets.h"

// Pin assignment
const int level1Pin = 2; // Lowest level
const int level2Pin = 3;
const int level3Pin = 4;
const int level4Pin = 5; // Highest level

const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;

void setup() {
    // Initialize the water level pins as input
    pinMode(level1Pin, INPUT);
    pinMode(level2Pin, INPUT);
    pinMode(level3Pin, INPUT);
    pinMode(level4Pin, INPUT);

    // Initialize the LEDs as output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {
    // Read water level sensors
    int level1 = digitalRead(level1Pin);
    int level2 = digitalRead(level2Pin);
    int level3 = digitalRead(level3Pin);
    int level4 = digitalRead(level4Pin);

    // Control LEDs based on water level
    digitalWrite(led1, level1);
    digitalWrite(led2, level2);
    digitalWrite(led3, level3);
    digitalWrite(led4, level4);

    delay(100); // Short delay for debounce
}
