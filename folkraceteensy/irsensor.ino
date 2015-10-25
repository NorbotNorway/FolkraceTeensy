/*
 * Methods used to talk to the IR-sensors
 */


int getSensorDistanceInCm(int pin)
{
  int sensorValue = analogRead(pin);
  int distance = map(sensorValue, 0, 1024, SENSOR_MIN_DISTANCE, SENSOR_MAX_DISTANCE); //TODO - the curve on the sensor is not linear.
  distance = constrain(distance, SENSOR_MIN_DISTANCE, SENSOR_MAX_DISTANCE);

  return distance;  
}

