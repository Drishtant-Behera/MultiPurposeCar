#include <Servo.h> 
const int trigPin = 6;
const int echoPin = 7;
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

int duration = 0;
int distance = 0;

Servo myservo;

void setup() 
{
  myservo.attach(10);
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  Serial.begin(9600);

}

void loop()
{
digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  delay(0);
 
 int lookRight()
{
    myservo.write(50); 
    delay(500);
    delay(100);
    myservo.write(115); 
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    delay(100);
    myservo.write(115); 
    delay(100);
}

  if ( distance < 20 )
  {
    if(distanceR>=distanceL){
      digitalWrite(leftForward , HIGH);
      digitalWrite(leftBackward , LOW);
      digitalWrite(rightForward , LOW);
      digitalWrite(rightBackward , HIGH);
    }
    else
        { digitalWrite(leftForward , LOW);
      digitalWrite(leftBackward , HIGH);
      digitalWrite(rightForward , HIGH);
      digitalWrite(rightBackward , LOW);}
      }
  else
        { digitalWrite(leftForward , HIGH);
      digitalWrite(leftBackward , LOW);
      digitalWrite(rightForward , HIGH);
      digitalWrite(rightBackward , LOW);}
      }




}




