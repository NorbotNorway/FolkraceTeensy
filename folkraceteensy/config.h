

/*
 * Pins
 */

int frontSensorOut = 18; //Value from front sensor
int frontSensorEnable = 19;
int ledPin = 13;  //Onboard LED
int frontSensorValue = 0;

int steeringPin = 4;
int motorPin = 3;

/*
 * Classes
 */

Servo servoSteering;
Servo servoMotor;

/*
 * Variables
 */

int pos = 0;
