#define echoPin 9
#define trigPin 8
#include <Servo.h>
#include <>
const int M1 = 10;
const int M4 = 10;
const int M2 = 13;
const int M3 = 13;
Servo myservo; 
int pos = 0;    

long duration; 
long distance; 


void setup() {
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  myservo.attach(4);
}


void loop() {
  
digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  delay(50);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,HIGH);
switch (distance <= 10){
case 0:
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  delay(500);
  //for (pos = 30; pos <= 270; pos += 1) { 
  //  myservo.write(pos);
  digitalWrite(M1,HIGH);
  digitalWrite(M4,HIGH);
  break;
}




}
 