/*
 * Control the teensy LED
 */

void ledBlink(int speed)
{
  digitalWrite(LED_PIN, HIGH);
  delay(speed);
  digitalWrite(LED_PIN, LOW);
  delay(speed);
}

