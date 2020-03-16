#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>

const int BUTTON_PIN = D7;
const int DHT_PIN = D5;

const int DHT_TYPE = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (bmp.begin(BMP280_ADDRESS_ALT)) {
    Serial.println("BMP ready");
  } else {
    Serial.println("BMP failed");
  }

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("Reading sensors...");
    
    float dhtTemp = dht.readTemperature(); 
    
    if (isnan(dhtTemp)) {
      Serial.println("Failed to read DHT!");
    } else {
      Serial.print("Temperature (DHT): ");
      Serial.print(dhtTemp);
      Serial.println(" *C");
    }

    float bmpTemp = bmp.readTemperature();

    if (isnan(bmpTemp)) {
      Serial.println("Failed to read BMP!");
    } else {
      Serial.print("Temperature (BMP): ");
      Serial.print(bmpTemp);
      Serial.println(" *C");
    }

    float bmpPressure = bmp.readPressure() / 100;

    if (isnan(bmpPressure)) {
      Serial.println("Failed to read BMP (pressure)!");
    } else {
      Serial.print("Pressure (BMP): ");
      Serial.print(bmpPressure);
      Serial.println(" hPa");
    }

    float bmpAltitude = bmp.readAltitude();

    if (isnan(bmpAltitude)) {
      Serial.println("Failed to read BMP (altitude)!");
    } else {
      Serial.print("Altitude: ");
      Serial.print(bmpAltitude);
      Serial.println("m");
    }

    int ldrValue = analogRead(A0);
    float voltage = ldrValue * (5.0 / 1023);

    if (isnan(voltage)) {
      Serial.println("Failed to read LDR!");
    } else {
      Serial.println("LDR voltage: ");
      Serial.print(voltage);
      Serial.println("V");
    }

    delay(1000);
  }
}