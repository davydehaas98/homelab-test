// CO2, NH3, NOx, alcohol, benzene, smoke etc.
// https://microcontrollerslab.com/interfacing-mq-135-gas-sensor-arduino/
// https://www.codrey.com/electronic-circuits/how-to-use-mq-135-gas-sensor/
const int MQ135_ANALOG = A0;

float mq135_detect_gas() {
  // approx. 100 - 150 = Normal air
  // approx. 700 = Alcohol
  // approx. 750 = Lighter gas
  float sensor_value = analogRead(MQ135_ANALOG);

  Serial.print("Air Quality: ");
  Serial.println(sensor_value);

  return sensor_value;
}
