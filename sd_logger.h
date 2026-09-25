#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define SD_CS 5

void initSD();
void SDwrite_loop(unsigned long time_ms, 
                  double latGPS, double lngGPS, double altGPS,
                  float ax_mps2, float ay_mps2, float az_mps2,
                  float gx_dps, float gy_dps, float gz_dps,
                  float tempC, float tempF);