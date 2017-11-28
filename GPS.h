//
// Created by: Jonathan Midolo
// Created on: 11/19/2017
// Last edited by: Jonathan Midolo
// Last edited on: 11/27/2017
//
// Edit notes:
//		(11-19-2017) Created...does not work
//		(11-22-2017) Works per the work of Daniel Benusovich
//		(11-27-2017) Cleared extraneous private data

#ifndef H2ROVER_GPS_H
#define H2ROVER_GPS_H

#include <Adafruit_GPS.h>	// need to install "Adafruit GPS Library" library on Arduino IDE
#include <SoftwareSerial.h>
#include <PinDeclarations.h>

//This class interfaces the Adafruit Ultimate GPS Breakout v3 with MTK3339 chipset
class GPS {
	public:
    // Constructor and deconstructor require no parameters
		GPS();

		~GPS();

    // The GPS module must "warm up" for 30-40s on first boot to get a fix with
		// dGPS (differential) quality (fixquality = 2)
		void initialize();

		int updateLocation();

		int getData(String* array);

	private:
		uint32_t timer = millis();

};

#endif //H2ROVER_GPS_H
