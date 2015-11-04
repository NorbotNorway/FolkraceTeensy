/*
 * Methods used to talk to the IR-sensors
 */



const int numReadings = 10;
const int pinCount = 25;
int readings[pinCount][numReadings]; //Each "Column" contains the sensorreadings. Each "Row" is used for the different pins.
/*
 * PIN0 - [reading 1], [reading 2], [reading 3], etc...
 * PIN1 - [reading 1], [reading 2], [reading 3], etc...
 * PIN2 - [reading 1], [reading 2], [reading 3], etc...
 * etc...
 */
int readIndexes[pinCount];
int totals[pinCount]; //The sum from each "Row" pr pin.

//Calls getSensorDistanceInCm, but returns an average of the last X readings from that pin.
int getAverageSensorDistanceInCm(int pin)
{
  totals[pin] = totals[pin] - readings[readIndexes[pin]][pin]; //Remove the oldest sensorreading for this pin.
  int value = getSensorDistanceInCm(pin);   //Get a new value from the sensor.
  readings[readIndexes[pin]][pin] = value; //Add the value to the matrix
  totals[pin] = totals[pin] + value;        //Calculate the total
  readIndexes[pin] = readIndexes[pin] + 1;
  if (readIndexes[pin] > numReadings)
    readIndexes[pin] = 0;

  return totals[pin] / numReadings;
}


//Get the distance for the given sensor in centimeters.
int getSensorDistanceInCm(int pin)
{
  int sensorValue = analogRead(pin);

  int in[] =  {100,120,130,150,170,200,220,240,250,280,300,350,380,420,480,560,720,1000}; //Needs to be increasing
  int out[] = {150,140,130,120,110,100, 90, 80, 70, 60, 50, 40, 35, 30, 25, 20, 15,  10};

  int distance = multiMap(sensorValue, in, out, 18);
  
  return distance;  
}

// note: the _in array should have increasing values
//http://playground.arduino.cc/Main/MultiMap
int multiMap(int val, int* _in, int* _out, uint8_t size)
{
  // take care the value is within range
  // val = constrain(val, _in[0], _in[size-1]);
  if (val <= _in[0]) return _out[0];
  if (val >= _in[size-1]) return _out[size-1];

  // search right interval
  uint8_t pos = 1;  // _in[0] allready tested
  while(val > _in[pos]) pos++;

  // this will handle all exact "points" in the _in array
  if (val == _in[pos]) return _out[pos];

  // interpolate in the right segment for the rest
  return (val - _in[pos-1]) * (_out[pos] - _out[pos-1]) / (_in[pos] - _in[pos-1]) + _out[pos-1];
}
