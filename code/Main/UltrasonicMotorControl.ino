// UltrasonicMotorControl.h
#ifndef ULTRASONIC_MOTOR_CONTROL_H
#define ULTRASONIC_MOTOR_CONTROL_H

#include <Arduino.h>
#include <Servo.h>

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
    
    int trigPin;
    int echoPin;
    int leftForward;
    int leftBackward;
    int rightForward;
    int rightBackward;
    int servoPin;
    bool enabled;
    Servo myservo;
};

#endif

UltrasonicMotorControl::UltrasonicMotorControl(int trig, int echo, int servo, int lf, int lb, int rf, int rb) {
    trigPin = trig;
    echoPin = echo;
    servoPin = servo;
    leftForward = lf;
    leftBackward = lb;
    rightForward = rf;
    rightBackward = rb;
    enabled = false;
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(leftForward, OUTPUT);
    pinMode(leftBackward, OUTPUT);
    pinMode(rightForward, OUTPUT);
    pinMode(rightBackward, OUTPUT);
    myservo.attach(servoPin);
}

void UltrasonicMotorControl::enable() {
    enabled = true;
}

void UltrasonicMotorControl::disable() {
    enabled = false;
    stopMotors();
}

int UltrasonicMotorControl::getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH);
    return duration / 58.2;
}

void UltrasonicMotorControl::moveForward() {
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
}

void UltrasonicMotorControl::moveLeft() {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
}

void UltrasonicMotorControl::moveRight() {
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, HIGH);
}

void UltrasonicMotorControl::stopMotors() {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, LOW);
}

void UltrasonicMotorControl::update() {
    if (!enabled) return;
    int distance = getDistance();
    if (distance < 20) {
        stopMotors();
        myservo.write(0);
        delay(500);
        int distanceL = getDistance();
        delay(100);
        myservo.write(180);
        delay(500);
        int distanceR = getDistance();
        delay(100);
        myservo.write(90);
        delay(100);
        if (distanceR > distanceL) {
            moveRight();
        } else {
            moveLeft();
        }
    } else {
        moveForward();
    }
}
