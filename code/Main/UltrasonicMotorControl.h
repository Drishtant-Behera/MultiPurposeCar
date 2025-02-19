#ifndef ULTRASONIC_MOTOR_CONTROL_H
#define ULTRASONIC_MOTOR_CONTROL_H

#include <Arduino.h>
#include <ESP32Servo.h>

class UltrasonicMotorControl {
public:
    UltrasonicMotorControl(int trigPin, int echoPin, int servoPin, int leftForward, int leftBackward, int rightForward, int rightBackward);
    void update();
    void enable();
    void disable();
private:
    int getDistance();
    void moveForward();
    void moveLeft();
    void moveRight();
    void stopMotors();

    int trigPin, echoPin, leftForward, leftBackward, rightForward, rightBackward, servoPin;
    bool enabled;
    Servo myservo;
};

#endif