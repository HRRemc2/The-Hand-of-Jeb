/*
Key info:
This is the GPS loop file, its header is gps_handler.h
the error code when there is no connection will cause the gps variables to be set to 1.1
the gps is connected to gpio RX: 16 and TX: 17
*/

#include "gps_handler.h"

TinyGPSPlus gps;
//GPS RX:16 TX:17 might be 17, 16
HardwareSerial gpsSerial(1);


void initGPS() {
    Serial.println(GPS Setup);
    gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
    Serial.println("GPS Begin");
    Serial.println("Finding Satellites");
}

void GPS_loop(double &latGPS, double &lngGPS, double &altGPS) {
    while (gpsSerial.available() > 0){
   gps.encode(gpsSerial.read());
 }
 if(gps.location.isValid()) {
   latGPS = gps.location.lat();
   lngGPS = gps.location.lng();
   altGPS = gps.altitude.meters();
 }
 else {
   //1.1 is the error confirmation
   latGPS = 1.1;
   lngGPS = 1.1;
   altGPS = 1.1;
 }
}
