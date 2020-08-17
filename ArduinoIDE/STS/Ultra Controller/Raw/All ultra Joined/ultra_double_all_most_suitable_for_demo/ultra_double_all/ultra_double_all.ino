/*
 created 7 March, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/

//Minimum distance for signal break set = width(ROAD);
const int minD = 7; 

//Sensor's pins
const int trigPinN = 44;//t
const int echoPinN = 45;//e
const int trigPinW = 46;//t
const int echoPinW = 47;//e
const int trigPinS = 48;//t
const int echoPinS = 49;//e
const int trigPinE = 50;//t
const int echoPinE = 51;//e
const int ultraGND = 52;//common for all sensors
const int ultraVCC = 53;

//Sensors Variables
long duration[4], dN = 1000, dW = 1000, dS = 1000, dE = 1000;

//On vehicle detect buzzer and matlab input through a wire signal
int buzzer = 22;
int CamN = 23;
int CamW = 24;
int CamS = 25;
int CamE = 26;

void setup() {

  //Sensor Pin Conf
  pinMode(trigPinN, OUTPUT);
  pinMode(echoPinN, INPUT);
  pinMode(trigPinW, OUTPUT);
  pinMode(echoPinW, INPUT);
  pinMode(trigPinS, OUTPUT);
  pinMode(echoPinS, INPUT);
  pinMode(trigPinE, OUTPUT);
  pinMode(echoPinE, INPUT);
  digitalWrite(ultraGND, LOW);
  digitalWrite(ultraVCC, HIGH);

  //On vehicle detect buzzer and matlab wired signal
  pinMode(CamN, OUTPUT);
  pinMode(CamW, OUTPUT);
  pinMode(CamS, OUTPUT);
  pinMode(CamE, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(CamN, LOW);
  digitalWrite(CamW, LOW);
  digitalWrite(CamS, LOW);
  digitalWrite(CamE, LOW);
  digitalWrite(buzzer, LOW);

  //Serial com
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPinN, LOW);
  digitalWrite(trigPinW, LOW);
  digitalWrite(trigPinS, LOW);
  digitalWrite(trigPinE, LOW);

  digitalWrite(trigPinN, HIGH);
  digitalWrite(trigPinW, HIGH);
  digitalWrite(trigPinS, HIGH);
  digitalWrite(trigPinE, HIGH);

  digitalWrite(trigPinN, LOW);
  digitalWrite(trigPinW, LOW);
  digitalWrite(trigPinS, LOW);
  digitalWrite(trigPinE, LOW);

  Serial.print("0");
  duration[0] = pulseIn(echoPinN, HIGH);
  Serial.print("1");
  //  duration[1] = pulseIn(echoPinW, HIGH);
  Serial.print("2");
  //duration[2] = pulseIn(echoPinS, HIGH);
  Serial.print("3");
  //duration[3] = pulseIn(echoPinE, HIGH);
  Serial.print("4");

  dN = duration[0] / 29 / 2;
  Serial.println("North\tWest\tSouth\tEast");
  Serial.print(dN);

  digitalWrite(trigPinW, LOW);

  dW = duration[1] / 29 / 2;
  Serial.print('\t');
  Serial.print(dN);

  digitalWrite(trigPinS, LOW);

  dS = duration[2] / 29 / 2;
  Serial.print('\t');
  Serial.print(dS);

  digitalWrite(trigPinE, LOW);

  dE = duration[3] / 29 / 2;
  Serial.print('\t');
  Serial.println(dE);
  //Gives Buzzer and INTR to MATLAB for snapshot
  if (dN < minD) {
    digitalWrite(buzzer, HIGH);//buzzer on
    digitalWrite(CamN, HIGH);//intr signal to matlab
  }
  if (dW < minD) {
    digitalWrite(buzzer, HIGH);//buzzer on
    digitalWrite(CamW, HIGH);//intr signal to matlab
  }
  if (dS < minD) {
    digitalWrite(buzzer, HIGH);//buzzer on
    digitalWrite(CamS, HIGH);//intr signal to matlab
  }
  if (dE < minD) {
    digitalWrite(buzzer, HIGH);//buzzer on
    digitalWrite(CamE, HIGH);//intr signal to matlab
  }
  if (dN > minD && dW > minD && dS > minD && dE > minD) {
    digitalWrite(CamN, LOW);
    digitalWrite(CamW, LOW);
    digitalWrite(CamS, LOW);
    digitalWrite(CamE, LOW);
    digitalWrite(buzzer, LOW);
  }
}
