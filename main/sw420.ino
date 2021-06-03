int sw420_pin = 3;

void sw420_setup() {
  pinMode(sw420_pin, OUTPUT);
}

float sw420_get_vibration() {
  float vibration = digitalRead(sw420_pin);

  Serial.print(F("Vibration: "));
  Serial.println(vibration);

  return vibration;
}
