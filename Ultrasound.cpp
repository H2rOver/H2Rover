//
// Created by DanielB on 11/26/2017.
//

#include "Ultrasound.h"

Ultrasound::Ultrasound() {
	this->sensorId = 0;
}

Ultrasound::~Ultrasound() {}

void Ultrasound::initialize(uint8_t sensorId) {
    this->sensorId = sensorId;
    //Trigger activates the ultrasonic unit
    pinMode(ULTRASOUND_TRIGGER, OUTPUT);
    //echo acknowledges the reflections
    pinMode(ULTRASOUND_ECHO, INPUT);
}

uint32_t Ultrasound::getDistance(uint8_t sampleCount) {
    uint32_t duration = 0;
	for(int i = 0; i < sampleCount + 5; i++){
        //Clear the area of noise

		digitalWrite(ULTRASOUND_TRIGGER, LOW);
		delayMicroseconds(2);
        //Enable trigger to populate local area with sound
		digitalWrite(ULTRASOUND_TRIGGER, HIGH);
		delayMicroseconds(10);
        //Deactivate emitter
		digitalWrite(ULTRASOUND_TRIGGER, LOW);
        //Read in values
		uint16_t temp = pulseIn(ULTRASOUND_ECHO, HIGH);
		temp = (temp/2) / 29.1;
		//Toss the first 5 samples. They are often inaccurate
		if (i > 4) {
			Serial.println(temp);
			if (temp <= 400) {
				duration += temp;
			} else {
				duration += 400;
			}
		}
		//Delay for 60 milliseconds to prevent overlap
		unsigned long timeStart = millis();
		while (millis() - timeStart < 60){
			
		}
	}
	Serial.println("Result");
	Serial.println(duration / (sampleCount));
    return (duration / (sampleCount));

}

void Ultrasound::getSensor(sensor_t *sensor) {
    memset(sensor, 0, sizeof(sensor_t));
    strncpy(sensor->name, "HD-38", sizeof(sensor->name) - 1);
    sensor->version = 1;
    sensor->sensor_id =this->sensorId;
    sensor->type = SENSOR_TYPE_VOLTAGE;
    sensor->min_delay = 65; //65 microseconds between readings
    sensor->max_value = 400; //400cm is the highest recorded value
    sensor->resolution = 1; //smallest difference in measurements is 1cm
}

