//
// Created by DanielB on 11/26/2017.
//

#ifndef H2ROVER_ULTRASOUND_H
#define H2ROVER_ULTRASOUND_H

#include <PinDeclarations.h>

//This class aims to simplify the usage of the Ultrasound module HC-SR04
//It returns values only in cm
class Ultrasound {
public:
    Ultrasound();

    ~Ultrasound();

    void initialize(uint8_t sensorId);

    uint16_t getDistance();

    void getSensor(sensor_t* sensor);

private:
    uint8_t sensorId;
};

#endif //H2ROVER_ULTRASOUND_H
