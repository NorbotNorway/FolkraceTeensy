/*
 * 
 */
/*
 enum startmoduleStates {
  WAITING,
  RUNNING,
  STOP
 };
*/



int startmoduleCheckState()
{
  bool sm_value = digitalRead(STARTMODULE_PIN);
  if (startmodule_state == WAITING && sm_value == true)
    startmodule_state = RUNNING;
  else if (startmodule_state == RUNNING && sm_value == false)
    startmodule_state = STOP;

  return 0; //? Does this need to be an int??
}

void changeStartmoduleState()
{
  bool sm_value = digitalRead(STARTMODULE_PIN);
  if (startmodule_state == WAITING && sm_value == true)
    startmodule_state = RUNNING;
  else if (startmodule_state == RUNNING && sm_value == false)
    startmodule_state = STOP;

    Serial.println("INTERRUPT!");
}
