/*
 * Control the motor that drives the car forwards and backwards.
 */

/*
 * Speed can be from -100 to 100 percent).
 */

int _motorSpeed = 0;

void motorSetSpeed(int speedPercentage)
{
  _motorSpeed = speedPercentage;
  
  int microseconds = map(speedPercentage, -100, 100, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  microseconds = constrain(microseconds, SERVO_MOTOR_MIN, SERVO_MOTOR_MAX);
  
  servoMotor.writeMicroseconds(microseconds); 
}

int getCurrentSpeed()
{
  return _motorSpeed;
}

