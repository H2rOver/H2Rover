//
// Created by: Jonathan Midolo
// Created on: 11/19/2017
// Last edited by: Jonathan Midolo
// Last edited bn: 11/20/2017
//
// Edit notes:
//		(11-19-2017) Created


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

	// Initialize GPS
	gps_obj.begin(9600);
	gps_obj.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	gps_obj.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
	gps_obj.sendCommand(PGCMD_ANTENNA);
	delay(1000);

	while(gps_obj.fix == 0){
		gps_obj.read();
		if (gps_obj.newNMEAreceived()) {
			if (!gps_obj.parse(gps_obj.lastNMEA())) return;
		}
	}
}

int GPS::updateLocation()
{
	gps_obj.read();
	if (gps_obj.newNMEAreceived()) {
		if (!gps_obj.parse(gps_obj.lastNMEA())) return 1;
	}
	return 0;
}

int GPS::getGPS(Adafruit_GPS *pop_gps)
{
	pop_gps = gps_obj;
}

