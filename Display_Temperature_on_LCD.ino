#include "arduino_secrets.h"

#include <DHT.h>
#include <LiquidCrystal.h>

// Define pin numbers
#define DHTPIN 8         // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11    // DHT sensor type (DHT11)

// Initialize DHT sensor and LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);            // Initialize the LCD with 16 columns and 2 rows
  dht.begin();                 // Initialize the DHT sensor

  // Display initial text on the LCD
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);         // Move to the second line
  lcd.print("Humidity: ");
}

void loop() {
  delay(2000);  // Wait a few seconds between readings

  // Read humidity and temperature values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Temperature in Celsius

  // Check if any reading failed and exit early (to try again in the next loop)
  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.print("DHT Error!");
    return;
  }

  // Display temperature on LCD
  lcd.setCursor(6, 0);         // Position cursor after "Temp: "
  lcd.print(temperature);
  lcd.print(" C ");            // Print " C " to indicate Celsius

  // Display humidity on LCD
  lcd.setCursor(10, 1);        // Position cursor after "Humidity: "
  lcd.print(humidity);
  lcd.print(" % ");            // Print " % " for percentage humidity

  delay(1000); // Optional delay to control refresh rate
}
