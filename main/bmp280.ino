#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// define device I2C address: 0x76 or 0x77 (0x77 is library default address)
const int BMP280_I2C_ADDRESS = 0x76;

const int BMP_SCK  = 13;
const int BMP_MISO = 12;
const int BMP_MOSI = 11;
const int BMP_CS   = 10;
const float SEALEVELPRESSURE_HPA = 1013.25;

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void bmp280_begin() {
  if (!bmp.begin(BMP280_I2C_ADDRESS)) {
    Serial.println(F("BMP280 sensor not found."));
  }
  else {
    bmp.setSampling(
      Adafruit_BMP280::MODE_NORMAL,     // Operating Mode
      Adafruit_BMP280::SAMPLING_X2,     // Temperature oversampling
      Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
      Adafruit_BMP280::FILTER_X16,      // Filtering
      Adafruit_BMP280::STANDBY_MS_500   // Standby time
    );
  }
}

float bmp280_get_temperature() {
  float temperature = bmp.readTemperature();

  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(" °C");

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
  float altitude = bmp.readAltitude(SEALEVELPRESSURE_HPA); // Atmospheric pressure at sea level

  Serial.print(F("Altitude: "));
  Serial.print(altitude);
  Serial.println(" m");

  return altitude;
}
