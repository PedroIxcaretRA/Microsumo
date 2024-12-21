const int SI1 = A6;
int stsi1;

const int Led = 13;

void setup()
{
  pinMode(SI1,INPUT);
  pinMode(Led,OUTPUT);
}

void loop()
{
  stsi1 = analogRead(SI1);
  if(stsi1 <= 60)
  {
    digitalWrite(Led,HIGH);
  }
  else{digitalWrite(Led,LOW);}
}
