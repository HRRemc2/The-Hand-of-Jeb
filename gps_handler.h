#pragma once

#include <Arduino.h>
#include <TinyGPS++.h>

extern TinyGPSPLUS gps;

void initGPS();

void GPS_loop(double &latGPS, double &lngGPS, double &altGPS);
