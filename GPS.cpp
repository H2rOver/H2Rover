//
// Created by: Jonathan Midolo
// Created on: 11/19/2017
// Last edited by: Jonathan Midolo
// Last edited on: 11/27/2017
//
// Edit notes:
//		(11-19-2017) Created...does not work
//		(11-22-2017) Works per the work of Daniel Benusovich
//		(11-27-2017) Cleared issue with millis() within .ino (Removed requirement)


#include "GPS.h"

SoftwareSerial soft(GPS_TX, GPS_RX);
Adafruit_GPS gps_obj(&soft);

// Constructor
GPS::GPS() {

}

// Deconstructor
GPS::~GPS() {

}

void GPS::initialize() {

	// Initialize GPS settings
	gps_obj.begin(9600);
	gps_obj.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	gps_obj.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
	gps_obj.sendCommand(PGCMD_ANTENNA);
	delay(1000);

	// Infinite loop until GPS module parses first NMEA sentence (no control over fixquality)
	while(1){
		gps_obj.read();
		if (gps_obj.newNMEAreceived()) {
			if (!gps_obj.parse(gps_obj.lastNMEA())) return;
		}
	}
}

int GPS::updateLocation()
{
	// Gets new NMEA reading and parses
	gps_obj.read();
	if (gps_obj.newNMEAreceived()) {
		if (!gps_obj.parse(gps_obj.lastNMEA())) return 1;
	}
	return 0;
}

int GPS::getData(String* array)
{
	// Infinite loop until data array of strings populates
	while(1){

		updateLocation();

		if (timer > millis())  timer = millis();

		if (millis() - timer > 2000) {
					timer = millis(); // reset the timer

			    array[0] = String(gps_obj.hour);
			    array[1] = String(gps_obj.minute);
			    array[2] = String(gps_obj.seconds);
			    array[3] = String(gps_obj.month);
			    array[4] = String(gps_obj.day);
			    array[5] = String(gps_obj.year);
			    array[6] = String(gps_obj.latitudeDegrees, 10);
			    array[7] = String(gps_obj.longitudeDegrees, 10);
					array[8] = String(gps_obj.fixquality);

			    return 0;
		}
	}
}
