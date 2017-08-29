


#include <ModbusMaster.h>

/*** NUM REGISTERS ***/
// DISCRETES
#define VERSION 1
#define CONTROL_CLP 2
#define DEFROST_MODE 5
#define EXT_ENGINE_STATUS 6
#define IMP_ENGINE_STATUS 7
#define T_IN_DEVICE_STATUS 10 // Inside temperature device status (Tint)
#define T_OUT_DEVICE_STATUS 11 // Download temperature device status (Tout)
#define T_EXT_DEVICE_STATUS 12 // Outside temperature device status (Text)
#define T_IMP_DEVICE_STATUS 13 // Impulsion temperature device status (Timp)
#define FILTER_STATUS_ALARM 14

// COILS
#define PRE_HEAT_BATT 2
#define POST_HEAT_BATT 3
#define CONT_LIB_POT 4
#define VERSION_SELECTION 6
#define MODE_ACTIVATION 7
#define AUTO_BAYPASS_CONTROL 8
#define MANUAL_BYPASS 9
#define FILTER_ALARM_RESET 12
#define FACTORY_RESET 13

// INPUT REGISTERS
#define CENTRAL_UNIT_VERSION 6
#define REMOTE_VERSION 7
#define PROGRAM_UNIT_VERSION 8
#define TWIN_FLOW_TYPE 9
#define ADJUSTEMENT_TYPE 10
#define FLOW_GAP 12
#define MIN_FLOW 13
#define MAX_FLOW 14
#define MAX_FLOW_FREE_COOLING 15
#define ACTUAL_FLOW 16
#define SUPPLY_VOLTAGE 17
#define EXT_ENGINE_REVS 19
#define IMP_ENGINE_REVS 20
#define T_INT 21
#define T_OUT 22
#define T_EXT 23
#define T_IMP 24
#define BYPASS_STATUS 25
#define PRE_HEAT_BATT_STATUS 26
#define POST_HEAT_BATT_STATUS 27
#define FILTER_ALARM_TIMER 36
#define PRE_HEAT_BATT_T_IN 37
#define PRE_HEAT_BATT_T_OUT 38
#define POST_HEAT_BATT_T_IN 39
#define POST_HEAT_BATT_T_OUT 40

//HOLDING REGISTERS
#define MODBUS_SLAVE_NODE 0
#define MODBUS_BAUDRATE 1
#define FLOW_GAP_SELECTION 8
#define MIN_FLOW_SELECTION 9
#define MAX_FLOW_SELECTION 10
//#define MAX_FLOW_FREE_COOLING 11
#define FLOW_RATE 15
#define MIN_RATE_V 16
#define MAX_RATE_V 17
#define BYPASS_AUTO_T_EXT 22
#define BYPASS_AUTO_T_INT 23
#define BYPASS_MANUAL_TIMEOUT 24
#define PRE_HEAT_BATT_T_ON 25
#define PRE_HEAT_BATT_T_OFF 26
#define POST_HEAT_BATT_T_ON 27
#define POST_HEAT_BATT_T_OFF 28
#define FILTER_ALARM_TIMER_SELECTION 31


class SPModbus : public ModbusMaster
{
public:
  uint8_t getCoilsInJson(String &output);
  uint8_t getInputRegistersInJson(String &output);
  uint8_t getHoldingRegistersInJson(String &output);
  uint8_t getDiscreteInputsInJson(String &output);

  /**
    param: data
      - 0 deactivate
      - 1 activate
  */
  uint8_t writeManualBypass(uint8_t data);
  /**
    param: data
      - 0 LOW
      - 1 MEDIUM(german version)/BOST(standard version)
      - 2 HIGH  only german version
  */
  uint8_t writeFLowRate(uint8_t data);
  /**
    param: data
      - 0 activar reset
      - 1 error reset
  */
  uint8_t writeFilterReset(uint8_t data);
  /**
    param: data
      - 0 standby off
      - 1 standby on
  */
  uint8_t writeActivationMode(uint8_t data);

private:

  uint8_t readAllCoils(uint16_t out[]);
  uint8_t readAllDiscreteInputs(uint16_t out[]);
  uint8_t readAllHoldingRegisters(uint16_t out[]);
  uint8_t readAllInputRegisters(uint16_t out[]);

};
