/*
 * Methods used to talk to the IR-sensors
 */


int getSensorDistanceInCm(int pin)
{
  int sensorValue = analogRead(pin);

  Serial.print("sensorValue:  ");
  Serial.println(sensorValue);
  int in[] =  {100,120,130,150,170,200,220,240,250,280,300,350,380,420,480,560,720,1000}; //Needs to be increasing
  int out[] = {150,140,130,120,110,100, 90, 80, 70, 60, 50, 40, 35, 30, 25, 20, 15,  10};

  int distance = multiMap(sensorValue, in, out, 18);
  
  //Serial.print("Distance: ");
  //Serial.println(distance);
  //Serial.println("cm");
  //int distance = map(sensorValue, 0, 1023, SENSOR_MIN_DISTANCE, SENSOR_MAX_DISTANCE); //TODO - the curve on the sensor is not linear.

  

  //distance = multiMap(distance, in, out, 15);
  
  //distance = constrain(distance, SENSOR_MAX_DISTANCE, SENSOR_MAX_DISTANCE);

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
