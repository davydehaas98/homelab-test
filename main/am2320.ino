// https://learn.adafruit.com/adafruit-am2320-temperature-humidity-i2c-sensor?view=all

#include <Adafruit_AM2320.h>

Adafruit_AM2320 am2320;

void am2320_begin() {
  if (!am2320.begin()) {
    Serial.println(F("AM2320 sensor not found."));
  }
}

float am2320_get_temperature() {
  float temperature = am2320.readTemperature();

  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(" °C");

  return temperature;
}

float am2320_get_humidity() {
  float humidity = am2320.readHumidity();

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println("%");

  return humidity;
}
