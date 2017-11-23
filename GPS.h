//
// Created by: Jonathan Midolo
// Created on: 11/19/2017
// Last edited by: Jonathan Midolo
// Last edited bn: 11/20/2017 // bn?
//
// Edit notes:
//		(11-19-2017) Created

#ifndef H2ROVER_GPS_H
#define H2ROVER_GPS_H

// #include "Arduino.h" // Do we need this...?
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
	// dGPS (differential) quality 
		void initialize(Adafruit_GPS* GPS_obj1);

		void gpsRead(Adafruit_GPS* GPS_obj1);
 

	private:
		// Private stuff goes here... I guess.
		// char c;
		// uint8_t hour;
		uint32_t timer = millis();
		// float lat, lon;
		// String str;
		// char timeArray[10], dateArray[10], latArray[10], longArray[10];  

	    int hour;
		float  lat; // use float or otherwise??? ... or split fractional part separate?
		float  lon; // use float or otherwise??? ... or split fractional part separate?
		String str;
		char timeArray[10];
		char dateArray[10];
		char latArray[10];
		char longArray[10];
		char c;
	
};

#endif //H2ROVER_GPS_H