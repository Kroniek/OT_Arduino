#include "arduino_secrets.h"

#include <IRremote.h>

// Define pins
const int RECV_PIN = 11; // IR receiver pin
const int BUZZER_PIN = 9; // Buzzer pin

IRrecv irrecv(RECV_PIN);
decode_results results;

bool buzzerState = false; // Variable to track the buzzer's state

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW); // Initially turn off the buzzer
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); // Print the IR code to the Serial Monitor

        // Replace `0xFFA25D` with the IR code of your specific remote button
        if (results.value == 0x1FE48B7) { // Example code for the toggle button
            buzzerState = !buzzerState; // Toggle the buzzer state
            digitalWrite(BUZZER_PIN, buzzerState ? HIGH : LOW); // Set buzzer on/off based on state
        }

        irrecv.resume(); // Receive the next value
    }
}
