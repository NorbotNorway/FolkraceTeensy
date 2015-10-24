/*
 * Frode Lillerud, Norbot, 22.oct 2015
 * Folkrace car for Stockholm Robot championship 7.nov 2015
 */

#include <Servo.h>
#include "config.h"
#include "startmodule"

//The car has ten gears. They control the direction and speed. Number is percentage.
int gearSpeeds[10] = {-100, -75, -50, -25, 0, 10, 25, 50, 75, 100};

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

  if (sm_state == WAITING || STOP)
  {
    stop();
    return;
  }

  changeSpeed();
  //changeDirection();
  setDirection();
  setSpeed();
  

  //int newDirection = car.guessBestDirection()
  //int newSpeed = car.guessBestSpeed();

  //drive(newDirection, newSpeed);
  
  //if (car.pathAheadIsClear())
  //{
//    car.drive(MOTOR_FORWARD);
//  }
  

  //Read the front sensor, and light LED accordingly
  frontSensorValue = analogRead(frontSensorOut);
  if (frontSensorValue > 512)
  {
    servoMotor.writeMicroseconds(MOTOR_STOP);
    //Serial.println("Motor running");
    //delay(30);
  }
  else
  {
    //map(50, MOTOR_STOP, MOTOR_FORWARD, 0, 100);
    servoMotor.writeMicroseconds(MOTOR_FORWARD);
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
