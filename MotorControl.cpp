#include "MotorControl.h"

MotorControl::MotorControl() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(inA1, OUTPUT);
    pinMode(inA2, OUTPUT);
    pinMode(inB1, OUTPUT);
    pinMode(inB2, OUTPUT);
}

void MotorControl::motorOff() {
    digitalWrite(inA1, LOW);
    digitalWrite(inA2, LOW);
    digitalWrite(inB1, LOW);
    digitalWrite(inB2, LOW);
    analogWrite(enB, 0);
    analogWrite(enA, 0);
}

void MotorControl::motorForward(int speed) {
    // turn on motor side A
    digitalWrite(inA1, HIGH);
    digitalWrite(inA2, LOW);
    // turn on motor side B
    digitalWrite(inB1, HIGH);
    digitalWrite(inB2, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enA, speed);
    analogWrite(enB, speed);
}

void MotorControl::motorBackward(int speed) {
    // turn on motor side A
    digitalWrite(inA1, LOW);
    digitalWrite(inA2, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enA, speed);
    // turn on motor side B
    digitalWrite(inB1, LOW);
    digitalWrite(inB2, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enB, speed);
}

void MotorControl::motorLeft(int speed) {
    // turn on motor side A
    digitalWrite(inA1, LOW);
    digitalWrite(inA2, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enA, speed);
    // turn on motor side B
    digitalWrite(inB1, HIGH);
    digitalWrite(inB2, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enB, speed);
}

void MotorControl::motorRight(int speed) {
    // turn on motor side A
    digitalWrite(inA1, HIGH);
    digitalWrite(inA2, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enA, speed);
    // turn on motor side B
    digitalWrite(inB1, LOW);
    digitalWrite(inB2, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(enB, speed);
}
