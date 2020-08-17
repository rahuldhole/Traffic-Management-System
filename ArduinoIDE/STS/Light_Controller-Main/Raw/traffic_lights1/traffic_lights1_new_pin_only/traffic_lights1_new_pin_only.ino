int nr = 5;
int ny = 6;
int ng = 7;
int wr = 8;
int wy = 9;
int wg = 10;
int sr = 48;//11
int sy = 50;//12
int sg = 52;//13
int er = 14;
int ey = 15;
int eg = 16;
int sig = 0;
int interrupt=0;
const int trigPin = 44;//t
const int echoPin = 45;//e
//char light[11] = {nr ny ng wr wy wg sr sy sg er ey eg};
  int l_set[4][3] = {{7,5,6}, {10,8,9}, {52,48,50}, {16,14,15}};
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
        pinMode(19, OUTPUT);
                pinMode(20, OUTPUT);
                pinMode(34, OUTPUT);
                 pinMode(trigPin, OUTPUT);
                  pinMode(echoPin, INPUT);
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
      digitalWrite(34,HIGH);
}
void lights_on(char signal){
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
  switch(signal){
  case 'N':
   interrupt = 1;
    Serial.print(" Start");  
    digitalWrite(l_set[0][0],HIGH);
    digitalWrite(l_set[0][1],LOW);
    delay_check(3000);
    digitalWrite(l_set[0][0],LOW);
    digitalWrite(l_set[0][2],HIGH);
    delay_check(2000);
  break;
  case 'W':
     interrupt = 2;
      Serial.print(" Start");  
    digitalWrite(l_set[1][0],HIGH);
    digitalWrite(l_set[1][1],LOW);
    delay_check(3000);
  digitalWrite(l_set[1][0],LOW);
    digitalWrite(l_set[1][2],HIGH);
    delay_check(2000);
  break;
  case 'S':
     interrupt = 3;
      Serial.print(" Start ");  
    digitalWrite(l_set[2][0],HIGH);
    digitalWrite(l_set[2][1],LOW);
    delay_check(3000);
    digitalWrite(l_set[2][0],LOW);
    digitalWrite(l_set[2][2],HIGH);
    delay_check(2000);
  break;
  case 'E':
     interrupt = 4;
      Serial.print(" Start");  
    digitalWrite(l_set[3][0],HIGH);
    digitalWrite(l_set[3][1],LOW);
    delay_check(3000);
    digitalWrite(l_set[3][0],LOW);
    digitalWrite(l_set[3][2],HIGH);
    delay_check(2000);
  break;
  default:
  Serial.print("Invalid Input...");
  }
      Serial.println("\tEnd");  
}
void delay_check(int d){
  long duration, inches, cm;
for(int i=0; i<=d; i+=200){
  //check();
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Check ok
  duration = pulseIn(echoPin, HIGH);
  interrupt = 0;
  cm = microsecondsToCentimeters(duration);
    analogWrite(A2, 0);
        digitalWrite(19, LOW);
  //interrupt = analogRead(A2);
  Serial.println(cm);
  if(cm<7){
  digitalWrite(19, HIGH);
    digitalWrite(20, HIGH);//intr
  }
  else
    digitalWrite(19, LOW);
        digitalWrite(20, LOW);
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
void loop() {

  lights_on('N');
  lights_on('W');
  lights_on('S');
  lights_on('E');
}






