//
// Created by DanielB on 10/25/2017.
//

#ifndef H2ROVER_PINDECLARATIONS_H
#define H2ROVER_PINDECLARATIONS_H

//Import to allow arduino commands 
#include <Arduino.h>

//List all pins used here
//No declaring

//Left Motors
const int MOTOR_SPEED_LEFT = 10;
const int MOTOR_ENABLE_LEFT_FRONT = 8;
const int MOTOR_ENABLE_LEFT_BACK = 7;

//Right Motors
const int MOTOR_SPEED_RIGHT = 9;
const int MOTOR_ENABLE_RIGHT_FRONT = 6;
const int MOTOR_ENABLE_RIGHT_BACK = 5;

//feelers
const int LEFT_FEELER = 12;
const int RIGHT_FEELER = 13;

#endif //H2ROVER_PINDECLARATIONS_H
