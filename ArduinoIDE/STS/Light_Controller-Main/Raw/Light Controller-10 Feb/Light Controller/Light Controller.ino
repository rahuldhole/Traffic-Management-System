/*
created 7 March, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
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

//delays of lights on/off
long dr = 3000;
long dy = 2000;

// MATLAB - Arduino communication signals
int sigStatN = 30;
int sigStatW = 31;
int sigStatS = 32;
int sigStatE = 33;

//Read INTR
int INTR_N = 34;
int INTR_W = 35;
int INTR_S = 36;
int INTR_E = 37;
int INTR_YELLOW_SIG = 0;

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

  //for MATLAB SignalStatus pins initially low
  pinMode(sigStatN, OUTPUT);
  pinMode(sigStatW, OUTPUT);
  pinMode(sigStatS, OUTPUT);
  pinMode(sigStatE, OUTPUT);
  digitalWrite(sigStatN, LOW);
  digitalWrite(sigStatW, LOW);
  digitalWrite(sigStatS, LOW);
  digitalWrite(sigStatE, LOW);
  // Read INTR default LOW
  pinMode(INTR_N, INPUT);
  pinMode(INTR_W, INPUT);
  pinMode(INTR_S, INPUT);
  pinMode(INTR_E, INPUT);
  digitalWrite(INTR_N, LOW);
  digitalWrite(INTR_W, LOW);
  digitalWrite(INTR_S, LOW);
  digitalWrite(INTR_E, LOW);

  //Initially turn lights to default
  lightsDef();

  //Serial com
  Serial.begin(9600);
}

void lightsDef() {
  /////////All Lights default cond
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
}

//Advance delay type
void delay_check(int d) {
  for (int i = 0; i <= d; i += 200) {
    int statC = check();
    //if check success and time remain less than half then break
    if (statC == 1 && i > d / 2)
      break;
    delay(200);
  }
}

//check() ultra status
int check() {
  int n = digitalRead(INTR_N);
  int w = digitalRead(INTR_W);
  int s = digitalRead(INTR_S);
  int e = digitalRead(INTR_E);
  Serial.print(n);
  Serial.print(w);
  Serial.print(s);
  Serial.println(e);

  if (n == 1) {
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    north_I();
    return 1;
  } else if (w == 1) {
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    west_I();
    return 1;
  } else if (s == 1) {
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    south_I();
    return 1;
  } else if (e == 1) {
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    east_I();
    return 1;
  } else {
    INTR_YELLOW_SIG = 0;
  }
  return 0;
}

void loop() {
  lightsDef();
  north();
  lightsDef();
  west();
  lightsDef();
  south();
  lightsDef();
  east();
}

void north() {
  INTR_YELLOW_SIG = ny;
  digitalWrite(sigStatN, HIGH);
  Serial.println(" North ");
  digitalWrite(ng, HIGH);//green
  digitalWrite(nr, LOW);//red
  delay_check(dr);
  digitalWrite(ng, LOW);//green
  digitalWrite(ny, HIGH);//yellow
  delay_check(dy);
  digitalWrite(ny, LOW);//y
  digitalWrite(nr, HIGH);//red
}

void west() {
  INTR_YELLOW_SIG = wy;
  digitalWrite(sigStatW, HIGH);
  Serial.println(" West");
  digitalWrite(wg, HIGH);//g
  digitalWrite(wr, LOW);//r
  delay_check(dr);
  digitalWrite(wg, LOW);//g
  digitalWrite(wy, HIGH);//y
  delay_check(dy);
  digitalWrite(wy, LOW);//y
  digitalWrite(wr, HIGH);//red
}

void south() {
  INTR_YELLOW_SIG = sy;
  digitalWrite(sigStatS, HIGH);
  Serial.println(" South ");
  digitalWrite(sg, HIGH);//g
  digitalWrite(sr, LOW);//r
  delay_check(dr);
  digitalWrite(sg, LOW);//g
  digitalWrite(sy, HIGH);//y
  delay_check(dy);
  digitalWrite(sy, LOW);//y
  digitalWrite(sr, HIGH);//red
}

void east() {
  INTR_YELLOW_SIG = ey;
  digitalWrite(sigStatE, HIGH);
  Serial.println(" East ");
  digitalWrite(eg, HIGH);
  digitalWrite(er, LOW);
  delay_check(dr);
  digitalWrite(eg, LOW);
  digitalWrite(ey, HIGH);
  delay_check(dy);
  digitalWrite(ey, LOW);//y
  digitalWrite(er, HIGH);//red
}

//NWSE after interrupt
void north_I() {
  digitalWrite(sigStatN, HIGH);
  Serial.println(" North ");
  digitalWrite(ng, HIGH);//green
  digitalWrite(nr, LOW);//red
  delay(dr);
  digitalWrite(ng, LOW);//green
  digitalWrite(ny, HIGH);//yellow
  delay(dy);
  digitalWrite(ny, LOW);//y
  digitalWrite(nr, HIGH);//red
}

void west_I() {
  digitalWrite(sigStatW, HIGH);
  Serial.println(" West");
  digitalWrite(wg, HIGH);//g
  digitalWrite(wr, LOW);//r
  delay(dr);
  digitalWrite(wg, LOW);//g
  digitalWrite(wy, HIGH);//y
  delay(dy);
  digitalWrite(wy, LOW);//y
  digitalWrite(wr, HIGH);//red
}

void south_I() {
  digitalWrite(sigStatS, HIGH);
  Serial.println(" South ");
  digitalWrite(sg, HIGH);//g
  digitalWrite(sr, LOW);//r
  delay(dr);
  digitalWrite(sg, LOW);//g
  digitalWrite(sy, HIGH);//y
  delay(dy);
  digitalWrite(sy, LOW);//y
  digitalWrite(sr, HIGH);//red
}

void east_I() {
  digitalWrite(sigStatE, HIGH);
  Serial.println(" East ");
  digitalWrite(eg, HIGH);
  digitalWrite(er, LOW);
  delay(dr);
  digitalWrite(eg, LOW);
  digitalWrite(ey, HIGH);
  delay(dy);
  digitalWrite(ey, LOW);//y
  digitalWrite(er, HIGH);//red
}
