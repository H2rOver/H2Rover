//
// Created by: Daniel Benusovich
// Created on: 10/25/2017
// Last edited By: Scott Timpe
// Last edited bn: 11/11/2017
//
// Edit notes:
// 		(11-11-2017) Moved FEELER to pin 2, GPS_RX to pin 12

#ifndef H2ROVER_PINDECLARATIONS_H
#define H2ROVER_PINDECLARATIONS_H

//Import to allow arduino commands 
#include <Arduino.h>


//THIS PIN DECLARATION IS FOR ARDUINO UNO ONLY
//CHANGE THIS ALL FOR ARDUINO NANO
//List all pins used here

//Left Motors
const int MOTOR_SPEED_LEFT = 10;
const int MOTOR_ENABLE_LEFT_FRONT = 8;
const int MOTOR_ENABLE_LEFT_BACK = 7;

//Right Motors
const int MOTOR_SPEED_RIGHT = 9;
const int MOTOR_ENABLE_RIGHT_FRONT = 6;
const int MOTOR_ENABLE_RIGHT_BACK = 5;

//Feelers
//We could use logic gates to incorporate multiple feelers
const int FEELER = 2;

//Moisture Sensor
//We combine Voltage_pin and motor_direction for the rack and pinion motor due to a lack of pins
//We may combine the pins because the moisture sensor will only be on when we lower the motor
const int MOISTURE_INPUT = A7;//Nano

//Proximity Sensor
const int ULTRASOUND_TRIGGER = 11;
const int ULTRASOUND_ECHO = 4;

//XBee
const int XBEE_TX = 1; //TX
const int XBEE_RX = 0; //RX

//Water Sensor
const int WATER_INPUT = A6;//Nano

//Battery Voltage
const int BATTERY_VOLTAGE = A3;//Nano

//Temperature Sensor
const int TEMPERATURE_INPUT = A0;

//GPS
const int GPS_RX = 12;
const int GPS_TX = 13;

//IMU
const int IMU_SDA = A4;
const int IMU_SCL = A5;

//Rack and Pinion Motor
const int MOTOR_MOISTURE_PWM = 3;

//Encoder
const int ENCODER_FRONT_LEFT_INC = A2;
const int ENCODER_FRONT_LEFT_DEC = A1;

#endif //H2ROVER_PINDECLARATIONS_H
