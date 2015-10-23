

/*
 * Pins
 */

//NB, I've switched OUT and ENABLE around from the Eagle schematic
int frontSensorOut = 20;
int frontSensorEnable = 21;
int leftSensorOut = 22;
int leftSensorEnable = 23;
int rightSensorOut = 18;
int rightSensorEnable = 19;
int ledPin = 13;  //Onboard LED



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
int frontSensorValue = 0;
int rightSensorValue = 0;
int leftSensorValue = 0;
int pos = 0;
