/*
 * Control the motor that drives the car forwards and backwards.
 */

/*
 * Speed can be from -100 to 100 percent).
 */
int _motorSpeed = 0;



int calculateMotorSpeed()
{ 
  int distance = getAverageSensorDistanceInCm(SENSOR_FRONT_OUT_PIN);
  int speed = getSpeedFromDistance(distance);

  //If we're turning, then reduce speed
  if (getCurrentDirection() < -35 || getCurrentDirection() > 35)
    speed = speed / 3;

    //Make sure that the speed we set is enough to move the car. It'll stall if the speed is too slow.
  if (speed > 0 && speed < MOTOR_MINIMUM_SPEED)
    speed = MOTOR_MINIMUM_SPEED;
  if (speed < 0 && speed * -1 > MOTOR_MINIMUM_SPEED)
    speed = MOTOR_MINIMUM_SPEED * -1;

  //Also, make sure we don't go faster than the maximum speed of the car.
  if (speed > 0) //Going forward
    speed = constrain(speed, MOTOR_MINIMUM_SPEED, MOTOR_MAXIMUM_SPEED);

  return speed;
}

int getSpeedFromDistance(int distance)
{
  const int min_distance = 10; //cm
  const int max_distance = 150; //cm

  distance = constrain(distance, min_distance, max_distance);

  int speed;

  if (distance >= 80)
    speed = 60;
  else if (distance < 80 && distance >= 15)
    speed =  40;
  else if (distance < 15)
    speed = -50; 
  else
    speed = -100;

  return speed;
}

int getCurrentSpeed()
{
  return _motorSpeed;
}

void motorSetSpeed(int speedPercentage)
{
  _motorSpeed = speedPercentage;
  
  int microseconds = map(speedPercentage, -100, 100, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  microseconds = constrain(microseconds, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  
  servoMotor.writeMicroseconds(microseconds); 
}
