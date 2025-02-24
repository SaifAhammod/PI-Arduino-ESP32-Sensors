#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>

// L3GD20 Gyroscope
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20); // Only sensorID is passed
// LSM303D Accelerometer and Magnetometer
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30); // Only sensorID is passed
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(31); // Only sensorID is passed

void setup() {
    Serial.begin(115200);
    Wire.begin();

    // Initialize Gyroscope (L3GD20)
    if (!gyro.begin()) {
        Serial.println("Failed to find L3GD20 Gyro!");
    } else {
        // Set the I2C address directly in the begin() method
        if (!gyro.begin()) {
            Serial.println("Failed to find L3GD20 Gyro!");
        } else {
            Serial.println("L3GD20 Gyro found!");
        }
    }

    // Initialize Accelerometer (LSM303D)
    if (!accel.begin()) {
        Serial.println("Failed to find LSM303D Accel!");
    } else {
        Serial.println("LSM303D Accel found!");
    }

    // Initialize Magnetometer (LSM303D)
    if (!mag.begin()) {
        Serial.println("Failed to find LSM303D Mag!");
    } else {
        Serial.println("LSM303D Mag found!");
    }
}

void loop() {
    sensors_event_t accel_event;
    sensors_event_t gyro_event;
    sensors_event_t mag_event;

    // Read Accelerometer data
    accel.getEvent(&accel_event);
    Serial.print("Accel X: "); Serial.print(accel_event.acceleration.x);
    Serial.print(" Y: "); Serial.print(accel_event.acceleration.y);
    Serial.print(" Z: "); Serial.println(accel_event.acceleration.z);

    // Read Gyroscope data
    gyro.getEvent(&gyro_event);
    Serial.print("Gyro X: "); Serial.print(gyro_event.gyro.x);
    Serial.print(" Y: "); Serial.print(gyro_event.gyro.y);
    Serial.print(" Z: "); Serial.println(gyro_event.gyro.z);

    // Read Magnetometer data
    mag.getEvent(&mag_event);
    Serial.print("Mag X: "); Serial.print(mag_event.magnetic.x);
    Serial.print(" Y: "); Serial.print(mag_event.magnetic.y);
    Serial.print(" Z: "); Serial.println(mag_event.magnetic.z);

    Serial.println();
    delay(500);
}
