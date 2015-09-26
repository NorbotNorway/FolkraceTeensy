int frontSensorPin = 14;
int ledPin = 13;
int frontSensorValue = 0;

void setup() {
  pinMode(frontSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  frontSensorValue = analogRead(frontSensorPin);

  if (frontSensorValue > 512)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);

  Serial.println(frontSensorValue);
}
