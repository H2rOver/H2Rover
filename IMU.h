//
// Created by: Daniel Benusovich
// Created on: 11/3/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/11/2017
//
// Edit notes:
//		(11-11-2017) Added note about specifically which arduino library needs to be installed

#ifndef H2ROVER_IMU_H
#define H2ROVER_IMU_H

#include "PinDeclarations.h"
#include "MotorControl.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>	//need to install "Adafruit BNO055" library on arduino IDE


//This sensor follows the Adafruit Unified Sensor Library Conventions
//This class interfaces the BNO055 Absolute Orientation Sensor
class IMU {
public:
    // Constructor and deconstructor require no parameters
    IMU();

    ~IMU();

    /* The sensor must have sensor offsets loaded onto the microchip before beginning operation.
       This function MUST be run AFTER beginning the serial line to properly initialize the IMU.
       The code will attempt to auto calibrate the sensor by using the MotorControl class to
       move the vehicle. The movement will stop once the IMU is calibrated
     */
    void initialize(int id);

    void getSensor(sensor_t* sensor);

    //Populates uint8_t array where:
    // array[0] = system status
    // array[1] = system test results
    // array[2] = system error
    void getSystemStatus(uint8_t *array);

    //Populates uint16_t array where:
    // array[0] = X heading (0 - 360)
    // array[1] = Y heading (-90 - 90)
    // array[2] = Z heading (-90 - 90)
    void getXYZ(int16_t *array);

private:
    Adafruit_BNO055 bno;
    //These values are predetermined through testing and will not change during operation
    //Calibration values correspond to:
    const adafruit_bno055_offsets_t offsets = {65522, 65455, 11, // Accelerometer X, Accelerometer Y, Accelerometer Z,
                                               65534, 65535, 1, // Gyroscope X, Gyroscope Y, Gyroscope Z,
                                               472, 65453, 65469, // Magnetometer X, Magnetometer Y, Magnetometer Z,
                                               1000, // Accelerometer Radius
                                               418}; // Magnetometer Radius
};

#endif //H2ROVER_IMU_H
