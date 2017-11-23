//
// Created by: Jonathan Midolo
// Created on: 11/19/2017
// Last edited by: Jonathan Midolo
// Last edited bn: 11/20/2017
//
// Edit notes:
//		(11-19-2017) Created


#include "GPS.h"

// Constructor
GPS::GPS() {

}

// Deconstructor
GPS::~GPS() {

}

void GPS::initialize(Adafruit_GPS* GPS_obj1, SoftwareSerial* softSerial) {

	// Setup onboard Arduino Nano LED for fix confirmation
	pinMode(LED_BUILTIN,OUTPUT);
	digitalWrite(LED_BUILTIN,LOW);

	// Initialize GPS
	GPS_obj1->begin(9600);


	GPS_obj1->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	GPS_obj1->sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
	GPS_obj1->sendCommand(PGCMD_ANTENNA);
	delay(1000);

	while(GPS_obj1->fix != 1){
		char letter = GPS_obj1->read();

			if (GPS_obj1->newNMEAreceived()) {
		
			if (!GPS_obj1->parse(GPS_obj1->lastNMEA()))   // this also sets the newNMEAreceived() flag to false
				return;  // we can fail to parse a sentence in which case we should just wait for another
			}
	}
	Serial.println("GPS ready");
}

void GPS::gpsRead(Adafruit_GPS* GPS_obj1)
{
	Serial.println("GPS");
	Serial.println((int)GPS_obj1);
	// if a sentence is received, we can check the checksum, parse it...
	if (GPS_obj1->newNMEAreceived()) {
	
	if (!GPS_obj1->parse(GPS_obj1->lastNMEA()))   // this also sets the newNMEAreceived() flag to false
		return;  // we can fail to parse a sentence in which case we should just wait for another
	}
	Serial.println(GPS_obj1->lastNMEA());
	Serial.println("GPS Read fix: ");
	Serial.println(GPS_obj1->fix);
	Serial.println("GPS Fix Quality: ");
	Serial.println(GPS_obj1->fixquality);
}


