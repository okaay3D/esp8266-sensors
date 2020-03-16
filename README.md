# Reading sensors

Just a small esp8266 project. PlatformIO in VSCode was used to create the code.

Sensors used in this project are:
- DHT11 (temperature)
- BMP280 (temperature and pressure)
- (generic) light dependent resistor

The reading process gets triggered when a button is pressed.


## Wiring
| Component | Pin |
|--|--|
|DHT11|D5 (GPIO14)|
|Button|D7 (GPIO13)|
|LDR|A0 (ADC0)|
|BMP280|SCL D1 (GPIO5)<br>SDA D2 (GPIO4)|
