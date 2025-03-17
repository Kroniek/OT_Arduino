#include "arduino_secrets.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define DHT Sensor
#define DHTPIN 7          // DHT11 data pin connected to Arduino pin 7
#define DHTTYPE DHT11     // DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

// Define LCD Address and Dimensions
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address commonly 0x27 or 0x3F for 16x2 LCD

void setup() {
    lcd.init();              // Initialize the LCD (using init())
    lcd.backlight();         // Turn on the backlight
    dht.begin();             // Initialize the DHT sensor
    lcd.print("Temp & Humid"); // Initial display message
    delay(2000);
    lcd.clear();
}

void loop() {
    // Read temperature and humidity from DHT11
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");     // Display error if sensor read fails
        return;
    }

    // Display temperature and humidity on the LCD
    lcd.setCursor(0, 0);               // Set cursor to top left
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");

    lcd.setCursor(0, 1);               // Set cursor to second line
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print(" %");

    delay(2000); // Refresh display every 2 seconds
}
