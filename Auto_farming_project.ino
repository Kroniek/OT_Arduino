#include "arduino_secrets.h"

#include <DHT.h>

// Define pin connections
#define SOIL_MOISTURE_PIN A0  // Soil moisture sensor pin
#define FLAME_SENSOR_PIN A1   // Flame sensor pin
#define MQ2_SENSOR_PIN A2     // MQ2 gas sensor pin
#define DHTPIN 3              // DHT11 data pin
#define MOTOR_PIN 7           // Motor/Relay control pin

// Define sensor types
#define DHTTYPE DHT11         // DHT11 sensor type

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

// Threshold values
int soilMoistureThreshold = 300;  // Threshold for dry soil
int flameThreshold = 800;         // Threshold for flame detection

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize DHT sensor
  dht.begin();

  // Initialize motor pin
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);  // Motor is initially OFF

  Serial.println("System is starting...");
}

void loop() {
  // Read soil moisture sensor value
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  soilMoistureValue=abs(soilMoistureValue-1024);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Read flame sensor value
  int flameValue = analogRead(FLAME_SENSOR_PIN);
  Serial.print("Flame Sensor Value: ");
  Serial.println(flameValue);

  // Read MQ2 gas sensor value (just for monitoring, no control based on this in the code)
  int mq2Value = analogRead(MQ2_SENSOR_PIN);
  Serial.print("MQ2 Gas Sensor Value: ");
  Serial.println(mq2Value);

  // Read temperature and humidity from DHT11
  float temperature = dht.readTemperature();  // Temperature in Celsius
  float humidity = dht.readHumidity();        // Humidity in percentage

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Â°C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // Check conditions to turn ON motor
  if (flameValue < flameThreshold) {
    Serial.println("Flame detected! Turning on motor...");
    digitalWrite(MOTOR_PIN, HIGH);  // Turn ON the motor
  } else if (soilMoistureValue < soilMoistureThreshold) {
    Serial.println("Soil is dry! Turning on motor...");
    digitalWrite(MOTOR_PIN, HIGH);  // Turn ON the motor
  } else {
    Serial.println("Conditions normal. Motor OFF.");
    digitalWrite(MOTOR_PIN, LOW);   // Turn OFF the motor
  }

  // Delay for next reading
  delay(1000);
}
