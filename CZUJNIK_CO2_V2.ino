//A1 - MQ5 Czujnik LPG, gazu ziemnego i gazu węglowego
//A2 - Czujnik tlenku węgla MQ-7
int MQ5=A1;
int MQ7=A2;
int MQ5_value = 0;
int MQ7_value = 0;

void setup()
{
  //pinMode(MQ5,INPUT);
  //pinMode(MQ7,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int MQ5_value = analogRead(A1);
  int MQ7_value = analogRead(A2);

  {
    Serial.println(MQ5_value);
    Serial.println(MQ7_value);
  }
  delay(500);
}
