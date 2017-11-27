//
// Created by DanielB on 11/26/2017.
//

#include "Ultrasound.h"

Ultrasound::Ultrasound() {}

Ultrasound::~Ultrasound() {}

void Ultrasound::initialize(uint8_t sensorId) {
    this->sensorId = sensorId;
    pinMode(ULTRASOUND_TRIGGER, OUTPUT);
    pinMode(ULTRASOUND_ECHO, INPUT);
}

uint16_t Ultrasound::getDistance() {
    uint16_t duration;
    digitalWrite(ULTRASOUND_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASOUND_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASOUND_TRIGGER, LOW);
    duration = pulseIn(ULTRASOUND_ECHO, HIGH);
    return (duration/2) / 29.1;
}

void Ultrasound::getSensor(sensor_t *sensor) {
    memset(sensor, 0, sizeof(sensor_t));
    strncpy(sensor->name, "HC-SR04", sizeof(sensor->name) - 1);
    sensor->version = 1;
    sensor->sensor_id =this->sensorId;
    sensor->type = SENSOR_TYPE_PROXIMITY;
    sensor->min_delay = 12; //12 microseconds between readings
    sensor->max_value = 1035; //1035cm is the highest recorded value
    sensor->resolution = 1; //smallest difference in measurements is 1cm
}

