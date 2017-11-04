//
// Created by: Daniel Benusovich
// Created on: 11/3/2017
// Last edited By: Daniel Benusovich
// Last edited bn: 11/3/2017
//

#include "IMU.h"

//
// Created by DanielB on 11/3/2017.
//

IMU::IMU(int id) {
    //Initialize IMU with id number
    this->bno = Adafruit_BNO055(id);

    //Check that bno is present in current system
    if(!this->bno.begin()){
        Serial.print("No BNO055 detected");
        while(1);
    }

    //Initialize sensor reference
    this->bno.getSensor(&sensor);

    //Set calibration offsets
    this->bno.setSensorOffsets(this->offsets);

    //Enable IMU operation
    this->bno.setExtCrystalUse(true);

    while(!this->bno.isFullyCalibrated()){
        Serial.print("Please move the sensor slightly");
        delay(10);
    }
}

IMU::~IMU() {}

sensor_t IMU::getSensor() {
    return this->sensor;
}

void IMU::getSystemStatus(uint8_t* array) {
    this->bno.getSystemStatus(&array[0], &array[1], &array[2]);
}

void IMU::getXYZ(uint8_t* array) {
    sensors_event_t event;
    this->bno.getEvent(&event);
    array[0] = event.orientation.x;
    array[1] = event.orientation.y;
    array[2] = event.orientation.z;
}