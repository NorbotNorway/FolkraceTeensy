/*
 * Control the teensy LED
 */

ledBlink(int speed)
{
  digitalWrite(LED_PIN, HIGH);
  delay(speed);
  digitalWrite(LED_PIN, LOW);
  delay(speed);
}

