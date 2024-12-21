const int SI1 = 15;
int stsi1;

const int Led = 13;

void setup()
{
  pinMode(SI1,INPUT);
  pinMode(Led,OUTPUT);
}

void loop()
{
  stsi1 = digitalRead(SI1);
  if(stsi1 == HIGH)
  {
    digitalWrite(Led,HIGH);
  }
  else{digitalWrite(Led,LOW);}
}
