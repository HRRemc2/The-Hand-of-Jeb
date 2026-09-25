#include "gyro_handler.h"

const int MPU_ADDR = 0x68;

void initGyro() {
    Serial.println("Gyro Setup");
    //gpio pins
    Wire.begin(21, 22);

    Wire.setClock(100000);

    Serial.println("Waking MPU");

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission(true);

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x1B);
    Wire.write(0x00);
    Wire.endTransmission(true);

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x1C);
    Wire.write(0x00);
    Wire.endTransmission(true);

    Serial.println("Gyro Connnected");
}

void Gyro_loop(float &ax_mps2, float &ay_mps2, float &az_mps2, 
               float &gx_dps, float &gy_dps, float &gz_dps, 
               float &tempC, float &tempF){
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);

    Wire.requestFrom(MPU_ADDR, 14);

    int16_t ax = Wire.read() << 8 | Wire.read();
    int16_t ay = Wire.read() << 8 | Wire.read();
    int16_t az = Wire.read() << 8 | Wire.read();

    int16_t tempRaw = Wire.read() << 8 | Wire.read();
    
    int16_t gx = Wire.read() << 8 | Wire.read();
    int16_t gy = Wire.read() << 8 | Wire.read();
    int16_t gz = Wire.read() << 8 | Wire.read();

    // Acceleration conversion
    ax_mps2 = (ax / 16384.0) * 9.80665;
    ay_mps2 = (ay / 16384.0) * 9.80665;
    az_mps2 = (az / 16384.0) * 9.80665;

    // Gyro conversion
    gx_dps = gx / 131.0;
    gy_dps = gy / 131.0;
    gz_dps = gz / 131.0;

    // Temperature conversion
    tempC = (tempRaw / 340.0) + 36.53;
    tempF = (tempC * 9.0 / 5.0) + 32.0;
}

