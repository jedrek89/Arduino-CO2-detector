#include <LiquidCrystal.h>
//A1 - MQ5 Czujnik LPG, gazu ziemnego i gazu węglowego
//A2 - Czujnik tlenku węgla MQ-7
//D11 - Buzzer

int MQ5=A1;
int MQ7=A2;
float MQ5_value = 0;
float MQ7_value = 0;
int BUZZER = 10;
// Ustawienie limitów dla czujników
int GAS_LIM = 345;
int CO2_LIM = 555;

LiquidCrystal lcd (12, 11, 3, 4, 5, 6);

void setup()
{
  lcd.begin (16, 2);
  lcd.clear();
  //pinMode(MQ5,INPUT);
  //pinMode(MQ7,INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  float MQ5_value = analogRead(A1);
  float MQ7_value = analogRead(A2);
  lcd.setCursor(0,0);
  lcd.print("GAZ:");
  lcd.setCursor(5,0);
  lcd.print(MQ5_value);
  lcd.setCursor(12,0);
  // Warunek wyświetlania
  //lcd.print("OK");
  if (MQ5_value <= GAS_LIM)
  {
    lcd.print("OK   ");
    lcd.setCursor(12,0);
  }
  else
  {
    lcd.print("ALM");
    lcd.setCursor(12,0);
  }
    lcd.setCursor(0,1);
    lcd.print("CO2:");
    lcd.setCursor(5,1);
    lcd.print(MQ7_value);
    lcd.setCursor(12,1);
  if (MQ7_value <= CO2_LIM)
  {
    lcd.print("OK  ");
    lcd.setCursor(12,0);
  }
  else
  {
    lcd.print("ALM");
    lcd.setCursor(12,0);
  }

// BUZZER
if (MQ5_value <= GAS_LIM && MQ7_value <= CO2_LIM )
{
  digitalWrite(BUZZER, LOW);
}
else
{
    digitalWrite(BUZZER, HIGH);
}
  delay(500);
}
