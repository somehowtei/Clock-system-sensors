#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int GasPin=A0;
int RedPin=2;
int GreenPin=4;
int ReadVal;
float GasVal;

void setup() 
{
  Serial.begin(9600);

  if (!rtc.begin()) 
  {
    Serial.println("Nu gasesc RTC!");
    while (1);
  }

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  dht.begin();  

  pinMode(GasPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void loop() 
{
  DateTime now=rtc.now();
  Serial.print("Time: ");
  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.print(now.year());
  Serial.print(" ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second());
  Serial.print("    ");

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.print(" ");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("*C");
  Serial.print("    ");

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

  delay(1000);
}
