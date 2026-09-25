/*
The Hand of Jeb V0.3.1
Basic integration of flight computer components:
 - GPS
 - Gyro (MPU6050)
 - SD Card
*/

#include <Arduino.h>
#include "gps_handler.h"
#include "gyro_handler.h"
#include "sd_logger.h"

// GPS state
double latGPS = 0.0;
double lngGPS = 0.0;
double altGPS = 0.0;

// Gyro state
float ax_mps2, ay_mps2, az_mps2;
float gx_dps, gy_dps, gz_dps;
float tempC, tempF;

unsigned long time_ms = 0;

void SerialPrint_loop() {
  Serial.print("GPS: ");
  Serial.print(latGPS, 6);
  Serial.print(", ");
  Serial.print(lngGPS, 6);
  Serial.print(", ");
  Serial.println(altGPS);

  Serial.print("Gyro: ");
  Serial.print(ax_mps2); Serial.print(", ");
  Serial.print(ay_mps2); Serial.print(", ");
  Serial.print(az_mps2); Serial.print(", ");
  Serial.print(gx_dps);  Serial.print(", ");
  Serial.print(gy_dps);  Serial.print(", ");
  Serial.println(gz_dps);

  Serial.print("Temp(C, F): ");
  Serial.print(tempC);
  Serial.print(", ");
  Serial.println(tempF);
}

void setup() {
    Serial.begin(115200);

    initGPS();
    initGyro();
    initSD();
}

void loop() {
    time_ms = millis();

    GPS_loop(latGPS, lngGPS, altGPS);
    Gyro_loop(ax_mps2, ay_mps2, az_mps2, gx_dps, gy_dps, gz_dps, tempC, tempF);

    SerialPrint_loop();
    SDwrite_loop(time_ms, latGPS, lngGPS, altGPS, 
               ax_mps2, ay_mps2, az_mps2, 
               gx_dps, gy_dps, gz_dps, 
               tempC, tempF);
}
