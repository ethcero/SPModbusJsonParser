

#include <ArduinoJson.h>
#include "SPModbus.h"

uint8_t SPModbus::getCoilsInJson(String &output)
{
  uint8_t result;
  uint16_t coils[14];
  result = readAllCoils(coils);

  if(result == ku8MBSuccess)
  {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["PRE_HEAT_BATT"] = coils[PRE_HEAT_BATT];
    root["POST_HEAT_BATT"] = coils[POST_HEAT_BATT];
    root["CONT_LIB_POT"] = coils[CONT_LIB_POT];
    root["VERSION_SELECTION"] = coils[VERSION_SELECTION];
    root["MODE_ACTIVATION"] = coils[MODE_ACTIVATION];
    root["AUTO_BAYPASS_CONTROL"] = coils[AUTO_BAYPASS_CONTROL];
    root["MANUAL_BYPASS"] = coils[MANUAL_BYPASS];
    root["FILTER_ALARM_RESET"] = coils[FILTER_ALARM_RESET];
    root["FACTORY_RESET"] = coils[FACTORY_RESET];
    root.printTo(output);
  }
  return result;
}

uint8_t SPModbus::getInputRegistersInJson(String &output)
{
  uint8_t result;
  uint16_t inputRegisters[41];
  result = readAllInputRegisters(inputRegisters);

  if(result == ku8MBSuccess)
  {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["CENTRAL_UNIT_VERSION"] = inputRegisters[CENTRAL_UNIT_VERSION];
    root["REMOTE_VERSION"] = inputRegisters[REMOTE_VERSION];
    root["PROGRAM_UNIT_VERSION"] = inputRegisters[PROGRAM_UNIT_VERSION];
    root["TWIN_FLOW_TYPE"] = inputRegisters[TWIN_FLOW_TYPE];
    root["ADJUSTEMENT_TYPE"] = inputRegisters[ADJUSTEMENT_TYPE];
    root["FLOW_GAP"] = inputRegisters[FLOW_GAP];
    root["MIN_FLOW"] = inputRegisters[MIN_FLOW];
    root["MAX_FLOW"] = inputRegisters[MAX_FLOW];
    root["MAX_FLOW_FREE_COOLING"] = inputRegisters[MAX_FLOW_FREE_COOLING];
    root["ACTUAL_FLOW"] = inputRegisters[ACTUAL_FLOW];
    root["SUPPLY_VOLTAGE"] = inputRegisters[SUPPLY_VOLTAGE];
    root["EXT_ENGINE_REVS"] = inputRegisters[EXT_ENGINE_REVS];
    root["IMP_ENGINE_REVS"] = inputRegisters[IMP_ENGINE_REVS];
    root["T_INT"] = inputRegisters[T_INT];
    root["T_OUT"] = inputRegisters[T_OUT];
    root["T_EXT"] = inputRegisters[T_EXT];
    root["T_IMP"] = inputRegisters[T_IMP];
    root["BYPASS_STATUS"] = inputRegisters[BYPASS_STATUS];
    root["PRE_HEAT_BATT_STATUS"] = inputRegisters[PRE_HEAT_BATT_STATUS];
    root["POST_HEAT_BATT_STATUS"] = inputRegisters[POST_HEAT_BATT_STATUS];
    root["FILTER_ALARM_TIMER"] = inputRegisters[FILTER_ALARM_TIMER];
    root["PRE_HEAT_BATT_T_IN"] = inputRegisters[PRE_HEAT_BATT_T_IN];
    root["PRE_HEAT_BATT_T_OUT"] = inputRegisters[PRE_HEAT_BATT_T_OUT];
    root["POST_HEAT_BATT_T_IN"] = inputRegisters[POST_HEAT_BATT_T_IN];
    root["POST_HEAT_BATT_T_OUT"] = inputRegisters[POST_HEAT_BATT_T_OUT];
    root.printTo(output);
  }
  return result;
}


uint8_t SPModbus::getHoldingRegistersInJson(String &output)
{
  uint8_t result;
  uint16_t holdingRegisters[32];
  result = readAllHoldingRegisters(holdingRegisters);

  if(result == ku8MBSuccess)
  {
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["MODBUS_SLAVE_NODE"] = holdingRegisters[MODBUS_SLAVE_NODE];
    root["MODBUS_BAUDRATE"] = holdingRegisters[MODBUS_BAUDRATE];
    root["FLOW_GAP_SELECTION"] = holdingRegisters[FLOW_GAP_SELECTION];
    root["MIN_FLOW_SELECTION"] = holdingRegisters[MIN_FLOW_SELECTION];
    root["MAX_FLOW_SELECTION"] = holdingRegisters[MAX_FLOW_SELECTION];
    root["MAX_FLOW_FREE_COOLING"] = holdingRegisters[MAX_FLOW_FREE_COOLING];
    root["FLOW_RATE"] = holdingRegisters[FLOW_RATE];
    root["MIN_RATE_V"] = holdingRegisters[MIN_RATE_V];
    root["MAX_RATE_V"] = holdingRegisters[MAX_RATE_V];
    root["BYPASS_AUTO_T_EXT"] = holdingRegisters[BYPASS_AUTO_T_EXT];
    root["BYPASS_AUTO_T_INT"] = holdingRegisters[BYPASS_AUTO_T_INT];
    root["BYPASS_MANUAL_TIMEOUT"] = holdingRegisters[BYPASS_MANUAL_TIMEOUT];
    root["PRE_HEAT_BATT_T_ON"] = holdingRegisters[PRE_HEAT_BATT_T_ON];
    root["PRE_HEAT_BATT_T_OFF"] = holdingRegisters[PRE_HEAT_BATT_T_OFF];
    root["POST_HEAT_BATT_T_ON"] = holdingRegisters[POST_HEAT_BATT_T_ON];
    root["POST_HEAT_BATT_T_OFF"] = holdingRegisters[POST_HEAT_BATT_T_OFF];
    root["FILTER_ALARM_TIMER_SELECTION"] = holdingRegisters[FILTER_ALARM_TIMER_SELECTION];
    root.printTo(output);
  }
  return result;
}

uint8_t SPModbus::getDiscreteInputsInJson(String &output)
{
  uint8_t result;
  uint16_t discreteInputs[15];
  result = readAllDiscreteInputs(discreteInputs);

  if(result == ku8MBSuccess)
  {
    DynamicJsonBuffer jsonBuffer;

    JsonObject& root = jsonBuffer.createObject();

    root["VERSION"] = discreteInputs[VERSION];
    root["CONTROL_CLP"] = discreteInputs[CONTROL_CLP];
    root["DEFROST_MODE"] = discreteInputs[DEFROST_MODE];
    root["EXT_ENGINE_STATUS"] = discreteInputs[EXT_ENGINE_STATUS];
    root["IMP_ENGINE_STATUS"] = discreteInputs[IMP_ENGINE_STATUS];
    root["T_IN_DEVICE_STATUS"] = discreteInputs[T_IN_DEVICE_STATUS];
    root["T_OUT_DEVICE_STATUS"] = discreteInputs[T_OUT_DEVICE_STATUS];
    root["T_EXT_DEVICE_STATUS"] = discreteInputs[T_EXT_DEVICE_STATUS];
    root["T_IMP_DEVICE_STATUS"] = discreteInputs[T_IMP_DEVICE_STATUS];
    root["FILTER_STATUS_ALARM"] = discreteInputs[FILTER_STATUS_ALARM];
    root.printTo(output);
  }
  return result;
}


//is in coils
uint8_t SPModbus::writeManualBypass(uint8_t u8State)
{
  return writeSingleCoil(MANUAL_BYPASS, u8State);
}

uint8_t SPModbus::writeActivationMode(uint8_t u8State)
{
  return writeSingleCoil(MODE_ACTIVATION, u8State);
}

//is in holding registers
uint8_t SPModbus::writeFLowRate(uint8_t u8State)
{
  return writeSingleRegister(FLOW_RATE, u8State);
}

uint8_t SPModbus::writeFilterReset(uint8_t u8State)
{
  return writeSingleCoil(FILTER_ALARM_RESET, u8State);
}

uint8_t SPModbus::writeRawCoils(int number, int data)
{
  return writeSingleCoil(number, data);
}

uint8_t SPModbus::writeRawHoldingRegisters(int number, int data)
{
  return writeSingleRegister(number, data);
}


/**  PRIVATE FUNCTIONS **/

uint8_t SPModbus::readAllCoils(uint16_t out[])
{
  uint8_t j, result;
  result = readCoils(0, 13);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j <= 13; j++)
    {
     out[j] = getResponseBuffer(j);
    //  Serial.print("pos: ");
    //  Serial.print(j);
    //  Serial.print(" => ");
    //  Serial.println(out[j]);
    }
  }
  clearResponseBuffer();
  clearTransmitBuffer();
  return result;
}

uint8_t SPModbus::readAllDiscreteInputs(uint16_t out[])
{
  uint8_t j, result;
  result = readDiscreteInputs(0, 14);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j <= 14; j++)
    {
     out[j] = getResponseBuffer(j);
    //  Serial.print("pos: ");
    //  Serial.print(j);
    //  Serial.print(" => ");
    //  Serial.println(out[j]);
    }
  }
  clearResponseBuffer();
  clearTransmitBuffer();
  return result;
}

uint8_t SPModbus::readAllHoldingRegisters(uint16_t out[])
{
  uint8_t j, result;
  result = readHoldingRegisters(0, 31);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j <= 31; j++)
    {
     out[j] = getResponseBuffer(j);
    //  Serial.print("pos: ");
    //  Serial.print(j);
    //  Serial.print(" => ");
    //  Serial.println(out[j]);
    }
  }
  clearResponseBuffer();
  clearTransmitBuffer();
  return result;
}

uint8_t SPModbus::readAllInputRegisters(uint16_t out[])
{
  uint8_t j, result;
  result = readInputRegisters(0, 40);
  if (result == ku8MBSuccess)
  {
    for (j = 0; j <= 40; j++)
    {

     out[j] = getResponseBuffer(j);
    //  Serial.print("pos: ");
    //  Serial.print(j);
    //  Serial.print(" => ");
    //  Serial.println(out[j]);
    }
  }
  clearResponseBuffer();
  clearTransmitBuffer();
  return result;
}
