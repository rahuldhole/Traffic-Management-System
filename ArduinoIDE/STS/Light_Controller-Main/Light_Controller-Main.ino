/*
created 7 March, 2016
updated 22 April, 2016
 by
 Rahul Dhole,
 Mrunal Surve,
 Ashish Deshmukh.
*/

//Lights' Pins and this 3-3 pins should be consecutive like 123 789 456
int nr = 5;//Connnect to vcc of RED Light of North side signal
int ny = 6;//Connnect to vcc of YELLOW Light of North side signal
int ng = 7;//Connnect to vcc of GREEN Light of North side signal
int wr = 8;//Connnect to vcc of RED Light of WEST side signal
int wy = 9;//Connnect to vcc of YELLOW Light of WEST side signal
int wg = 10;//Connnect to vcc of GREEN Light of WEST side signal
int sr = 11;//Connnect to vcc of RED Light of SOUTH side signal
int sy = 12;//Connnect to vcc of YELLOW Light of SOUTH side signal
int sg = 13;//Connnect to vcc of GREEN Light of SOUTH side signal
int er = 14;//Connnect to vcc of RED Light of EAST side signal
int ey = 15;//Connnect to vcc of YELLOW Light of EAST side signal
int eg = 16;//Connnect to vcc of GREEN Light of EAST side signal

//delays of lights on/off
long dg = 10000;//Set time delay for RED light
long dy = 3000;//Set time delay for YELLOW light

// MATLAB - Arduino communication signals
int sigStatN = 30;//Output connect to PIN 2 of MATLAB ARDUINO
int sigStatW = 31;//Output connect to PIN 3 of MATLAB ARDUINO
int sigStatS = 32;//Output connect to PIN 4 of MATLAB ARDUINO
int sigStatE = 33;//Output connect to PIN 5 of MATLAB ARDUINO

//Read INTR
int INTR_N = 34;
int INTR_W = 35;
int INTR_S = 36;
int INTR_E = 37;
int INTR = 38;

//Specially for yellow signal during interrupt
int INTR_YELLOW_SIG;
int skipY = 0;
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
  pinMode(INTR, INPUT);
  digitalWrite(INTR_N, LOW);
  digitalWrite(INTR_W, LOW);
  digitalWrite(INTR_S, LOW);
  digitalWrite(INTR_E, LOW);
  digitalWrite(INTR, LOW);

  //Initially turn lights to default
  //lightsDef();

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
  digitalWrite(sigStatN, LOW);
  digitalWrite(sigStatW, LOW);
  digitalWrite(sigStatS, LOW);
  digitalWrite(sigStatE, LOW);
  digitalWrite(INTR_N, LOW);
  digitalWrite(INTR_W, LOW);
  digitalWrite(INTR_S, LOW);
  digitalWrite(INTR_E, LOW);
}

//Advance delay type
void delay_check(int d, char l) {
  int statC = 0, inactive = 0;
  for (int i = 0; i <= d; i += 200) {
//now working for north only
    if(skipY == 1 && l == 'y'){
    skipY = 0;
    break;
    }
    //inactive signal remove it if any error
    //after 3 sec to give time to turn off
    //intr signal
    if (i >= 3000) {
      digitalWrite(INTR, LOW);
      inactive = 0;
      inactive = digitalRead(INTR);
      if (inactive == 1 && l == 'g') {
        Serial.println();
        Serial.println("Inactive Signal Interrupted");
        break;
      }
    }
    //Serial.print(i);
    /*
    For check only once i.e. j=1 for more interrupt
    in one signal increase value of "j" followed by
    changes in below if statements  as 'j<possible' INTR's
    */
    if (statC == 0)
      statC = check(l);//check intr
    if (statC) {
      statC = 0;
      if (l == 'y') {
        //if check success and time remain less than
        //1/4 for yellow then break
        if (i > d / 4)
          break;
      }
      Serial.println(INTR_YELLOW_SIG);
    }
    delay(200);
  }
}

//check() ultra status
int check(char l) {
  digitalWrite(INTR_N, LOW);
  digitalWrite(INTR_W, LOW);
  digitalWrite(INTR_S, LOW);
  digitalWrite(INTR_E, LOW);
  int n = digitalRead(INTR_N);
  int w = digitalRead(INTR_W);
  int s = digitalRead(INTR_S);
  int e = digitalRead(INTR_E);
  //  Serial.print(n);
  //  Serial.print(w);
  //  Serial.print(s);
  //  Serial.println(e);

  if (n == 1) {
    Serial.println();
    Serial.print("Interrupted from");
    Serial.println(" North");
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    north_I();
    lightsDef();
    digitalWrite(INTR_YELLOW_SIG - 1, LOW);
    if (l == 'y')
      digitalWrite(INTR_YELLOW_SIG, HIGH);
    if (l == 'g')
      digitalWrite(INTR_YELLOW_SIG + 1, HIGH);
      skipY = 1;
    return 1;
  } else if (w == 1) {
    Serial.println();
    Serial.print("Interrupted from");
    Serial.println(" WEST");
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    west_I();
    lightsDef();
    digitalWrite(INTR_YELLOW_SIG - 1, LOW);
    if (l == 'y')
      digitalWrite(INTR_YELLOW_SIG, HIGH);
    if (l == 'g')
      digitalWrite(INTR_YELLOW_SIG + 1, HIGH);
    return 1;
  } else if (s == 1) {
    Serial.println();
    Serial.print("Interrupted from");
    Serial.println(" SOUTH");
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    south_I();
    lightsDef();
    digitalWrite(INTR_YELLOW_SIG - 1, LOW);
    if (l == 'y')
      digitalWrite(INTR_YELLOW_SIG, HIGH);
    if (l == 'g')
      digitalWrite(INTR_YELLOW_SIG + 1, HIGH);
    return 1;
  } else if (e == 1) {
    Serial.println();
    Serial.print("Interrupted from");
    Serial.println("EAST");
    digitalWrite(INTR_YELLOW_SIG, HIGH);
    delay(dy);
    lightsDef();
    east_I();
    lightsDef();
    digitalWrite(INTR_YELLOW_SIG - 1, LOW);
    if (l == 'y')
      digitalWrite(INTR_YELLOW_SIG, HIGH);
    if (l == 'g')
      digitalWrite(INTR_YELLOW_SIG + 1, HIGH);
    return 1;
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
  Serial.print(" North: ");
  Serial.print(" GREEN ");
  digitalWrite(ng, HIGH);//green
  digitalWrite(nr, LOW);//red
  delay_check(dg, 'g');
  Serial.print(" YELLOW ");
  digitalWrite(ng, LOW);//green
  digitalWrite(ny, HIGH);//yellow
  delay_check(dy, 'y');
  Serial.println(" RED ");
  digitalWrite(ny, LOW);//y
  digitalWrite(nr, HIGH);//red
}

void west() {
  INTR_YELLOW_SIG = wy;
  digitalWrite(sigStatW, HIGH);
  Serial.print(" West: ");
  Serial.print(" GREEN ");
  digitalWrite(wg, HIGH);//g
  digitalWrite(wr, LOW);//r
  delay_check(dg, 'g');
  Serial.print(" YELLOW ");
  digitalWrite(wg, LOW);//g
  digitalWrite(wy, HIGH);//y
  delay_check(dy, 'y');
  Serial.println(" RED ");
  digitalWrite(wy, LOW);//y
  digitalWrite(wr, HIGH);//red
}

void south() {
  INTR_YELLOW_SIG = sy;
  digitalWrite(sigStatS, HIGH);
  Serial.print(" South: ");
  Serial.print(" GREEN ");
  digitalWrite(sg, HIGH);//g
  digitalWrite(sr, LOW);//r
  delay_check(dg, 'g');
  Serial.print(" YELLOW ");
  digitalWrite(sg, LOW);//g
  digitalWrite(sy, HIGH);//y
  delay_check(dy, 'y');
  Serial.println(" RED ");
  digitalWrite(sy, LOW);//y
  digitalWrite(sr, HIGH);//red
}

void east() {
  INTR_YELLOW_SIG = ey;
  digitalWrite(sigStatE, HIGH);
  Serial.print(" East: ");
  Serial.print(" GREEN ");
  digitalWrite(eg, HIGH);
  digitalWrite(er, LOW);
  delay_check(dg, 'g');
  Serial.print(" YELLOW ");
  digitalWrite(eg, LOW);
  digitalWrite(ey, HIGH);
  delay_check(dy, 'y');
  Serial.println(" RED ");
  digitalWrite(ey, LOW);//y
  digitalWrite(er, HIGH);//red
}

//NWSE after interrupt
void north_I() {
  digitalWrite(sigStatN, HIGH);
  Serial.print(" North: ");
  Serial.print(" GREEN ");
  digitalWrite(ng, HIGH);//green
  digitalWrite(nr, LOW);//red
  delay(dg);
  Serial.print(" YELLOW ");
  digitalWrite(ng, LOW);//green
  digitalWrite(ny, HIGH);//yellow
  delay(dy);
  Serial.println(" RED ");
  digitalWrite(ny, LOW);//y
  digitalWrite(nr, HIGH);//red
}

void west_I() {
  digitalWrite(sigStatW, HIGH);
  Serial.print(" West: ");
  Serial.print(" GREEN ");
  digitalWrite(wg, HIGH);//g
  digitalWrite(wr, LOW);//r
  delay(dg);
  Serial.print(" YELLOW ");
  digitalWrite(wg, LOW);//g
  digitalWrite(wy, HIGH);//y
  delay(dy);
  Serial.println(" RED ");
  digitalWrite(wy, LOW);//y
  digitalWrite(wr, HIGH);//red
}

void south_I() {
  digitalWrite(sigStatS, HIGH);
  Serial.print(" South: ");
  Serial.print(" GREEN ");
  digitalWrite(sg, HIGH);//g
  digitalWrite(sr, LOW);//r
  delay(dg);
  Serial.print(" YELLOW ");
  digitalWrite(sg, LOW);//g
  digitalWrite(sy, HIGH);//y
  delay(dy);
  Serial.println(" RED ");
  digitalWrite(sy, LOW);//y
  digitalWrite(sr, HIGH);//red
}

void east_I() {
  digitalWrite(sigStatE, HIGH);
  Serial.print(" East: ");
  Serial.print(" GREEN ");
  digitalWrite(eg, HIGH);
  digitalWrite(er, LOW);
  delay(dg);
  Serial.print(" YELLOW ");
  digitalWrite(eg, LOW);
  digitalWrite(ey, HIGH);
  delay(dy);
  Serial.println(" RED ");
  digitalWrite(ey, LOW);//y
  digitalWrite(er, HIGH);//red
}
