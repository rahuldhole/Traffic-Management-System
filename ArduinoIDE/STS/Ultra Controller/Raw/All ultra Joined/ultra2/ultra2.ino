/*
 created 7 March, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/

//Sensor's pins
int vcc = 2; //attach pin 2 to vcc
int trig = 3; // attach pin 3 to Trig
int echo = 4; //attach pin 4 to Echo
int trig1 = 11; // attach pin 3 to Trig
int echo1 = 12; //attach pin 4 to Echo
int gnd = 5; //attach pin 5 to GND

const int minD = 7; //Minimum distance for signal break

//On vehicle detect buzzer and matlab input through a wire signal
int buzzer = 7;
int light = 8;
int Cam = 9;

void setup() {

  //On vehicle detect buzzer and matlab wired signal
  pinMode(Cam, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(light, OUTPUT);
  digitalWrite(Cam, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(light, LOW);
  pinMode (vcc, OUTPUT);
  pinMode (gnd, OUTPUT);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);

  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo, INPUT);

  duration = pulseIn(echo, HIGH);

  // convert the time into a distance
  cm = duration / 29 / 2;

  Serial.print(cm);
  Serial.print("cm / ");
  //Ultra 1
    pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo1 off of an object.
  pinMode(echo1, INPUT);

  duration = pulseIn(echo1, HIGH);

  // convert the time into a distance
  cm = duration / 29 / 2;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  //Gives Buzzer, Light and INTR to MATLAB for snapshot
  if (cm < minD) {
    digitalWrite(buzzer, HIGH);//buzzer on
    digitalWrite(Cam, HIGH);//intr signal to matlab
    digitalWrite(light, HIGH);
  }
  else {
    digitalWrite(Cam, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(light, LOW);
  }
}
