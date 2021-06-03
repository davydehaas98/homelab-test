#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();

void am2320_setup() {
  am2320.begin();
}

float am2320_get_temp() {
  float temperature = am2320.readTemperature();
  
  Serial.print("Temp: ");
  Serial.println(temperature);

  return temperature;
}

float am2320_get_hum() {
  float humidity = am2320.readHumidity();
  
  Serial.print("Hum: ");
  Serial.println(humidity);
  
  return humidity;
}
