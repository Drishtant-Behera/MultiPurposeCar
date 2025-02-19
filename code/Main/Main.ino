// Pin Configuration
// Trigger Pin: 6
// Echo Pin: 7
// Servo Pin: 8
// Left Motor Forward: 2
// Left Motor Backward: 3
// Right Motor Forward: 4
// Right Motor Backward: 5

#include "UltrasonicMotorControl.ino"

UltrasonicMotorControl motorControl(6, 7, 8, 2, 3, 4, 5);
bool ultrasonicMode = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();
        if (command == 'e') {
            ultrasonicMode = true;
            motorControl.enable();
        } else if (command == 'd') {
            ultrasonicMode = false;
            motorControl.disable();
        }
    }
    if (ultrasonicMode) {
        motorControl.update();
    }
}
