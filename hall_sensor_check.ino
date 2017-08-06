
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int senval_a=analogRead(A0);
  float volt_a=senval_a*(5.0/1023.0);

  int senval_b=analogRead(A1);
  float volt_b=senval_b*(5.0/1023.0);

  int senval_c=analogRead(A2);
  float volt_c=senval_c*(5.0/1023.0);
  Serial.print(volt_a);
  Serial.print('\t');
  Serial.print(volt_b);
  Serial.print('\t');
  Serial.print(volt_c);
  Serial.println();
  

}
