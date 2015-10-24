/*
 * Methods for controlling the car.
 * The car has parts it controls, like motor, steering and sensors.
 */

boolean carEngineIsOff()
{
 return true; 
}

void carDriveForward(int speed)
{
}

void carStop()
{
  setMotorSpeed(0);
}

void carReverse(int speed)
{
  
}

/*
 * Read the front sensor, and determines which speed to use. When nothing in front, then go fast. When really close, back up.
 */
int getSuggestedGear()
{
  int minDistance = 0;
  int maxDistance = 1023;
  
  int distanceFront = analogRead(FRONT_SENSOR_PIN);
  int gear = map(distanceFront, minDistance, maxDistance, 0, 10);
  gear = constrain(gear, 0, 10);
  return gear;
}

void changeSpeed()
{
  
}

