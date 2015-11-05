/*
 * Methods for controlling the car.
 * The car has parts it controls, like motor, steering and sensors.
 */

void carWait()
{
  motorSetSpeed(0);
  steeringTurnTo(0);
  ledBlink(LED_SLOW_BLINK);
}

void carDrive()
{
  //Figure out best direction to go. Continously calculate what the best speed and direction is.
  int speed = calculateMotorSpeed();
  int direction = calculateDirection();

  motorSetSpeed(speed);
  steeringTurnTo(direction);
}

void carStop()
{
  ledBlink(LED_FAST_BLINK);
  motorSetSpeed(0);
  steeringTurnTo(0);
}

/*
 * Read the front sensor, and determines which speed to use. When nothing in front, then go fast. When really close, back up.
 */
 /*
int getSuggestedGear()
{
  int minDistance = 0;
  int maxDistance = 1023;
  
  int distanceFront = analogRead(SENSOR_FRONT_OUT_PIN);
  int gear = map(distanceFront, minDistance, maxDistance, 0, 10);
  gear = constrain(gear, 0, 10);
  return gear;
}
*/
