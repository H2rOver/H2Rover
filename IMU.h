//
// Created by: Daniel Benusovich
// Created on: 11/3/2017
// Last edited By: Daniel Benusovich
// Last edited bn: 11/3/2017
//

#ifndef H2ROVER_IMU_H
#define H2ROVER_IMU_H

#include "PinDeclarations.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


//This sensor follows the Adafruit Unified Sensor Library Conventions
class IMU {
public:
    //ID is the unique sensor ID associated with this sensor
    IMU(int id);
    ~IMU();
    sensor_t getSensor();
    //Populates int array where:
    // array[0] = system status
    // array[1] = system test results
    // array[2] = system error
    void getSystemStatus(uint_8* array);
    //Populates int array where:
    // array[0] = X heading
    // array[1] = Y heading
    // array[2] = Z heading
    void getXYZ(uint_8* array);

private:
    Adafruit_BNO055 bno;
    sensor_t sensor;
    //Calibration values correspond to:
    const adafruit_bno055_offsets_t offsets = {65522, 65455, 11, // Accelerometer X, Accelerometer Y, Accelerometer Z,
                                               65534, 65535, 1, // Gyroscope X, Gyroscope Y, Gyroscope Z,
                                               472, 65453, 65469, // Magnetometer X, Magnetometer Y, Magnetometer Z,
                                               1000, // Accelerometer Radius
                                               418}; // Magnetometer Radius
};
#endif //H2ROVER_IMU_H
