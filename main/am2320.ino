// https://learn.adafruit.com/adafruit-am2320-temperature-humidity-i2c-sensor?view=all

#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();

void am2320_setup() {
  if (!am2320.begin()) {
    Serial.println(F("AM2320 sensor not found."));
    while (1) delay(10);
  }
  Serial.println(F("AM2320 sensor found."));
}

float am2320_get_temp() {
  float temperature = am2320.readTemperature();

  Serial.print(F("Temp: "));
  Serial.println(temperature);

  return temperature;
}

float am2320_get_hum() {
  float humidity = am2320.readHumidity();

  Serial.print(F("Hum: "));
  Serial.println(humidity);

  return humidity;
}
