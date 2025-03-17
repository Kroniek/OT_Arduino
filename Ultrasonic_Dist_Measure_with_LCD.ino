#include "arduino_secrets.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust address to match your LCD (0x27 or 0x3F)

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  lcd.init();    // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();     // Turn on the backlight
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear line by printing spaces
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000);  // Update every second
}
