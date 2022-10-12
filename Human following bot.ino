const int trigPin1 = 3;
const int trigpin2 = 5;
const int echopin2 = 6;
const int echoPin1 = 2;
const int m1 = 7, m2=8;
const int m3 = 9, m4=10;
// defines variables
long duration1;
long duration2;
int distance1;
int distance2;
void setup()
{
pinMode(trigPin1, OUTPUT);
pinMode(trigpin2, OUTPUT);// Sets the trigPin as an Output
pinMode(echoPin1, INPUT);
pinMode(echopin2, INPUT);// Sets the echoPin as an Input
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);

Serial.begin(9600); // Starts the serial communication
}
void loop()
{
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin1, LOW);

delayMicroseconds(10);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);

digitalWrite(trigpin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigpin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2, LOW);
duration2 = pulseIn(echopin2, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
distance2= duration2*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.print(distance1);
Serial.print("  Distance2: ");
Serial.println(distance2);
delay(100);
if((distance2-distance1)>15)
{
  turn_right();
 
}
else if((distance1-distance2)>15)

{
  turn_left();
}
else if(distance1>10 && distance2>10)
{
  drive_forward();
 
}
else
{
  halt();
}
}
void halt()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  Serial.print("Halt");
}
void drive_forward()
{
  digitalWrite(m1,HIGH);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,HIGH);
  Serial.print("Drive Forward");
}
void turn_right()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
Serial.print("Turn Right");
 
}
void turn_left()
{
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
  Serial.print("Turn Left");
 
}