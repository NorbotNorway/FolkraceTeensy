/*
 * Control the motor that drives the car forwards and backwards.
 */

/*
 * Speed can be from -100 to 100 percent).
 */
int _motorSpeed = 0;

void motorSetSpeed(int speedPercentage)
{
  if (speedPercentage < 10 && speedPercentage > -10)
    speedPercentage = 0;
  
  _motorSpeed = speedPercentage;
  
  int microseconds = map(speedPercentage, -100, 100, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  microseconds = constrain(microseconds, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  
  servoMotor.writeMicroseconds(microseconds); 
}

int calculateMotorSpeed()
{
  //const int min_distance = 10; //cm
  //const int max_distance = 150; //cm
  
  int distance = getAverageSensorDistanceInCm(SENSOR_FRONT_OUT_PIN);
  
  //distance = constrain(distance, min_distance, max_distance);
  //Serial.print("Distance: ");
  //Serial.println(distance);

  int speed = getSpeedFromDistance(distance);

  //If we're turning, then reduce speed
  if (getCurrentDirection() < -30 || getCurrentDirection() > 30)
    speed = speed / 2;

  return speed;
}

int getSpeedFromDistance(int distance)
{
  const int min_distance = 10; //cm
  const int max_distance = 150; //cm

  distance = constrain(distance, min_distance, max_distance);

  int speed;

  if (distance >= 35)
    speed = 70;
  else if (distance < 35 && distance >= 20)
    speed =  30;
  else if (distance < 20)
    speed = -35; 
  else
    speed = 100;

  return speed;
}

int getCurrentSpeed()
{
  return _motorSpeed;
}

