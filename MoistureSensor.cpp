//
// Created by DanielB on 12/27/2017.
//
#include "MoistureSensor.h"
#include "PinDeclarations.h"

MoistureSensor::MoistureSensor() {
    this->sensorID = 0;
}

MoistureSensor::MoistureSensor(uint8_t sensorID) {
    this->sensorID = sensorID;
}

MoistureSensor::~MoistureSensor() {}

void MoistureSensor::initialize(uint8_t sensorID) {
	this->sensorID = sensorID;
}

uint16_t MoistureSensor::getData(uint8_t sampleCount) {
    uint32_t dataBank = 0;
    for (int i = 0; i < sampleCount; i++){
        dataBank += analogRead(MOISTURE_INPUT);
		unsigned long timeStart = millis();
		while (millis() - timeStart < 100){
			
		}
    }
    return dataBank/sampleCount;
}

void MoistureSensor::getSensor(sensor_t *sensor) {
    memset(sensor, 0, sizeof(sensor_t));
    strncpy(sensor->name, "", sizeof(sensor->name) - 1);
    sensor->version = 1;
    sensor->sensor_id =this->sensorID;
    sensor->type = SENSOR_TYPE_PROXIMITY;
    sensor->min_delay = 100; //100 microseconds between readings
    sensor->max_value = 1023; //highest recorded value (very dry
    sensor->resolution = 1; //smallest difference in measurements is 1 unit
}