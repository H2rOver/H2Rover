#include "MotorControl.h"

MotorControl::MotorControl() {
    pinMode(MOTOR_SPEED_LEFT, OUTPUT);
    pinMode(MOTOR_SPEED_RIGHT, OUTPUT);
    pinMode(MOTOR_ENABLE_LEFT_FRONT, OUTPUT);
    pinMode(MOTOR_ENABLE_LEFT_BACK, OUTPUT);
    pinMode(MOTOR_ENABLE_RIGHT_FRONT, OUTPUT);
    pinMode(MOTOR_ENABLE_RIGHT_BACK, OUTPUT);
}

void MotorControl::motorOff() {
    digitalWrite(MOTOR_ENABLE_LEFT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_LEFT_BACK, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT_BACK, LOW);
    analogWrite(MOTOR_SPEED_RIGHT, 0);
    analogWrite(MOTOR_SPEED_LEFT, 0);
}

void MotorControl::motorForward(int speed) {
    // turn on motor side A
    digitalWrite(MOTOR_ENABLE_LEFT_FRONT, HIGH);
    digitalWrite(MOTOR_ENABLE_LEFT_BACK, LOW);
    // turn on motor side B
    digitalWrite(MOTOR_ENABLE_RIGHT_FRONT, HIGH);
    digitalWrite(MOTOR_ENABLE_RIGHT_BACK, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_LEFT, speed);
    analogWrite(MOTOR_SPEED_RIGHT, speed);
}

void MotorControl::motorBackward(int speed) {
    // turn on motor side Left
    digitalWrite(MOTOR_ENABLE_LEFT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_LEFT_BACK, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_LEFT, speed);
    // turn on motor side B
    digitalWrite(MOTOR_ENABLE_RIGHT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT_BACK, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_RIGHT, speed);
}

void MotorControl::motorLeft(int speed) {
    // turn on motor side Left
    digitalWrite(MOTOR_ENABLE_LEFT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_LEFT_BACK, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_LEFT, speed);
    // turn on motor side right
    digitalWrite(MOTOR_ENABLE_RIGHT_FRONT, HIGH);
    digitalWrite(MOTOR_ENABLE_RIGHT_BACK, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_RIGHT, speed);
}

void MotorControl::motorRight(int speed) {
    // turn on motor side Left
    digitalWrite(MOTOR_ENABLE_LEFT_FRONT, HIGH);
    digitalWrite(MOTOR_ENABLE_LEFT_BACK, LOW);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_LEFT, speed);
    // turn on motor side Right
    digitalWrite(MOTOR_ENABLE_RIGHT_FRONT, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT_BACK, HIGH);
    // set pwm to 'speed' out of possible range 0~255
    analogWrite(MOTOR_SPEED_RIGHT, speed);
}
