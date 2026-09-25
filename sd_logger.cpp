#include "sd_logger.h"

void initSD(){
    Serial.println("SD Reader Setup Start");
    pinMode(2, OUTPUT);

    if (!SD.begin(SD_CS)){
        Serial.println("SD init failed");
        return;
    }

    SD.remove("/data.csv");

    File file = SD.open("data.csv", FILE_WRITE);
    if (file) {
        file.println("time_ms,latGPS,lngGPS,altGPS,ax_mps2,ay_mps2,az_mps2,gx_dps,gy_dps,gz_dps,tempC,tempF");
        file.close();
    }
    
    Serial.println("SD Read Initialized");
}

void SDwrite_loop(unsigned long time_ms, 
                  double latGPS, double lngGPS, double altGPS,
                  float ax_mps2, float ay_mps2, float az_mps2,
                  float gx_dps, float gy_dps, float gz_dps,
                  float tempC, float tempF) {
    File file = SD.open("/data.csv", FILE_APPEND);
    if (file) {
        file.print(time_ms);
    file.print(",");
    file.print(latGPS, 6);
    file.print(",");
    file.print(lngGPS, 6);
    file.print(",");
    file.print(altGPS, 6);
    file.print(",");
    file.print(ax_mps2);
    file.print(",");
    file.print(ay_mps2);
    file.print(",");
    file.print(az_mps2);
    file.print(",");
    file.print(gx_dps);
    file.print(",");
    file.print(gy_dps);
    file.print(",");
    file.print(gz_dps);
    file.print(",");
    file.print(tempC);
    file.print(",");
    file.println(tempF);

    file.close();
    }
}