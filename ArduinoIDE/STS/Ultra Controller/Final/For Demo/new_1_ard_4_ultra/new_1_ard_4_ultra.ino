/*
for ultra checking only
 created 7 March, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/
//com 16
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

//On vehicle detect led and matlab input through a wire signal
int CamN = 26;
int CamNVeri = 27;

int CamW = 30;
int CamWVeri = 31;

int CamS = 34;
int CamSVeri = 35;

int CamE = 38;
int CamEVeri = 39;

void setup() {

  //Sensor Pin Conf
  pinMode(vcc1, OUTPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(err_ledVCC1, OUTPUT);
  pinMode(err_ledGND1, OUTPUT);

  pinMode(vcc2, OUTPUT);
  pinMode(gnd2, OUTPUT);
  pinMode(err_ledVCC2, OUTPUT);
  pinMode(err_ledGND2, OUTPUT);

  pinMode(vcc3, OUTPUT);
  pinMode(gnd3, OUTPUT);
  pinMode(err_ledVCC3, OUTPUT);
  pinMode(err_ledGND3, OUTPUT);

  pinMode(vcc4, OUTPUT);
  pinMode(gnd4, OUTPUT);
  pinMode(err_ledVCC4, OUTPUT);
  pinMode(err_ledGND4, OUTPUT);

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
  digitalWrite(CamN, LOW);
  digitalWrite(CamNVeri, LOW);

  pinMode(CamW, OUTPUT);
  pinMode(CamWVeri, INPUT);
  digitalWrite(CamW, LOW);
  digitalWrite(CamWVeri, LOW);

  pinMode(CamS, OUTPUT);
  pinMode(CamSVeri, INPUT);
  digitalWrite(CamS, LOW);
  digitalWrite(CamSVeri, LOW);

  pinMode(CamE, OUTPUT);
  pinMode(CamEVeri, INPUT);
  digitalWrite(CamE, LOW);
  digitalWrite(CamEVeri, LOW);

  //Serial com
  Serial.begin(9600);
}

void loop() {
  long duration[4], dN = 1000, dW = 1000, dS = 1000, dE = 1000, nErr = 0, wErr = 0, sErr = 0, eErr = 0;
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

  int CamNVT = 0, CamWVT = 0, CamSVT = 0, CamEVT = 0;
  //Gives led and INTR to MATLAB for snapshot
  if (dN < minD && dN > 0) {
    digitalWrite(CamN, HIGH);//intr signal to matlab
    nErr = 0;
  }
  if (dW < minD && dW > 0) {
    digitalWrite(CamW, HIGH);//intr signal to matlab
    wErr = 0;
  }
  if (dS < minD && dS > 0) {
    digitalWrite(CamS, HIGH);//intr signal to matlab
    sErr = 0;
  }
  if (dE < minD && dE > 0) {
    digitalWrite(CamE, HIGH);//intr signal to matlab
    eErr = 0;
  }

  //Verification of camera interrupt
  if (nErr < 5000) {
    CamNVT = digitalRead(CamNVeri);
    if (CamNVT) {
      digitalWrite(CamN, LOW);
      nErr = 5000;
    }
    else if (nErr < 5000)
      nErr++;
    //5000 appx. equivalent to 5 seconds
    if (nErr == 4999) {
      digitalWrite(CamN, LOW);
    }
  }

  if (wErr < 5000) {
    CamWVT = digitalRead(CamWVeri);
    if (CamWVT) {
      digitalWrite(CamW, LOW);
      wErr = 5000;
    }
    else if (wErr < 5000)
      wErr++;
    if (wErr == 4999) {
      digitalWrite(CamW, LOW);
    }
  }

  if (sErr < 5000) {
    CamSVT = digitalRead(CamSVeri);
    if (CamSVT) {
      digitalWrite(CamS, LOW);
      sErr = 5000;
    }
    else if (sErr < 5000)
      sErr++;
    if (sErr == 4999) {
      digitalWrite(CamS, LOW);
    }
  }

  if (eErr < 5000) {
    CamEVT = digitalRead(CamEVeri);
    if (CamEVT) {
      digitalWrite(CamE, LOW);
      eErr = 5000;
    }
    else if (eErr < 5000)
      eErr++;
    if (eErr == 4999) {
      digitalWrite(CamE, LOW);
    }
  }
}
