#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int mode=0;
int button_rtc=8;
int button_rtc_val;
int button_dht=9;
int button_dht_val;
int button_gas=10;
int button_gas_val;
int GasPin=A0;
int RedPin=2;
int GreenPin=4;
int ReadVal;
float GasVal;

void printclock(int number) //functie pt ceas
{
  if(number<10)
  {
    lcd.print("0");
  }
  lcd.print(number);
}

void printval(float number) //functie pt valori
{
  if(number<10)
  {
    lcd.print("0");
  }
  lcd.print(number, 2);
}

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) 
  {
    Serial.println("Nu gasesc RTC!");
    while (1);
  }

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  dht.begin();  

  pinMode(button_rtc, INPUT_PULLUP);
  pinMode(button_dht, INPUT_PULLUP);
  pinMode(button_gas, INPUT_PULLUP);
  pinMode(GasPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
}

void loop() 
{
  button_rtc_val=digitalRead(button_rtc);
  button_dht_val=digitalRead(button_dht);
  button_gas_val=digitalRead(button_gas);

  if(button_rtc_val==0)
  {
    mode=1;
  }
  else if(button_dht_val==0)
  {
    mode=2;
  }
  else if(button_gas_val==0)
  {
    mode=3;
  }

  Serial.print(button_rtc_val);
  Serial.print(button_dht_val);
  Serial.println(button_gas_val);

  lcd.clear();
  
  if(mode==0)
  {
    lcd.setCursor(0,0);
    lcd.print("   Press any");
    lcd.setCursor(0,1);
    lcd.print("    button!");
  }

  DateTime now=rtc.now();

  if(mode==1)
  {
    lcd.setCursor(0,0); //pe prima linie a LCD-ului
    lcd.print("Day:");
    printclock(now.day());
    lcd.print("/");
    printclock(now.month());
    lcd.print("/");
    printclock(now.year());
    lcd.setCursor(0,1); //pe randul urmator
    lcd.print("Time:");
    printclock(now.hour());
    lcd.print(":");
    printclock(now.minute());
    lcd.print(":");
    printclock(now.second());
  }

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if(mode==2)
  {
    lcd.setCursor(0,0);
    lcd.print("Humidity:");
    printval(humidity);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    printval(temperature);
    lcd.print((char)223);
    lcd.print("C");
  }
  
  ReadVal=analogRead(GasPin);
  GasVal=100./1023.*ReadVal;

  if(mode==3)
  {
    lcd.setCursor(0,0);
    lcd.print("Gas:");
    printval(GasVal);
    lcd.print("%");
  }
  
  if(GasVal<20)
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
