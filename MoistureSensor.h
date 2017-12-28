//
// Created by DanielB on 12/27/2017.
//

#ifndef H2ROVER_MOISTURESENSOR_H
#define H2ROVER_MOISTURESENSOR_H

#include <PinDeclarations.h>
#include <Adafruit_Sensor.h>

class MoistureSensor {
public:
	MoistureSensor();
    MoistureSensor(uint8_t sensorID);
    ~MoistureSensor();
	void initialize(uint8_t sensorID);
    uint16_t getData(uint8_t sampleCount);
    void getSensor(sensor_t* sensor);
private:
    uint8_t sensorID;
};

#endif //H2ROVER_MOISTURESENSOR_H
