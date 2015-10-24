/*
 * Pins
 */
//NB, I've switched OUT and ENABLE around from the Eagle schematic
const int frontSensorOut = 20;
const int frontSensorEnable = 21;
const int leftSensorOut = 22;
const int leftSensorEnable = 23;
const int rightSensorOut = 18;
const int rightSensorEnable = 19;
const int ledPin = 13;  //Onboard LED
const int startmodulePin = -1; //TODO

const int steeringPin = 4;
const int motorPin = 3;

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

/*
 * Constants
 */
const int MOTOR_REVERSE = 1250;
const int MOTOR_STOP = 1500;
const int MOTOR_FORWARD = 1750;

const int SENSOR_MIN_DISTANCE = 10; //cm
const int SENSOR_MAX_DISTANCE = 150; //cm
