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
    digitalWrite(ledPin, HIGH);
    servoMotor.writeMicroseconds(1500);
    //Serial.println("Motor running");
    //delay(30);
  }
  else
  {
    servoMotor.writeMicroseconds(175
    30);
    digitalWrite(ledPin, LOW);
    //delay(30);
  }

  //Steering goes back and forth.
//  for (pos = 0; pos <= 180; pos += 1)
//  {
//    Serial.println(pos);
//    servoMotor.write(pos);
//    servoSteering.write(pos);
//    delay(100); 
//  }
//  for (pos = 180; pos >= 0; pos -= 1)
//  {
//    Serial.println(pos);
//    servoSteering.write(pos);
//    delay(100);
//  }

  Serial.println(frontSensorValue);
}
