/*
 * Frode Lillerud, Norbot, 22.oct 2015
 * Folkrace car for Stockholm Robot championship 7.nov 2015
 */

#include <Servo.h>
#include "config.h"
//#include "startmodule"
//#include "car"
//#include "motor"
//#include "steering"

//The car has ten gears. They control the direction and speed. Number is percentage.
//int gearSpeeds[10] = {-100, -75, -50, -25, 0, 10, 25, 50, 75, 100};

void setup() {

  //Define inputs and outputs
  pinMode(SENSOR_FRONT_EN_PIN, OUTPUT);
  pinMode(SENSOR_LEFT_EN_PIN, OUTPUT);
  pinMode(SENSOR_RIGHT_EN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  //Serial connection back to Arduino IDE
  Serial.begin(9600);

  //Enable the sensors and startmodule
  digitalWrite(SENSOR_FRONT_EN_PIN, HIGH);
  digitalWrite(SENSOR_LEFT_EN_PIN, HIGH);
  digitalWrite(SENSOR_RIGHT_EN_PIN, HIGH);

  //Connect servos
  servoSteering.attach(SERVO_STEERING_PIN);
  servoMotor.attach(SERVO_MOTOR_PIN);

  //Listen for changes on the Startmodule
  attachInterrupt(STARTMODULE_PIN, changeStartmoduleState, RISING);
}

void loop() {

  startmoduleCheckState();

  if (startmodule_state == WAITING)
  {
    carWait();
  }
  else if (startmodule_state == RUNNING)
  {
    carDrive();
  }
  else if (startmodule_state == STOP)
  {
    carStop();
  }
  else
  {
    Serial.println("No StartModule state set");
  }
  

  //int newDirection = car.guessBestDirection()
  //int newSpeed = car.guessBestSpeed();

  //drive(newDirection, newSpeed);
  
  //if (car.pathAheadIsClear())
  //{
//    car.drive(MOTOR_FORWARD);
//  }
  /*

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
  */
}
