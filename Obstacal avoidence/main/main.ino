#include <Servo.h>

const int trigPin = 6;
const int echoPin = 7;
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;
const int servoPin = 8;

Servo myservo;

void setup() {
    myservo.attach(servoPin);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(leftForward, OUTPUT);
    pinMode(leftBackward, OUTPUT);
    pinMode(rightForward, OUTPUT);
    pinMode(rightBackward, OUTPUT);
    Serial.begin(9600);
}

int getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH);
    return duration / 58.2;
}

void moveForward() {
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
}

void moveLeft() {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
}

void moveRight() {
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, HIGH);
}

void stopMotors() {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, LOW);
}

void loop() {
    int distance = getDistance();
    Serial.println(distance);
    
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
