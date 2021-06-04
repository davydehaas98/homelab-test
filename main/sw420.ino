const int SW420_DIGITAL = 5;

void sw420_setup() {
  pinMode(SW420_DIGITAL, INPUT);
}

float sw420_get_vibration() {
  float vibration = digitalRead(SW420_DIGITAL);

  Serial.print(F("Vibration: "));
  Serial.println(vibration);

  return vibration;
}
