const int trigPin = 6;
const int echoPin = 7;
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

int duration = 0;
int distance = 0;

void setup() 
{
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
 
  if ( distance < 20 )
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(100);
  }
  else
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
 
}