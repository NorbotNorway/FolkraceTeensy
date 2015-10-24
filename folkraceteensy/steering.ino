/*
 * Control the steering
 * Frode Lillerud, NorBot, oct 2015
 */

/*
 * Based on the sensorvalues, and current speed, calculate and set a new steering direction.
 * If there is something close up front, then go to the side with furthest distance to object.
 * If the speed is high, then just turn slightly. If speed is low, then turn hard.
 */
void setDirection()
{
  //Gather sensor readings, and use those to suggest new direction. Then set that direction.
  int f = getSensorDistanceInCm(SENSOR_FRONT_PIN);
  int l = getSensorDistanceInCm(SENSOR_LEFT_PIN);
  int r = getSensorDistanceInCm(SENSOR_RIGHT_PIN);
  int speed = getCurrentSpeed();

  int newDirection = suggestNewDirection(f, l, r, speed);

  turnTo(newDirection);
}

/*
 * The new direction we should go in. Returns between -90 (hard left) and 90 (hard right) degrees.
 */
int suggestNewDirection(int frontSensorDistance, int leftSensorDistance, int rightSensorDistance, int currentSpeed)
{ 
  //TODO
  //TODO - add smoothing to avoid erratic turning?
  int newDirection = 40; //todo, random now
  return newDirection;
}

void turnTo(int degrees)
{
  //TODO - turn steering to the degrees given. -90 is left, 0 is senter, 90 is right.
}

