/*
 * Frode Lillerud, Norbot, 22.oct 2015
 * Folkrace car for Stockholm Robot championship 7.nov 2015
 */

#include <Servo.h>
#include "config.h"

const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;


void setup() {

  //Serial connection back to Arduino IDE
  Serial.begin(9600);

  //Define inputs and outputs
  pinMode(SENSOR_FRONT_EN_PIN, OUTPUT);
  pinMode(SENSOR_LEFT_EN_PIN, OUTPUT);
  pinMode(SENSOR_RIGHT_EN_PIN, OUTPUT);
  pinMode(STARTMODULE_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  //Enable the sensors
  digitalWrite(SENSOR_FRONT_EN_PIN, HIGH);
  digitalWrite(SENSOR_LEFT_EN_PIN, HIGH);
  digitalWrite(SENSOR_RIGHT_EN_PIN, HIGH);

  //Connect servos
  servoSteering.attach(SERVO_STEERING_PIN);
  servoMotor.attach(SERVO_MOTOR_PIN);

  //Listen for changes on the Startmodule
  attachInterrupt(STARTMODULE_PIN, changeStartmoduleState, CHANGE);

    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}


void loop() {

  delay(100);
  total = total - readings[readIndex];
  int distance = getSensorDistanceInCm(SENSOR_FRONT_OUT_PIN);
  readings[readIndex] = distance;
  total = total + distance;
  readIndex = readIndex + 1;
  if (readIndex >= numReadings)
    readIndex = 0;
  Serial.print(readIndex);
  average = total / numReadings;
  Serial.print("AverageDistance: ");
  Serial.println(average);
  
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println(" cm");
  return;

  startmodule_state = RUNNING; //DEBUG

  if (startmodule_state == WAITING)
  {
    carWait();
  }
  else if (startmodule_state == RUNNING)
  {
    carDrive();

    //Serial.println(GetState());
  }
  else if (startmodule_state == STOP)
  {
    //carStop();
  }

  return;
}
