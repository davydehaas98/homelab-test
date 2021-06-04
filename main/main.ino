void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }
//  esp6288_setup();
//  sw420_setup();
}

void loop() {
  am2320_begin();
  am2320_get_temperature();
  am2320_get_humidity();
  
//  mq9_detect_gas();
//  mq135_detect_gas();
  
//  bmp280_begin();
//  bmp280_get_temperature();
//  bmp280_get_pressure();
//  bmp280_get_altitude();
  
//  sw420_get_vibration();
  delay(1000);
}
