#include <SoftwareSerial.h>
int redLeds[] = {11, 5, 6, 9, 10}; 
int period=5000;
int period2=20;
int period3=1500;
volatile int counter = 0;
volatile int counter2 = 0;
volatile int changeValue = 1;
int ledCounter=1;
long randomNumber;
bool checkOnce = false;
unsigned long time_now = 0;
unsigned long time_now2 = 0;
unsigned long time_now3 = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  delay(500);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), choiceValue, RISING);
  attachInterrupt(digitalPinToInterrupt(3), delayValue, RISING);
  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
}

void delayTime()
{ 
   time_now = millis();
   while(millis() - time_now < period){}
}

void delayTime2()
{ 
   time_now2 = millis();
   while(millis() - time_now2 < period2){} 
}

void delayTime3()
{ 
   time_now3 = millis();
   while(millis() - time_now3 < period3){} 
}

void loop() 
{
  if (checkOnce == true)
  {
    checkOnce = false;

    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    Serial.println("TRUE");
  }
  switch(changeValue)
  {
    case 1:    
      randomNumber = random(6);
      switch(randomNumber)
      {
        case 1:
          digitalWrite(redLeds[0], LOW);
          digitalWrite(redLeds[1], HIGH);
          digitalWrite(redLeds[2], HIGH);
          digitalWrite(redLeds[3], HIGH);
          digitalWrite(redLeds[4], HIGH);
          Serial.println("Random 1");
          break;
        case 2:
          digitalWrite(redLeds[0], HIGH);
          digitalWrite(redLeds[1], LOW);
          digitalWrite(redLeds[2], HIGH);
          digitalWrite(redLeds[3], HIGH);
          digitalWrite(redLeds[4], HIGH);
          Serial.println("Random 2");
          break;
        case 3:
          digitalWrite(redLeds[0], HIGH);
          digitalWrite(redLeds[1], HIGH);
          digitalWrite(redLeds[2], LOW);
          digitalWrite(redLeds[3], HIGH);
          digitalWrite(redLeds[4], HIGH);
          Serial.println("Random 3");
          break;
        case 4:
          digitalWrite(redLeds[0], HIGH);
          digitalWrite(redLeds[1], HIGH);
          digitalWrite(redLeds[2], HIGH);
          digitalWrite(redLeds[3], LOW);
          digitalWrite(redLeds[4], HIGH);     
          Serial.println("Random 4");
          break;
        case 5:
          digitalWrite(redLeds[0], HIGH);
          digitalWrite(redLeds[1], HIGH);
          digitalWrite(redLeds[2], HIGH);
          digitalWrite(redLeds[3], HIGH);
          digitalWrite(redLeds[4], LOW);
          Serial.println("Random 5");
          break;  
      }
      delayTime();
      break;
    case 2:
      for (int ledFade = 255; ledFade >= 0; ledFade--)
      {
        analogWrite(redLeds[0], ledFade);
        analogWrite(redLeds[1], ledFade);
        analogWrite(redLeds[2], ledFade);
        analogWrite(redLeds[3], ledFade);
        analogWrite(redLeds[4], ledFade);
        delayTime2();
      }
      delayTime();
      for (int ledFade = 0; ledFade <= 255; ledFade++) 
      {
        analogWrite(redLeds[0], ledFade);
        analogWrite(redLeds[1], ledFade);
        analogWrite(redLeds[2], ledFade);
        analogWrite(redLeds[3], ledFade);
        analogWrite(redLeds[4], ledFade);
        delayTime2();
      }
      delayTime();   
      break;

    case 3:
      switch(ledCounter)
      {
        case 1:
          digitalWrite(redLeds[0], LOW);
          digitalWrite(redLeds[1], LOW);
          digitalWrite(redLeds[2], LOW);
          digitalWrite(redLeds[3], LOW);
          digitalWrite(redLeds[4], LOW);
          delayTime3(); 
          break;
        case 2:
          digitalWrite(redLeds[0], HIGH);
          delayTime(); 
          break;
        case 3:
          digitalWrite(redLeds[1], HIGH);
          delayTime(); 
          break;
        case 4:
          digitalWrite(redLeds[2], HIGH);
          delayTime(); 
          break;
        case 5:
          digitalWrite(redLeds[3], HIGH);
          delayTime(); 
          break;
        case 6:
          digitalWrite(redLeds[4], HIGH);
          delayTime(); 
          break;  
        case 7:
          ledCounter=0;
          delayTime(); 
          break;  
      }
      ledCounter++;
      break;     
  }
  Serial.println(period);
  Serial.println(changeValue);
}

void choiceValue()
{
  counter++;
  switch(counter)
  {
    case 1:
      changeValue=1;
      digitalWrite(8, HIGH);
     digitalWrite(12, LOW);
      break;

    case 2:
      changeValue=2;
      checkOnce = true;   
      digitalWrite(8, LOW);
      digitalWrite(12, HIGH);
      break;
    
    case 3:
      changeValue=3;
      counter=0;
      digitalWrite(8, HIGH);
      digitalWrite(12, HIGH;
      break;
  }  
  return;
}

 void delayValue()
{
  counter2++;
  switch(counter2)
  {
    case 1:
      period=1500;
      digitalWrite(4, HIGH);
      break;

    case 2:
      period=5000;
      counter2=0;
      digitalWrite(4, LOW);
      break;
  }
}
