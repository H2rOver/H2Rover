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

void GPS::initialize(Adafruit_GPS* GPS_obj1) {

	// Initialize GPS
	GPS_obj1->begin(9600);
	GPS_obj1->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	GPS_obj1->sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
	GPS_obj1->sendCommand(PGCMD_ANTENNA);
	delay(1000);

	while(GPS_obj1->fix == 0){
		GPS_obj1->read();
		if (GPS_obj1->newNMEAreceived()) {
			if (!GPS_obj1->parse(GPS_obj1->lastNMEA())) return;
		}
	}
}

int GPS::gpsRead(Adafruit_GPS* GPS_obj1)
{
	GPS_obj1->read();
	if (GPS_obj1->newNMEAreceived()) {
		if (!GPS_obj1->parse(GPS_obj1->lastNMEA())) return 1;
	}
	return 0;
}


