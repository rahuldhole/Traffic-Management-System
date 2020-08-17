int nr = 5;
int ny = 6;
int ng = 7;
int wr = 8;
int wy = 9;
int wg = 10;
int sr = 48;//
int sy = 50;//
int sg = 52;//
int er = 14;
int ey = 15;
int eg = 16;
//char light[11] = {nr ny ng wr wy wg sr sy sg er ey eg};
  int l_set[4][4] = {{2,4,9,6}, {0,5,7,9}, {0,3,8,10}, {1,3,6,11}};
void setup() {
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
    digitalWrite(3, LOW);
}

void loop() {
for(int i=5; i<17; i++){
digitalWrite(i, HIGH);
delay(300);
}
for(int i=5; i<17; i++){
digitalWrite(i, LOW);
delay(300);
}
}





