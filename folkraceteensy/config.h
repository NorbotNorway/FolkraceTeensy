/*
 * Pins
 */
//NB, I've switched OUT and ENABLE around from the Eagle schematic
const int SENSOR_FRONT_OUT_PIN = 20;
const int SENSOR_FRONT_EN_PIN = 21;
const int SENSOR_LEFT_OUT_PIN = 22;
const int SENSOR_LEFT_EN_PIN = 23;
const int SENSOR_RIGHT_OUT_PIN = 18;
const int SENSOR_RIGHT_EN_PIN = 19;
const int LED_PIN = 13;  //Onboard LED
const int STARTMODULE_PIN = 5;

const int SERVO_STEERING_PIN = 4;
const int SERVO_MOTOR_PIN = 3;

const int LED_SLOW_BLINK = 750; //ms
const int LED_FAST_BLINK = 200; //ms

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

const int SERVO_MOTOR_MAX = 1900;
const int SERVO_MOTOR_MIN = 1100;

const int SENSOR_MIN_DISTANCE = 10; //cm
const int SENSOR_MAX_DISTANCE = 150; //cm

const int SERVO_STEERING_MIN = 1100; //us
const int SERVO_STEERING_MAX = 1900; //us

 enum startmoduleStates {
  WAITING,
  RUNNING,
  STOP
 };

 volatile startmoduleStates startmodule_state = WAITING;
