#include "arduino_secrets.h"

#include <Servo.h> // Include the Servo library

Servo myServo; // Create a servo object
int servoPin = 9; // Pin connected to the servo's control wire

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  myServo.attach(servoPin); // Attach the servo to the specified pin
  myServo.write(90); // Set the servo to the neutral position (90 degrees)
  Serial.println("Enter an angle (0-180) for the servo:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read input until newline
    input.trim(); // Remove leading/trailing whitespace
    int angle = input.toInt(); // Convert input to an integer

    // Check if the input is valid
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle); // Set servo to the input angle
      Serial.print("Servo set to ");
      Serial.print(angle);
      Serial.println(" degrees.");
    } else {
      Serial.println("Invalid input! Please enter an angle between 0 and 180.");
    }
  }
}
