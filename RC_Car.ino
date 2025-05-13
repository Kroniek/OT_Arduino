#include <SoftwareSerial.h>

// Define Bluetooth pins for SoftwareSerial
SoftwareSerial BTSerial(2, 3); // RX = 2, TX = 3

char t;
const int mt1 = 5;  // Left motor forward
const int mt2 = 6;  // Left motor reverse
const int mt3 = 10; // Right motor forward
const int mt4 = 11; // Right motor reverse


void setup() {
  // Set all motor control pins as OUTPUT
  pinMode(mt1, OUTPUT);
  pinMode(mt2, OUTPUT);
  pinMode(mt3, OUTPUT);
  pinMode(mt4, OUTPUT);


  // Start SoftwareSerial for Bluetooth
  BTSerial.begin(9600); // Set the baud rate of Bluetooth module
  Serial.begin(9600);   // Start hardware serial for debugging
}

void loop() {
  // Check if data is available to read from Bluetooth via SoftwareSerial
  if (BTSerial.available() > 0) {
    t = BTSerial.read();  // Read the command from Bluetooth
    Serial.println(t);    // Print the command to Serial Monitor (for debugging)
  }

  // Forward
  if (t == 'F') {
    digitalWrite(mt1, HIGH);
    digitalWrite(mt3, HIGH);
    digitalWrite(mt2, LOW);
    digitalWrite(mt4, LOW);
  
  }

  // Backward
  else if (t == 'B') {
    digitalWrite(mt1, LOW);
    digitalWrite(mt3, LOW);
    digitalWrite(mt2, HIGH);
    digitalWrite(mt4, HIGH);
  }

  // Turn left (right motors move forward)
  else if (t == 'L') {
     digitalWrite(mt1, LOW);
    digitalWrite(mt3, HIGH);
    digitalWrite(mt2, LOW);
    digitalWrite(mt4, LOW);
    
  }

  // Turn right (left motors move forward)
  else if (t == 'R') {
    digitalWrite(mt1, HIGH);
    digitalWrite(mt3, LOW);
    digitalWrite(mt2, LOW);
    digitalWrite(mt4, LOW);
  }

  // Stop
  else if (t == 'S') {
    digitalWrite(mt1, LOW);
    digitalWrite(mt3, LOW);
    digitalWrite(mt2, LOW);
    digitalWrite(mt4, LOW);
  }

  delay(100); // Small delay for stability
}
