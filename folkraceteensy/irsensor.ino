/*
 * Methods used to talk to the IR-sensors
 */


int getSensorDistanceInCm(int pin)
{
  int sensorValue = analogRead(pin);
  //Serial.println(sensorValue);
  int distance = map(sensorValue, 0, 1023, SENSOR_MAX_DISTANCE, SENSOR_MIN_DISTANCE); //TODO - the curve on the sensor is not linear.
  //distance = constrain(distance, SENSOR_MAX_DISTANCE, SENSOR_MAX_DISTANCE);

  return distance;  
}

