
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }
  am2320_setup();
}

void loop() {
  delay(1000);
  am2320_get_temp();
  am2320_get_hum();
}
