int in1=3;
int a1=8;
int a2=7;
//-----------------------
int in2=11;
int b1=6;
int b2=5;

void setup() 
{ 
  //TCCR2B = TCCR2B & B11111000 | B00000001;
  //set timer 2 divisor to     1 for PWM frequency of 31372.55 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000010; 
  //set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000011;   
  //set timer 2 divisor to    32 for PWM frequency of   980.39 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000100;   
  //set timer 2 divisor to    64 for PWM frequency of   490.20 Hz (The DEFAULT)

  //TCCR2B = TCCR2B & B11111000 | B00000101;   
  //set timer 2 divisor to   128 for PWM frequency of   245.10 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000110;   
  //set timer 2 divisor to   256 for PWM frequency of   122.55 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000111;   
  //set timer 2 divisor to  1024 for PWM frequency of    30.64 Hz

  pinMode(in1, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
}

void loop()
{
  left(205,205);
  delay(100);
  stopB();
  delay(1000);
}

void backwards(int pwml, int pwmr)
{
  analogWrite(in1,pwmr);//left
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  //-----------------------
  analogWrite(in2,pwml);//right 
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
}

void forwards(int pwml, int pwmr)
{
  analogWrite(in1,pwmr);//left
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  //-----------------------
  analogWrite(in2,pwml);//right 
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
}

void left(int pwml, int pwmr)
{
  analogWrite(in1,pwmr);//RIGHT
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  //-----------------------
  analogWrite(in2,pwml);//LEFT 
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
}

void right(int pwml, int pwmr)
{
  analogWrite(in1,pwmr);//left
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  //-----------------------
  analogWrite(in2,pwml);//right 
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
}

void stop()
{
  analogWrite(in1,255);//right
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  //-----------------------
  analogWrite(in2,255);//left 
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
}

void stopB()
{
  analogWrite(in1,0);//right
  digitalWrite(a1,HIGH);
  digitalWrite(a2,HIGH);
  //-----------------------
  analogWrite(in2,0);//left 
  digitalWrite(b1,HIGH);
  digitalWrite(b2,HIGH);
}