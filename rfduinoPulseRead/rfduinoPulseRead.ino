//
//    File: RfduinoPulseRead.ino
//  Author: Ben.Andrews@gmail.com
//    Date: 5/31/2015
//
#include <RFduinoBLE.h>
#include "RunningMedian.h"

#define DEVICE_NAME "RFduino HR"
#define SERVICE_UUID "00002220-0000-1000-8000-00805f9b34fb"

//
// Pin setup
//
const int analogPin = 3;
int val = 0;

//
// Filter setup
//
RunningMedian rawData = RunningMedian(10);

//
// Function Defs
//
void bleSendString(String sendstring);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  RFduinoBLE.deviceName = DEVICE_NAME;
  RFduinoBLE.customUUID = SERVICE_UUID;
  RFduinoBLE.begin();  
}

void loop() {
  // sample every 2 milliseconds
  RFduino_ULPDelay( 2 );
  
  // read the input pin
  val = analogRead(analogPin);
  
  //
  // Apply median filter
  //
  rawData.add(val);
  int m = (int)rawData.getMedian();
  
  // send the data to bluetooth
  RFduinoBLE.sendInt(m);
}

void RFduinoBLE_onReceive(char *data, int len)
{
  // Display debug message
  Serial.println("Bar");
}
