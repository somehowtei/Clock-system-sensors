int GasPin=A0;
int RedPin=2;
int GreenPin=4;
int ReadVal;
float GasVal;
void setup() 
{
  Serial.begin(9600);
  pinMode(GasPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void loop() 
{
  ReadVal=analogRead(GasPin);
  GasVal=5./1023.*ReadVal;
  Serial.print("Gas: ");
  Serial.println(GasVal, 2); // 2 zecimale
  
  if(GasVal<3)
  {
    digitalWrite(GreenPin, HIGH);
    digitalWrite(RedPin, LOW);
  }
  else
  {
    digitalWrite(GreenPin, LOW);
    digitalWrite(RedPin, HIGH);
  }

  delay(200);
}
