#include <RFduinoBLE.h>

#define DEVICE_NAME "RFduino HR"
#define SERVICE_UUID "00002220-0000-1000-8000-00805f9b34fb"

const int analogPin = 3;
int val = 0;               // variable to store the value read

void bleSendString(String sendstring);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  RFduinoBLE.deviceName = DEVICE_NAME;
  RFduinoBLE.customUUID = SERVICE_UUID;
  RFduinoBLE.begin();  
}

void loop() {
  // put your main code here, to run repeatedly:
  //val = analogRead(analogPin);    // read the input pin
  //Serial.println(val);            // debug value
  
  // sample once per second
  RFduino_ULPDelay( SECONDS(1) );

  // send the sample to the iPhone
  RFduinoBLE.sendInt(1);
}

void RFduinoBLE_onReceive(char *data, int len)
{
  // display the first recieved byte
  Serial.println("Bar");
}
