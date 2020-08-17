/*
created 7 March, 2016
 by 
 Rahul Dhole, 
 Mrunal Surve, 
 Ashish Deshmikh.
*/

//Lights Pin
int nr = 5;
int ny = 6;
int ng = 7;
int wr = 8;
int wy = 9;
int wg = 10;
int sr = 11;//11
int sy = 12;//12
int sg = 13;//13
int er = 14;
int ey = 15;
int eg = 16;

// INTR
char sigStat = 0;
const int minD = 7; //Minimum distance for signal break

//Sensors Pin
const int trigPinN = 44;//t
const int echoPinN = 45;//e
const int trigPinW = 46;//t
const int echoPinW = 47;//e
const int trigPinS = 48;//t
const int echoPinS = 49;//e
const int trigPinE = 50;//t
const int echoPinE = 51;//e
const int ultraGND = 52;
const int ultraVCC = 53;//common for all sensors

//char light[11] = {nr ny ng wr wy wg sr sy sg er ey eg};
int l_set[4][3] = {{7, 5, 6}, {10, 8, 9}, {13, 11, 12}, {16, 14, 15}};

void setup() {
  //Traffic Lights
  pinMode(nr, OUTPUT);
  pinMode(ny, OUTPUT);
  pinMode(ng, OUTPUT);
  pinMode(wr, OUTPUT);
  pinMode(wy, OUTPUT);
  pinMode(wg, OUTPUT);
  pinMode(sr, OUTPUT);
  pinMode(sy, OUTPUT);
  pinMode(sg, OUTPUT);
  pinMode(er, OUTPUT);
  pinMode(ey, OUTPUT);
  pinMode(eg, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(34, OUTPUT);

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
  digitalWrite(ultraVCC, LOW);

  //Serial
  Serial.begin(9600);

  /////////On Lights
  digitalWrite(nr, LOW);
  digitalWrite(ny, LOW);
  digitalWrite(ng, LOW);
  digitalWrite(wr, LOW);
  digitalWrite(wy, LOW);
  digitalWrite(wg, LOW);
  digitalWrite(sr, LOW);
  digitalWrite(sy, LOW);
  digitalWrite(sg, LOW);
  digitalWrite(er, LOW);
  digitalWrite(ey, LOW);
  digitalWrite(eg, LOW);
  digitalWrite(34, HIGH);
}
void lights_on(char signal) {
  Serial.print("Signal: ");
  Serial.print(signal);
  digitalWrite(nr, HIGH);
  digitalWrite(ny, LOW);
  digitalWrite(ng, LOW);
  digitalWrite(wr, HIGH);
  digitalWrite(wy, LOW);
  digitalWrite(wg, LOW);
  digitalWrite(sr, HIGH);
  digitalWrite(sy, LOW);
  digitalWrite(sg, LOW);
  digitalWrite(er, HIGH);
  digitalWrite(ey, LOW);
  digitalWrite(eg, LOW);
  delay(200);
  switch (signal) {
    case 'N':
      sigStat = 'N';
      Serial.print(" Start");
      digitalWrite(l_set[0][0], HIGH);
      digitalWrite(l_set[0][1], LOW);
      delay_check(3000);
      digitalWrite(l_set[0][0], LOW);
      digitalWrite(l_set[0][2], HIGH);
      delay_check(2000);
      break;
    case 'W':
      sigStat = 'W';
      Serial.print(" Start");
      digitalWrite(l_set[1][0], HIGH);
      digitalWrite(l_set[1][1], LOW);
      delay_check(3000);
      digitalWrite(l_set[1][0], LOW);
      digitalWrite(l_set[1][2], HIGH);
      delay_check(2000);
      break;
    case 'S':
      sigStat = 'S';
      Serial.print(" Start ");
      digitalWrite(l_set[2][0], HIGH);
      digitalWrite(l_set[2][1], LOW);
      delay_check(3000);
      digitalWrite(l_set[2][0], LOW);
      digitalWrite(l_set[2][2], HIGH);
      delay_check(2000);
      break;
    case 'E':
      sigStat = 'E';
      Serial.print(" Start");
      digitalWrite(l_set[3][0], HIGH);
      digitalWrite(l_set[3][1], LOW);
      delay_check(3000);
      digitalWrite(l_set[3][0], LOW);
      digitalWrite(l_set[3][2], HIGH);
      delay_check(2000);
      break;
    default:
      Serial.print("Invalid Input...");
  }
  Serial.println("\tEnd");
}
/*
------------------------------------------------------------------------------------------------------------------------------------------
******************************************************************************************************************************************
------------------------------------------------------------------------------------------------------------------------------------------
*/
void delay_check(int d) {
  for (int i = 0; i <= d; i += 200) {
    check();
    //    digitalWrite(19, LOW);//buzzer off

    delay(200);
  }
}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//////////////////////////////////////Check
void check() {
  long duration, inches, dN = 1000, dW = 1000, dS = 1000, dE = 1000;

  //sensor N
  digitalWrite(trigPinN, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinN, LOW);
  duration = pulseIn(echoPinN, HIGH);
  dN = microsecondsToCentimeters(duration);
  Serial.println("North\tWest\tSouth\tEast");
  Serial.println(dN);

  //sensor W
  digitalWrite(trigPinW, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinW, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinW, LOW);
  duration = pulseIn(echoPinW, HIGH);
  dW = microsecondsToCentimeters(duration);
  Serial.print('\t');
  Serial.print(dN);

  //sensor S
  digitalWrite(trigPinS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinS, LOW);
  duration = pulseIn(echoPinS, HIGH);
  dS = microsecondsToCentimeters(duration);
  Serial.print('\t');
  Serial.print(dS);

  //sensor E
  digitalWrite(trigPinE, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinE, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinE, LOW);
  duration = pulseIn(echoPinE, HIGH);
  dE = microsecondsToCentimeters(duration);
  Serial.print('\t');
  Serial.print(dE);

  //Gives Buzzer and INTR to MATLAB for snapshot
  if (dN < minD) {
    digitalWrite(19, HIGH);//buzzer on
    digitalWrite(20, HIGH);//intr signal to matlab
  }
  if (dW < minD) {
    digitalWrite(19, HIGH);//buzzer on
  }
  if (dS < minD) {
    digitalWrite(19, HIGH);//buzzer on
  }
  if (dE < minD) {
    digitalWrite(19, HIGH);//buzzer on
  }
  if (dN > minD && dW > minD && dS > minD && dE > minD) {
    digitalWrite(19, LOW);
    digitalWrite(20, LOW);
  }
}

void loop() {
  lights_on('N');
  lights_on('W');
  lights_on('S');
  lights_on('E');
}






