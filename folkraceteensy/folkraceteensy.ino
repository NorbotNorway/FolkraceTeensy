/*
 * Frode Lillerud, Norbot, 22.oct 2015
 * Folkrace car for Stockholm Robot championship 7.nov 2015
 */

#include <Servo.h>
#include "config.h"

void setup() {

  //Define inputs and outputs
  pinMode(frontSensorOut, INPUT);
  pinMode(frontSensorEnable, OUTPUT);
  pinMode(ledPin, OUTPUT);

  //Serial connection back to Arduino IDE
  Serial.begin(9600);

  //Enable the sensors
  digitalWrite(frontSensorEnable, HIGH);

  //Connect servos
  servoSteering.attach(steeringPin);
  servoMotor.attach(motorPin);
}

void loop() {

  //Read the front sensor, and light LED accordingly
  frontSensorValue = analogRead(frontSensorOut);
  if (frontSensorValue > 512)
  {
    servoMotor.writeMicroseconds(1500);
    //Serial.println("Motor running");
    //delay(30);
  }
  else
  {
    servoMotor.writeMicroseconds(1750);
    //delay(30);
  }

  //Read the side sensors, and turn the other way if object is detected
  rightSensorValue = analogRead(rightSensorOut);
  leftSensorValue = analogRead(leftSensorOut);
  //Serial.println(rightSensorValue);
  if (rightSensorValue > 512)
  {
    servoSteering.writeMicroseconds(1000);
    digitalWrite(ledPin, HIGH);
  }
  else if (leftSensorValue > 512)
  {
    servoSteering.writeMicroseconds(2000);
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    servoSteering.writeMicroseconds(1500);
    digitalWrite(ledPin, LOW);
  }

  //Serial.println(frontSensorValue);
}
