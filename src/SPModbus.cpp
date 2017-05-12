

#include <ArduinoJson.h>

#include "SPModbus.h"

char * SPModbus::getAllInJson()
{
   //StaticJsonBuffer<200> jsonBuffer;
  DynamicJsonBuffer  jsonBuffer;

  JsonObject& root = jsonBuffer.createObject();

  uint16_t* data = readAllDiscreteInputs();

  root["VERSION"] = data[VERSION];
  root["CONTROL_CLP"] = data[CONTROL_CLP];
  root["DEFROST_MODE"] = data[DEFROST_MODE];
  root["EXT_ENGINE_STATUS"] = data[EXT_ENGINE_STATUS];
  root["IMP_ENGINE_STATUS"] = data[IMP_ENGINE_STATUS];
  root["T_IN_DEVICE_STATUS"] = data[T_IN_DEVICE_STATUS];
  root["T_OUT_DEVICE_STATUS"] = data[T_OUT_DEVICE_STATUS];
  root["T_EXT_DEVICE_STATUS"] = data[T_EXT_DEVICE_STATUS];
  root["T_IMP_DEVICE_STATUS"] = data[T_IMP_DEVICE_STATUS];
  root["FILTER_STATUS_ALARM"] = data[FILTER_STATUS_ALARM];
  delete[] data;

  data = readAllCoils();
  root["PRE_HEAT_BATT"] = data[PRE_HEAT_BATT];
  root["POST_HEAT_BATT"] = data[POST_HEAT_BATT];
  root["CONT_LIB_POT"] = data[CONT_LIB_POT];
  root["VERSION_SELECTION"] = data[VERSION_SELECTION];
  root["MODE_ACTIVATION"] = data[MODE_ACTIVATION];
  root["AUTO_BAYPASS_CONTROL"] = data[AUTO_BAYPASS_CONTROL];
  root["MANUAL_BYPASS"] = data[MANUAL_BYPASS];
  root["FILTER_ALARM_RESET"] = data[FILTER_ALARM_RESET];
  root["FACTORY_RESET"] = data[FACTORY_RESET];
  delete[] data;

  data = readAllInputRegisters();
  root["CENTRAL_UNIT_VERSION"] = data[CENTRAL_UNIT_VERSION];
  root["REMOTE_VERSION"] = data[REMOTE_VERSION];
  root["PROGRAM_UNIT_VERSION"] = data[PROGRAM_UNIT_VERSION];
  root["TWIN_FLOW_TYPE"] = data[TWIN_FLOW_TYPE];
  root["ADJUSTEMENT_TYPE"] = data[ADJUSTEMENT_TYPE];
  root["FLOW_GAP"] = data[FLOW_GAP];
  root["MIN_FLOW"] = data[MIN_FLOW];
  root["MAX_FLOW"] = data[MAX_FLOW];
  root["MAX_FLOW_FREE_COOLING"] = data[MAX_FLOW_FREE_COOLING];
  root["ACTUAL_FLOW"] = data[ACTUAL_FLOW];
  root["SUPPLY_VOLTAGE"] = data[SUPPLY_VOLTAGE];
  root["EXT_ENGINE_REVS"] = data[EXT_ENGINE_REVS];
  root["IMP_ENGINE_REVS"] = data[IMP_ENGINE_REVS];
  root["T_INT"] = data[T_INT];
  root["T_OUT"] = data[T_OUT];
  root["T_EXT"] = data[T_EXT];
  root["T_IMP"] = data[T_IMP];
  root["BYPASS_STATUS"] = data[BYPASS_STATUS];
  root["PRE_HEAT_BATT_STATUS"] = data[PRE_HEAT_BATT_STATUS];
  root["POST_HEAT_BATT_STATUS"] = data[POST_HEAT_BATT_STATUS];
  root["FILTER_ALARM_TIMER"] = data[FILTER_ALARM_TIMER];
  root["PRE_HEAT_BATT_T_IN"] = data[PRE_HEAT_BATT_T_IN];
  root["PRE_HEAT_BATT_T_OUT"] = data[PRE_HEAT_BATT_T_OUT];
  root["POST_HEAT_BATT_T_IN"] = data[POST_HEAT_BATT_T_IN];
  root["POST_HEAT_BATT_T_OUT"] = data[POST_HEAT_BATT_T_OUT];
  delete[] data;

  data = readAllHoldingRegisters();
  root["MODBUS_SLAVE_NODE"] = data[MODBUS_SLAVE_NODE];
  root["MODBUS_BAUDRATE"] = data[MODBUS_BAUDRATE];
  root["FLOW_GAP_SELECTION"] = data[FLOW_GAP_SELECTION];
  root["MIN_FLOW_SELECTION"] = data[MIN_FLOW_SELECTION];
  root["MAX_FLOW_SELECTION"] = data[MAX_FLOW_SELECTION];
  root["MAX_FLOW_FREE_COOLING"] = data[MAX_FLOW_FREE_COOLING];
  root["FLOW_RATE"] = data[FLOW_RATE];
  root["MIN_RATE_V"] = data[MIN_RATE_V];
  root["MAX_RATE_V"] = data[MAX_RATE_V];
  root["BYPASS_AUTO_T_EXT"] = data[BYPASS_AUTO_T_EXT];
  root["BYPASS_AUTO_T_INT"] = data[BYPASS_AUTO_T_INT];
  root["BYPASS_MANUAL_TIMEOUT"] = data[BYPASS_MANUAL_TIMEOUT];
  root["PRE_HEAT_BATT_T_ON"] = data[PRE_HEAT_BATT_T_ON];
  root["PRE_HEAT_BATT_T_OFF"] = data[PRE_HEAT_BATT_T_OFF];
  root["POST_HEAT_BATT_T_ON"] = data[POST_HEAT_BATT_T_ON];
  root["POST_HEAT_BATT_T_OFF"] = data[POST_HEAT_BATT_T_OFF];
  root["FILTER_ALARM_TIMER_SELECTION"] = data[FILTER_ALARM_TIMER_SELECTION];
  delete[] data;

  char* output = new char;
  root.printTo(output);

  return output;
}

//is in coils
void SPModbus::writeManualBypass(uint8_t u8State)
{
  writeSingleCoil(MANUAL_BYPASS, u8State);
}

//is in holding registers
void SPModbus::writeFLowRate(uint16_t u16WriteValue)
{
  writeSingleRegister(FLOW_RATE, u16WriteValue);
}


/**  PRIVATE FUNCTIONS **/
uint16_t* SPModbus::readAllCoils()
{
  uint8_t j, result;
  uint16_t* data = new uint16_t[13];

  result = readCoils(0, 13);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j < 13; j++)
    {
     data[j] = getResponseBuffer(j);
    }
  }

  return data;
}

uint16_t* SPModbus::readAllDiscreteInputs()
{
  uint8_t j, result;
  uint16_t* data = new uint16_t[14];

  result = readCoils(0, 14);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j < 14; j++)
    {
     data[j] = getResponseBuffer(j);
    }
  }

  return data;
}

uint16_t* SPModbus::readAllHoldingRegisters()
{
  uint8_t j, result;
  uint16_t* data = new uint16_t[31];

  result = readCoils(0, 31);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j < 31; j++)
    {
     data[j] = getResponseBuffer(j);
    }
  }

  return data;
}

uint16_t* SPModbus::readAllInputRegisters()
{
  uint8_t j, result;
  uint16_t* data = new uint16_t[40];

  result = readCoils(1, 40);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j < 40; j++)
    {
     data[j] = getResponseBuffer(j);
    }
  }

  return data;
}
