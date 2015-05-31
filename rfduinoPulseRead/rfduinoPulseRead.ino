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
RunningMedian samples = RunningMedian(10);
//int g_series[10];
//int g_size = 10;
//int g_pos = 0;

//
// Function Defs
//
void bleSendString(String sendstring);
//int ApplyFilter(int data);
//int Median();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  RFduinoBLE.deviceName = DEVICE_NAME;
  RFduinoBLE.customUUID = SERVICE_UUID;
  RFduinoBLE.begin();  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);    // read the input pin
  //Serial.println(val);          // debug value
  
  // sample every 2 milliseconds
  RFduino_ULPDelay( 2 );

  // send the sample over bluetooth
  samples.add(val);
  int m = (int)samples.getMedian();
//  Serial.print("Median: ");
//  Serial.println(m);
//  Serial.print("Raw: ");
//  Serial.println(val);
  RFduinoBLE.sendInt(m);
}

void RFduinoBLE_onReceive(char *data, int len)
{
  // display the first recieved byte
  Serial.println("Bar");
}

//int ApplyFilter(int data) {
//    g_series[g_pos++] = data;
//    g_pos = g_pos % g_size;
//
//    return Median();
//}
//
//int Median() {
//    int tempArray[g_size] = {};
//    memcpy( tempArray, g_series, g_size );
//
//    Arrays.sort(tempArray);
//    float median;
//    if (tempArray.length % 2 == 0) {
//        median = ( tempArray[tempArray.length / 2] + tempArray[tempArray.length / 2 - 1]) / 2;
//    }
//    else {
//        median = tempArray[tempArray.length / 2];
//    }
//
//    return median;
//}
