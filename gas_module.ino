int readpin=A0;
int redpin=8;
int greenpin=7;
int readval;
float val;
float val_med=2;
int time=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval=analogRead(readpin);
  val=5./1023.*readval;
  Serial.println(val);
  if(val<val_med)
  {
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, HIGH);
  }
  else
  {
    digitalWrite(greenpin, LOW);
    digitalWrite(redpin, HIGH);
  }
  delay(time);
}
