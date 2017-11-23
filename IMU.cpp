//
// Created by: Daniel Benusovich
// Created on: 11/3/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/19/2017
//
// Edit notes:
//	(11-19-2017) Changed IMU calibration to disregard system calibration.
//               This means the IMU is not "fully" calibrated now, however, since
//				 the system component was being so problematic I am taking it out for now.

#include "IMU.h"

IMU::IMU() {}

IMU::~IMU() {}

//Populates sensor object
void IMU::getSensor(sensor_t* sensor) {
    this->bno.getSensor(sensor);
}

void IMU::initialize(int id) {
	uint8_t system, gyro, accel, mag;
	
    //Initialize IMU with id number
    this->bno = Adafruit_BNO055(id);

    //Check that bno is present in current system
    if(!this->bno.begin()){
        Serial.print("No BNO055 detected");
        while(1);
    }

    //Set calibration offsets
    this->bno.setSensorOffsets(this->offsets);

    //Enable IMU operation
    this->bno.setExtCrystalUse(true);
    MotorControl temp;

//NEW WAY:
    Serial.println("Please move the sensor slightly");
	do {
      this->bno.getCalibration(&system, &gyro, &accel, &mag);
	  temp.motorRight(150);
      delay(800);
      temp.motorOff();
      delay(800);/*
	  Serial.print("Sys:");
      Serial.print(system, DEC);
      Serial.print(" G:");
      Serial.print(gyro, DEC);
      Serial.print(" A:");
      Serial.print(accel, DEC);
      Serial.print(" M:");
	  Serial.println(mag, DEC);*/
	} while(gyro < 3 || accel < 3 || mag < 3);
	//} while(system < 3 || gyro < 3 || accel < 3 || mag < 3); //for full calibration
	
//OLD WAY:
/*	
    while(!this->bno.isFullyCalibrated()){
        Serial.print("Please move the sensor slightly");

        temp.motorRight(150);
        delay(1000);
        temp.motorOff();
        delay(1000);
    }
*/
}

void IMU::getSystemStatus(uint8_t* array) {
    this->bno.getSystemStatus(&array[0], &array[1], &array[2]);
}

void IMU::getXYZ(int16_t* array) {
    sensors_event_t event;
    this->bno.getEvent(&event);
    array[0] = event.orientation.x;
    array[1] = event.orientation.y;
    array[2] = event.orientation.z;
}