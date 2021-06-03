#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp;

void bmp280_setup() {
  if (!bmp.begin()) {
    Serial.println(F("BMP280 sensor not found."));
    while (1) delay(10);
  }
  Serial.println(F("BMP280 sensor found."));

  bmp.setSampling(
    Adafruit_BMP280::MODE_NORMAL,     // Operating Mode
    Adafruit_BMP280::SAMPLING_X2,     // Temperature oversampling
    Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
    Adafruit_BMP280::FILTER_X16,      // Filtering
    Adafruit_BMP280::STANDBY_MS_500   // Standby time
  );
}

float bmp280_get_temp() {
  float temperature = bmp.readTemperature();

  Serial.print(F("Temp: "));
  Serial.print(temperature);
  Serial.println(" *C");

  return temperature;
}

float bmp280_get_pressure() {
  float pressure = bmp.readPressure();

  Serial.print(F("Pressure: "));
  Serial.print(pressure);
  Serial.println(" Pa");

  return pressure;
}

float bmp280_get_altitude() {
  float altitude = bmp.readAltitude(1013.25);

  Serial.print(F("Altitude: "));
  Serial.print(altitude);
  Serial.println(" m");

  return altitude;
}
