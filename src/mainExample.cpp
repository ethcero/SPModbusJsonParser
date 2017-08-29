
#include <SPModbus.h>
/*!
  We're using a MAX485-compatible RS485 Transceiver.
  Rx/Tx is hooked up to the hardware serial port at 'Serial'.
  The Data Enable and Receiver Enable pins are hooked up as follows:
*/
#define MAX485_DE      14
#define MAX485_RE_NEG  12

// instantiate SPModbus object
SPModbus node;


void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, HIGH);
  digitalWrite(MAX485_DE, HIGH);
}

void postTransmission()
{
  delay(1); //https://github.com/esp8266/Arduino/issues/2536
  digitalWrite(MAX485_RE_NEG, LOW);
  digitalWrite(MAX485_DE, LOW);
}
void initSP()
{
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  // Init in receive mode
  digitalWrite(MAX485_RE_NEG, LOW);
  digitalWrite(MAX485_DE, LOW);

  // Modbus communication runs at 19200 baud, 8,even,1
  Serial.begin(19200,SERIAL_8E1);

  // Modbus slave ID 1
  node.begin(1, Serial);
  // Callbacks allow us to configure the RS485 transceiver correctly
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}

void setup()
{
  initSP();
}

void loop()
{
  uint8_t result;
  String data1,data2,data3,data4;

  delay(2000);
  result = node.getInputRegistersInJson(data1);
  if(result == node.ku8MBSuccess)
  {
    Serial.println(data1);
  }
  delay(2000);
  result = node.getCoilsInJson(data2);
  if(result == node.ku8MBSuccess)
  {
    Serial.println(data2);
  }
  delay(2000);
  result = node.getDiscreteInputsInJson(data3);
  if(result == node.ku8MBSuccess)
  {
    Serial.println(data3);
  }
  delay(2000);
  result = node.getHoldingRegistersInJson(data4);
  if(result == node.ku8MBSuccess)
  {
    Serial.println(data4);
  }
  delay(10000);
}
