//MOCTEAM-Micro_BIT
//rgb pins
#include <FastLED.h>
#define NUM_LEDS 2
#define DATA_PIN 10
CRGB leds[NUM_LEDS];
//TB pins
//-------right motor
#define in1 3
#define a1 8
#define a2 7
//-------left motor
#define in2 11
#define b1 6
#define b2 5
//sensors, push-button and start module
const int sr = 14;  //right
const int sm = 16;  //mid
const int sl = 15;  //left
const int sf = A3;  //line
const int pb = 2;
const int arr = 12;
//states of sensors, button and start module
int stsr;
int stsm;
int stsl;
int stsf;
int stpb;
int starr;
//indicator
const int led = 13;
//auxiliary variables
int count, x = 0;
int pos, contador = 0;
int contadorattack = 750;
int val, poslast, contador2, contador3 = 0;
int timev = 100;
int wait, wait2, wait3 = 0;
byte R_1 = 0, M_1 = 0, L_1 = 0;
byte sensores;

void setup() {
  //TCCR2B = TCCR2B & B11111000 | B00000001;
  //set timer 2 divisor to     1 for PWM frequency of 31372.55 Hz

  //TCCR2B = TCCR2B & B11111000 | B00000010;
  //set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz

  TCCR2B = TCCR2B & B11111000 | B00000011;
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
  pinMode(sr, INPUT);
  pinMode(sm, INPUT);
  pinMode(sl, INPUT);
  pinMode(sf, INPUT);
  pinMode(pb, INPUT_PULLUP);
  pinMode(arr, INPUT);
  pinMode(led, OUTPUT);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  leds[0].setRGB(0, 0, 0);
  leds[1].setRGB(0, 0, 0);
}

void loop() {
  starr = digitalRead(arr);
  while (starr == LOW) {
    starr = digitalRead(arr);
    stpb = digitalRead(pb);
    if (stpb == LOW) {
      digitalWrite(led, HIGH);
      count = count + 1;
      delay(300);
      digitalWrite(led, LOW);
    }
  }

  while (starr == HIGH) {
    for (int i = 0; i < 180000; i++) {
      starr = digitalRead(arr);
      floor_move();
      if (starr == LOW) {
        count = 0;
        x = 0;
        break;
      }
      delay(1);
    }
  }
  stopB();
  digitalWrite(led, LOW);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}

void floor_move() {
  stsf = analogRead(sf);
  if (stsf <= 60) {
    move();
  } else {
    conditions(count);
  }
}

void conditions(int countc) {
  switch (countc) {
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    case 10:
      ten();
      break;
    default:
      atacar();
      break;
  }
}

void read() {
  stsr = digitalRead(sr);
  stsm = digitalRead(sm);
  stsl = digitalRead(sl);

  if (stsr == 1) { R_1 = 0B00000001; }  //right sensor
  else {
    R_1 = 0B00000000;
  }
  if (stsm == 1) { M_1 = 0B00000010; }  //mid sensor
  else {
    M_1 = 0B00000000;
  }
  if (stsl == 1) { L_1 = 0B00000100; }  //left sensor
  else {
    L_1 = 0B00000000;
  }

  sensores = R_1 + M_1 + L_1;

  switch (sensores) {
    case 0B00000001:  //right
      pos = 100;
      leds[0] = CHSV(205, 255, 80);
      leds[1] = CHSV(205, 255, 80);
      FastLED.show();
      break;
    case 0B00000011:
      pos = 100;
      leds[0] = CHSV(125, 255, 80);
      leds[1] = CHSV(125, 255, 80);
      FastLED.show();
      break;
    case 0B00000100:  //left
      pos = 200;
      leds[0] = CHSV(55, 255, 80);
      leds[1] = CHSV(55, 255, 80);
      FastLED.show();
      break;
    case 0B00000110:
      pos = 200;
      leds[0] = CHSV(55, 255, 80);
      leds[1] = CHSV(55, 255, 80);
      FastLED.show();
      break;
    case 0B00000010:  //mid
      pos = 300;
      leds[0] = CHSV(125, 255, 80);
      leds[1] = CHSV(125, 255, 80);
      FastLED.show();
      break;
    case 0B00000111:
      pos = 300;
      leds[0] = CHSV(125, 255, 80);
      leds[1] = CHSV(125, 255, 80);
      FastLED.show();
      break;
    case 0B00000101:
      pos = 300;
      leds[0] = CHSV(125, 255, 80);
      leds[1] = CHSV(125, 255, 80);
      FastLED.show();
      break;
    default:
      pos = 0;
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      FastLED.show();
      break;
  }
  if (poslast == 100 && pos == 0) {
    pos = 100;
    contador2 = contador2 + 1;
  }
  if (poslast == 200 && pos == 0) {
    pos = 200;
    contador3 = contador3 + 1;
  }
  if (contador2 == timev) {
    pos = 0;
    contador3 = 0;
    contador2 = 0;
  }
  if (contador3 == timev) {
    pos = 0;
    contador3 = 0;
    contador2 = 0;
  }
  poslast = pos;
  return pos;
}

void atacar() {
  read();
  switch (pos) {
    case 100:
      right(100, 100);
      contador = 0;
      break;
    case 200:
      left(100, 100);
      contador = 0;
      break;
    case 300:
      contador = contador + 1;
      if (contador >= contadorattack) {
        forwards(155, 155);
      } else {
        forwards(35, 35);
      }
      break;
    default:
      forwards(50, 50);
      contador = 0;
      break;
  }
}

void one() {
  while (x < 1) {
    right(205, 205);
    delay(60);
    x = x + 1;
  }
  atacar();
}

void two() {
  while (x < 1) {
    left(205, 205);
    delay(55);
    x = x + 1;
  }
  atacar();
}

void three() {
  while (x < 1) {
    left(205, 205);
    delay(102);
    x = x + 1;
  }
  atacar();
}

void four() {
  while (x < 1) {
    for (int h = 0; h <= 255; h++) {
      forwards(h, h);
      delay(2);
      if (h == 254) { break; }
    }
    x = x + 1;
  }
  atacar();
}

void five() {
  while (x < 1) {
    right(205, 205);
    delay(30);
    forwards(205, 205);
    delay(200);
    left(205, 205);
    delay(70);
    stopB();
    delay(20);
    x = x + 1;
  }
  atacar();
}

void six() {
  while (x < 1) {
    left(205, 205);
    delay(30);
    forwards(205, 205);
    delay(200);
    right(205, 205);
    delay(70);
    stopB();
    delay(20);
    x = x + 1;
  }
  atacar();
}

void seven() {
  while (x < 1) {
    right(205, 205);
    delay(30);
    forwards(205, 205);
    delay(200);
    left(205, 205);
    delay(90);
    forwards(205, 205);
    delay(150);
    stopB();
    delay(20);
    x = x + 1;
  }
  atacar();
}

void eight() {
  while (x < 1) {
    left(205, 205);
    delay(30);
    forwards(205, 205);
    delay(200);
    right(205, 205);
    delay(85);
    forwards(205, 205);
    delay(100);
    stopB();
    delay(50);
    x = x + 1;
  }
  atacar();
}

void nine() {
  while (x < 1) {
    forwards(255,248);
    delay(200);
    x = x + 1;
  }
  atacar();
}

void ten() {
  while (x < 1) {
    forwards(248,255);
    delay(200);
    x = x + 1;
  }
  atacar();
}
//---------------------------------------

void move() {
  backwards(205, 205);  //205,215
  delay(100);
  right(205, 205);
  delay(100);
}

void backwards(int pwml, int pwmr) {
  analogWrite(in1, pwmr);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  //-----------------------
  analogWrite(in2, pwml);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
}

void forwards(int pwml, int pwmr) {
  analogWrite(in1, pwmr);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  //-----------------------
  analogWrite(in2, pwml);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void right(int pwml, int pwmr) {
  analogWrite(in1, pwmr);  //RIGHT
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  //-----------------------
  analogWrite(in2, pwml);  //LEFT
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
}

void left(int pwml, int pwmr) {
  analogWrite(in1, pwmr);  //left
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  //-----------------------
  analogWrite(in2, pwml);  //right
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);
}

void stop() {
  analogWrite(in1, 255);  //right
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  //-----------------------
  analogWrite(in2, 255);  //left
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
}

void stopB() {
  analogWrite(in1, 0);  //right
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  //-----------------------
  analogWrite(in2, 0);  //left
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
}