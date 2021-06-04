// CH4, CO & LPG
// https://wiki.seeedstudio.com/Grove-Gas_Sensor-MQ9/
// https://www.hackster.io/electropeak/how-to-calibrate-use-mq9-gas-sensor-w-arduino-e93cb1

const int MQ9_ANALOG = A0;

void mq9_calibration() {
  // Run the sensor for 15 minutes to get an accurate R0 value.
  float sensor_value = 0;

  // Get average
  for (int x = 0 ; x < 100 ; x++) {
    sensor_value = sensor_value + analogRead(MQ9_ANALOG);
  }

  sensor_value = sensor_value / 100.0;

  float sensor_volt = (sensor_value / 1024) * 5.0;
  float Rs_air = (5.0 - sensor_volt) / sensor_volt; // Internal resistance based on gas concentration
  float R0 = Rs_air / 9.9; // The ratio of Rs/R0 is 9.9 in LPG gas

  Serial.print("Sensor Voltage: ");
  Serial.print(sensor_volt);
  Serial.println("V");
  Serial.print("R0: ");
  Serial.println(R0);
}

float mq9_detect_gas() {
  float R0 = 1.90; // Replace R0 with the value found in the configuration
  float sensor_value = analogRead(MQ9_ANALOG);
  float sensor_volt = sensor_value / 1024 * 5.0; // RL 5k Ohm
  float Rs_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  float ratio = Rs_gas / R0; // ratio Rs/R0

  Serial.print("Sensor Voltage: ");
  Serial.print(sensor_volt);
  Serial.println("V");
  Serial.print("Rs gas: ");
  Serial.println(Rs_gas);
  Serial.print("Rs/R0: ");
  Serial.println(ratio);

  return sensor_volt;
}
