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
  const int min_distance = 10; //cm
  const int max_distance = 150; //cm
  
  int distance = getAverageSensorDistanceInCm(SENSOR_FRONT_OUT_PIN);
//  distance = rollingAverage(historyArray, 10, distance);
  
  distance = constrain(distance, min_distance, max_distance);
  //distance = mavg(distance);
  Serial.print("Distance: ");
  Serial.println(distance);

  int speed = getSpeedFromDistance(distance);
  
  Serial.print("Speed:");
  Serial.println(speed);

  return speed;
}

int getSpeedFromDistance(int distance)
{
  const int min_distance = 10; //cm
  const int max_distance = 150; //cm

  distance = constrain(distance, min_distance, max_distance);

  if (distance >= 30)
    return 50;
  else if (distance < 30 && distance >= 20)
    return 35;
  else if (distance < 20)
    return -35; 
  else
    return 100;
  
  //return map(distance, min_distance, max_distance, 0, 100);
}

int getCurrentSpeed()
{
  return _motorSpeed;
}

