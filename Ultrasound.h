//
// Created by DanielB on 11/26/2017.
//

#ifndef H2ROVER_ULTRASOUND_H
#define H2ROVER_ULTRASOUND_H

#include <PinDeclarations.h>
#include <Adafruit_Sensor.h>

//This class aims to simplify the usage of the Ultrasound module HC-SR04
//It returns values only in cm
class Ultrasound {
public:
    //Empty constructor
    Ultrasound();

    //Empty deconsttructor no heap data is created
    ~Ultrasound();

    //initializes the required operating pins
    //Sets sensorID value to the passed in parameter MUST BE UNIQUE
    void initialize(uint8_t sensorId);

    //Returns the average of sampleCount samples in cm
    //Clips and distance greater than 200cm to 200cm
    //Exceedingly large sample value may delay the operation of the machine
    uint32_t getDistance(uint8_t sampleCount);

    //Diagnostic data on the sensor
    //Following Adafruit Unifeid Sensor Format
    void getSensor(sensor_t* sensor);

private:
    uint8_t sensorId;
};

#endif //H2ROVER_ULTRASOUND_H
