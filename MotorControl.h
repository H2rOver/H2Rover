#ifndef H2ROVER_LIBRARY_H
#define H2ROVER_LIBRARY_H

#include "PinDeclarations.h"

class MotorControl {
public:
    MotorControl();
    void motorOff();
    void probeOff();
    void motorForward(int speed);
	void motorForwardRight(int speed);
	void motorForwardLeft(int speed);
    void motorBackward(int speed);
    void motorRight(int speed);
    void motorLeft(int speed);
    void probeDown(int speed);
    void probeUp(int speed);
};

#endif
