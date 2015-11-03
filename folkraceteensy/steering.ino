/*
 * Control the steering
 * Frode Lillerud, NorBot, oct 2015
 */

/*
 * Based on the sensorvalues, and current speed, calculate and set a new steering direction.
 * If there is something close up front, then go to the side with furthest distance to object.
 * If the speed is high, then just turn slightly. If speed is low, then turn hard.
 */
int calculateDirection()
{
  //Gather sensor readings, and use those to suggest new direction. Then set that direction.
  int f = getSensorDistanceInCm(SENSOR_FRONT_OUT_PIN);
  int l = getSensorDistanceInCm(SENSOR_LEFT_OUT_PIN);
  int r = getSensorDistanceInCm(SENSOR_RIGHT_OUT_PIN);
  int speed = getCurrentSpeed();


  Serial.print("F=");
  Serial.print(f);
  Serial.print("\t");
  Serial.print("L=");
  Serial.print(l);
  Serial.print("\t");
  Serial.print("R=");
  Serial.println(r);
  
  int newDirection = suggestNewDirection(f, l, r, speed);
  //Serial.print("New Direction: ");
  //Serial.println(newDirection);

  return newDirection;
}

/*
 * Based on the sensorreadings, and the current speed, calculate the new direction we should go in. 
 * Returns between -90 (hard left) and 90 (hard right) degrees.
 */
int suggestNewDirection(int frontSensorDistance, int leftSensorDistance, int rightSensorDistance, int currentSpeed)
{ 
  int newDirection = 0;
  //TODO - add smoothing to avoid erratic turning?

  if (frontSensorDistance > 100)
  {
    newDirection = 0; //Nothing ahead, go straight.
  }
  else //Use sidesensors to determine which way to turn.
  {
    
    int value = (rightSensorDistance * 100 / (leftSensorDistance + rightSensorDistance));
    //Serial.println(value);
    value = constrain(value, 0, 100);
    value = map(value, 0, 100, -80, 80); //Go from percentage to degrees
    newDirection = value;
  }

  //Compensate angle using current speed. If we're driving fast, then make smaller turns.
  if (getCurrentSpeed() > 50)
  {
    newDirection = newDirection / 2;
  }
  
  return newDirection;
}

/*
 * Turn steering to the degrees given. -90 is left, 0 is center, 90 is right.
 */
void steeringTurnTo(int degrees)
{
  int microseconds = map(degrees, -90, 90, SERVO_STEERING_MIN, SERVO_STEERING_MAX);
  microseconds = constrain(microseconds, SERVO_STEERING_MIN, SERVO_STEERING_MAX);
  servoSteering.writeMicroseconds(microseconds);
}

