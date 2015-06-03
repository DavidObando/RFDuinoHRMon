# RFDuinoHRMon
Android app that comunicates with rfduino for computing heart rate

Arduino code lives here:
 \RFDuinoHRMon\rfduinoPulseRead

Android app lives here:
 \RFDuinoHRMon

Implementation details:
- Arduino samples data every 50ms (In order to keep computations at real time)
- Arduino does median filtering on a window size of 5 (can be adjusted)
- Java code is built off the Bluetooth test code (https://github.com/lann/RFDuinoTest) with the following modifications
   + Added graphing library
   + Added FFT library
   + Updated UI to hide the Bluetooth connection settings
   + Updated UI to display median filtered data, HR, and FFT
- FFT seems to compute a slightly lower than expect HR (4-6bpm) which is probably the result of a computation error in my FFT size.
