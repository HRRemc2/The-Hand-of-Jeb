#pragma once

#include <Arduino.h>
#include <Wire.h>

void initGyro();
void Gyro_loop(float &ax_mps2, float &ay_mps2, float &az_mps2, 
               float &gx_dps, float &gy_dps, float &gz_dps, 
               float &tempC, float &tempF);