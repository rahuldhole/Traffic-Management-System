/*
 created 17 April, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/
//com16
//Minimum distance for signal break set = width(ROAD);
const int minD = 7;

//Sensor's pins
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
int vcc3 = 14;
int trig3 = 15;
int echo3 = 16;
int gnd3 = 17;
int err_ledVCC3 = 18;
int err_ledGND3 = 19;
int vcc4 = 20;
int trig4 = 21;
int echo4 = 22;
int gnd4 = 23;
int err_ledVCC4 = 24;
int err_ledGND4 = 25;
//Sensors Variables
int ErrMax = 20;//appx if 20 then 10 seconds i.e. half of time
int dErrMax = 5;
long duration[4], dN = 1000, dW = 1000, dS = 1000, dE = 1000;
long nErr = ErrMax, wErr = ErrMax, sErr = ErrMax, eErr = ErrMax;
long dnErr = dErrMax, dwErr = dErrMax, dsErr = dErrMax, deErr = dErrMax;

int ledMax = 10;
long nLED = ledMax, wLED = ledMax, sLED = ledMax, eLED = ledMax;

//On vehicle detect led and matlab input through a wire signal
int CamN = 26;
int CamNVeri = 27;
int CamNErr = 28;
int ledN = 29;//All led ground common

int CamW = 30;
int CamWVeri = 31;
int CamWErr = 32;
int ledW = 33;

int CamS = 34;
int CamSVeri = 35;
int CamSErr = 36;
int ledS = 37;

int CamE = 38;
int CamEVeri = 39;
int CamEErr = 40;
int ledE = 41;

void setup() {

  //Sensor Pin Conf
  pinMode(vcc1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(err_ledVCC1, OUTPUT);
  pinMode(err_ledGND1, OUTPUT);

  pinMode(vcc2, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(gnd2, OUTPUT);
  pinMode(err_ledVCC2, OUTPUT);
  pinMode(err_ledGND2, OUTPUT);

  pinMode(vcc3, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(gnd3, OUTPUT);
  pinMode(err_ledVCC3, OUTPUT);
  pinMode(err_ledGND3, OUTPUT);

  pinMode(vcc4, OUTPUT);
  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);
  pinMode(gnd4, OUTPUT);
  pinMode(err_ledVCC4, OUTPUT);
  pinMode(err_ledGND4, OUTPUT);

  digitalWrite(vcc1, HIGH);
  digitalWrite(gnd1, LOW);
  digitalWrite(err_ledVCC1, LOW);
  digitalWrite(err_ledGND1, LOW);

  digitalWrite(vcc2, HIGH);
  digitalWrite(gnd2, LOW);
  digitalWrite(err_ledVCC2, LOW);
  digitalWrite(err_ledGND2, LOW);

  digitalWrite(vcc3, HIGH);
  digitalWrite(gnd3, LOW);
  digitalWrite(err_ledVCC3, LOW);
  digitalWrite(err_ledGND3, LOW);

  digitalWrite(vcc4, HIGH);
  digitalWrite(gnd4, LOW);
  digitalWrite(err_ledVCC4, LOW);
  digitalWrite(err_ledGND4, LOW);

  digitalWrite(vcc1, HIGH);
  digitalWrite(gnd1, LOW);
  digitalWrite(err_ledGND1, LOW);

  digitalWrite(vcc2, HIGH);
  digitalWrite(gnd2, LOW);
  digitalWrite(err_ledGND2, LOW);

  digitalWrite(vcc3, HIGH);
  digitalWrite(gnd3, LOW);
  digitalWrite(err_ledGND3, LOW);

  digitalWrite(vcc4, HIGH);
  digitalWrite(gnd4, LOW);
  digitalWrite(err_ledGND4, LOW);

  //On vehicle detect led and matlab wired signal
  pinMode(CamN, OUTPUT);
  pinMode(CamNVeri, INPUT);
  pinMode(CamNErr, OUTPUT);
  pinMode(ledN, OUTPUT);
  digitalWrite(ledN, LOW);
  digitalWrite(CamN, LOW);
  digitalWrite(CamNVeri, LOW);
  digitalWrite(CamNErr, LOW);

  pinMode(CamW, OUTPUT);
  pinMode(CamWVeri, INPUT);
  pinMode(CamWErr, OUTPUT);
  pinMode(ledW, OUTPUT);
  digitalWrite(ledW, LOW);
  digitalWrite(CamW, LOW);
  digitalWrite(CamWVeri, LOW);
  digitalWrite(CamWErr, LOW);

  pinMode(CamS, OUTPUT);
  pinMode(CamSVeri, INPUT);
  pinMode(CamSErr, OUTPUT);
  pinMode(ledS, OUTPUT);
  digitalWrite(ledS, LOW);
  digitalWrite(CamS, LOW);
  digitalWrite(CamSVeri, LOW);
  digitalWrite(CamSErr, LOW);

  pinMode(CamE, OUTPUT);
  pinMode(CamEVeri, INPUT);
  pinMode(CamEErr, OUTPUT);
  pinMode(ledE, OUTPUT);
  digitalWrite(ledE, LOW);
  digitalWrite(CamE, LOW);
  digitalWrite(CamEVeri, LOW);
  digitalWrite(CamEErr, LOW);

  //Serial com
  Serial.begin(9600);
}

void loop() {

  pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);

  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);

  delayMicroseconds(5);
  digitalWrite(trig1, LOW);

  Serial.println("North\tWest\tSouth\tEast");
  pinMode(echo1, INPUT);

  duration[0] = pulseIn(echo1, HIGH);
  dN = duration[0] / 29 / 2;
  Serial.print(dN);
  Serial.print('\t');

  pinMode(trig2, OUTPUT);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2, LOW);
  pinMode(echo2, INPUT);

  duration[1] = pulseIn(echo2, HIGH);

  dW = duration[1] / 29 / 2;

  Serial.print(dW);
  Serial.print('\t');

  pinMode(trig3, OUTPUT);
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig3, LOW);

  pinMode(echo3, INPUT);
  duration[2] = pulseIn(echo3, HIGH);
  dS = duration[2] / 29 / 2;

  Serial.print(dS);
  Serial.print('\t');

  pinMode(trig4, OUTPUT);
  digitalWrite(trig4, LOW);
  delayMicroseconds(2);
  digitalWrite(trig4, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig4, LOW);
  pinMode(echo4, INPUT);
  duration[3] = pulseIn(echo4, HIGH);
  dE = duration[3] / 29 / 2;
  Serial.println(dE);


  if (dN == 0)
    digitalWrite(err_ledVCC1, HIGH);
  else
    digitalWrite(err_ledVCC1, LOW);
  if (dW == 0)
    digitalWrite(err_ledVCC2, HIGH);
  else
    digitalWrite(err_ledVCC2, LOW);
  if (dS == 0)
    digitalWrite(err_ledVCC3, HIGH);
  else
    digitalWrite(err_ledVCC3, LOW);
  if (dE == 0)
    digitalWrite(err_ledVCC4, HIGH);
  else
    digitalWrite(err_ledVCC4, LOW);

  int CamNVT = 0, CamWVT = 0, CamSVT = 0, CamEVT = 0;
  //Gives led and INTR to MATLAB for snapshot
  if (dN < minD && dN > 0) {
    digitalWrite(ledN, HIGH);//led on
    digitalWrite(CamN, HIGH);//intr signal to matlab
    nLED = 0;
    if (nErr == ErrMax)
      nErr = 0;
  }
  if (dW < minD && dW > 0) {
    digitalWrite(ledW, HIGH);//led on
    digitalWrite(CamW, HIGH);//intr signal to matlab
    wLED = 0;
    if (wErr == ErrMax)
      wErr = 0;
  }
  if (dS < minD && dS > 0) {
    digitalWrite(ledS, HIGH);//led on
    digitalWrite(CamS, HIGH);//intr signal to matlab
    sLED = 0;
    if (sErr == ErrMax)
      sErr = 0;
  }
  if (dE < minD && dE > 0) {
    digitalWrite(ledE, HIGH);//led on
    digitalWrite(CamE, HIGH);//intr signal to matlab
    eLED = 0;
    if (eErr == ErrMax)
      eErr = 0;
  }

  //Turn on LED for 2 seconds
  if (nLED < ledMax)
    nLED++;
  else
    digitalWrite(ledN, LOW);

  if (wLED < ledMax)
    wLED++;
  else
    digitalWrite(ledW, LOW);

  if (sLED < ledMax)
    sLED++;
  else
    digitalWrite(ledS, LOW);

  if (eLED < ledMax)
    eLED++;
  else
    digitalWrite(ledE, LOW);

  //Verification of camera interrupt
  if (nErr < ErrMax) {
    nErr++;
    CamNVT = digitalRead(CamNVeri);
    if (CamNVT) {
      digitalWrite(CamN, LOW);
      digitalWrite(CamNErr, LOW);
      nErr = ErrMax;
    }
    //ErrMax is 100 appx. equivalent to 5 seconds
    if (nErr == ErrMax - 1) {
      digitalWrite(CamN, LOW);
      digitalWrite(CamNErr, HIGH);
    }
  }

  if (wErr < ErrMax) {
    wErr++;
    CamWVT = digitalRead(CamWVeri);
    if (CamWVT) {
      digitalWrite(CamW, LOW);
      digitalWrite(CamWErr, LOW);
      wErr = ErrMax;
    }
    if (wErr == ErrMax - 1) {
      digitalWrite(CamW, LOW);
      digitalWrite(CamWErr, HIGH);
    }
  }

  if (sErr < ErrMax) {
    sErr++;
    CamSVT = digitalRead(CamSVeri);
    if (CamSVT) {
      digitalWrite(CamS, LOW);
      digitalWrite(CamSErr, LOW);
      sErr = ErrMax;
    }
    if (sErr == ErrMax - 1) {
      digitalWrite(CamS, LOW);
      digitalWrite(CamSErr, HIGH);
    }
  }

  if (eErr < ErrMax) {
    eErr++;
    CamEVT = digitalRead(CamEVeri);
    if (CamEVT) {
      digitalWrite(CamE, LOW);
      digitalWrite(CamEErr, LOW);
      eErr = ErrMax;
    }
    if (eErr == ErrMax - 1) {
      digitalWrite(CamE, LOW);
      digitalWrite(CamEErr, HIGH);
    }
  }
}
