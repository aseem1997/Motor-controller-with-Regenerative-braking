#define DELAY 20
#define DEAD 100
byte duty = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT); //M1
  pinMode(5,OUTPUT); //M4
  pinMode(6,OUTPUT); //M3
  pinMode(9,OUTPUT); //M2
  pinMode(10,OUTPUT);//M6
  pinMode(11,OUTPUT);//M5
  pinMode(13,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
}

void rpm()
{
  analogWrite(5,0);
  delayMicroseconds(DEAD);
  analogWrite(3,duty);
}

void rnm()
{
  analogWrite(3,0);
  delayMicroseconds(DEAD);
  analogWrite(5,duty);
}

void rzm()
{
  delayMicroseconds(DEAD);
  analogWrite(3,0);
  analogWrite(5,0);
}

void ypm()
{
  analogWrite(9,0);
  delayMicroseconds(DEAD);
  analogWrite(6,duty);
}

void ynm()
{
  analogWrite(6,0);
  delayMicroseconds(DEAD);
  analogWrite(9,duty);
}

void yzm()
{
  delayMicroseconds(DEAD);
  analogWrite(9,0);
  analogWrite(6,0);
}

void bpm()
{
  analogWrite(11,0);
  delayMicroseconds(DEAD);
  analogWrite(10,duty);
}

void bnm()
{
  analogWrite(10,0);
  delayMicroseconds(DEAD);
  analogWrite(11,duty);
}

void bzm()
{
  delayMicroseconds(DEAD);
  analogWrite(10,0);
  analogWrite(11,0);
}

void a30()
{
  yzm();
  bnm();
  rpm();
}

void a90()
{
  rzm();
  bnm();
  ypm();
}

void a150()
{
  bzm();
  rnm();
  ypm();
}

void a210()
{
  yzm();
  rnm();
  bpm();
}

void a270()
{
  rzm();
  ynm();
  bpm();
}

void a330()
{
  bzm();
  ynm();
  rpm();
}

bool a3,a4,a5;
int a0;

void loop() {

//  a30();
//  delay(DELAY);
//  a90();
//  delay(DELAY);
//  a150();
//  delay(DELAY);
//  a210();
//  delay(DELAY);
//  a270();
//  delay(DELAY);
//  a330();
//  delay(DELAY);
  
  a3 = digitalRead(A3);
  a4 = digitalRead(A4);
  a5 = digitalRead(A5);
  a0 = analogRead(A0);
  duty = a0/4;
  if(a3 == 1 && a4 == 0 && a5 == 0)
  {
    a210();
//    Serial.print("30 : ");
  }
  else if(a3 == 1 && a4 == 1 && a5 == 0)
  {
    a150();
//    Serial.print("90 : ");
  }
  else if(a3 == 0 && a4 == 1 && a5 == 0)
  {
    a90();
//    Serial.print("150 : ");
  }
  else if(a3 == 0 && a4 == 1 && a5 == 1)
  {
    a30();
//    Serial.print("210 : ");
  }
  else if(a3 == 0 && a4 == 0 && a5 == 1)
  {
    a330();
//    Serial.print("270 : ");
  }
  else if(a3 == 1 && a4 == 0 && a5 == 1)
  {
    a270();
//    Serial.print("330 : ");
  }
//  Serial.print(a3);
//  Serial.print(" , ");
//  Serial.print(a4);
//  Serial.print(" , ");
//  Serial.println(a5);
}
