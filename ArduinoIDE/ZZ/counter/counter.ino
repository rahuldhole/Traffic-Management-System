/*
 created 11 March, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/

//++Sensor's pins
int vcc1 = 2; //attach pin 2 to vcc
int trig1 = 3; // attach pin 3 to Trig
int echo1 = 4; //attach pin 4 to Echo
int gnd1 = 5; //attach pin 5 to GND
int err_ledVCC1 = 6;
int err_ledGND1 = 7;
int vcc2 = 8; //attach pin 8 to vcc
int trig2 = 9; // attach pin 9 to Trig
int echo2 = 10; //attach pin 10 to Echo
int gnd2 = 11; //attach pin 11 to GND
int err_ledVCC2 = 12;//If ultrasonic gives Error or damages
int err_ledGND2 = 13;

//--Sensor's pins
int vcc1 = 2; //attach pin 2 to vcc
int trig1 = 3; // attach pin 3 to Trig
int echo1 = 4; //attach pin 4 to Echo
int gnd1 = 5; //attach pin 5 to GND
int err_ledVCC1 = 6;
int err_ledGND1 = 7;
int vcc2 = 8; //attach pin 8 to vcc
int trig2 = 9; // attach pin 9 to Trig
int echo2 = 10; //attach pin 10 to Echo
int gnd2 = 11; //attach pin 11 to GND
int err_ledVCC2 = 12;//If ultrasonic gives Error or damages
int err_ledGND2 = 13;

//Opposite sensor --counter
int intrIn = 14;
int intrOp = 15;

const int minD = 7; //Minimum distance for signal break

//ultras distances
long cm1 = 1000, cm2 = 1000;

//light and buzzer to high freq
int i = 0;

void setup() {

  pinMode(err_ledVCC1, OUTPUT);
  pinMode(err_ledGND1, OUTPUT);
  pinMode(err_ledVCC2, OUTPUT);
  pinMode(err_ledGND2, OUTPUT);
  digitalWrite(err_ledVCC1, LOW);
  digitalWrite(err_ledVCC2, LOW);
  digitalWrite(err_ledGND1, LOW);
  digitalWrite(err_ledGND2, LOW);

  //INTR opposite sensor
  pinMode(intrIn, INPUT);
  digitalWrite(intrIn, LOW);
  pinMode(intrOp, OUTPUT);
  digitalWrite(intrOp, LOW);

  //PowerPins
  pinMode (vcc1, OUTPUT);
  pinMode (gnd1, OUTPUT);
  digitalWrite(vcc1, HIGH);
  digitalWrite(gnd1, LOW);
  pinMode (vcc2, OUTPUT);
  pinMode (gnd2, OUTPUT);
  digitalWrite(vcc2, HIGH);
  digitalWrite(gnd2, LOW);

  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo1, INPUT);
  if (cm1 == 0)
    digitalWrite(err_ledVCC1, HIGH);
  else
  {
    duration = pulseIn(echo1, HIGH);//needs restart for reconfiguration
    // convert the time into a distance
    cm1 = duration / 29 / 2;
  }
  Serial.println("Values of this sensors:");
  Serial.print(cm1);
  Serial.print("cm / ");
  //Ultra 1
  pinMode(trig2, OUTPUT);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo1 off of an object.
  pinMode(echo2, INPUT);
  if (cm2 == 0)
    digitalWrite(err_ledVCC2, HIGH);
  else {
    duration = pulseIn(echo2, HIGH);
    // convert the time into a distance
    cm2 = duration / 29 / 2;
  }
  Serial.print(cm2);
  Serial.println("cm");
  if (cm1 < minD && cm2 < minD) {
    if (cm1 > 0 || cm2 > 0)
      digitalWrite(intrOp, HIGH);
  }

  //Displlay counter
  //check interrupt
  int tmp = 0;
  tmp = digitalRead(intrIn);
  if(intrIn==1)
  i++;
  Serial.print("No. of vehicles: ");
  Serial.println(i);
  //Gives Buzzer, Light and INTR to MATLAB for snapshot
}
