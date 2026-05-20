#include <SoftwareSerial.h>
int redLeds[] = {5, 6, 9, 10, 11}; 
int interval=2000;
int interval2=20;
volatile int counter = 0;
volatile int counter2 = 0;
volatile int changeValue = 1;
int ledCounter=1;
unsigned long previousDelay = 0; 
long randomNumber;
bool checkOnce = false;
unsigned long currentDelay;
unsigned long lastDebouncetime = 0;
const unsigned long debounceDelay = 250;
unsigned long timeNow= 0;
unsigned long timeNow2 = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  delay(500);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), choiceValue, CHANGE);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
}

void delayTime()
{ 
   timeNow = millis();
   while(millis() - timeNow < interval2){} 
}

void loop() 
{
  currentDelay = millis();
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
      if (currentDelay - previousDelay >= interval) 
      {
        previousDelay = currentDelay;  
        randomNumber = random(6);
      }  
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
      break;
    case 2:
      for (int ledFade = 255; ledFade >= 0; ledFade--)
      {
        analogWrite(redLeds[0], ledFade);
        analogWrite(redLeds[1], ledFade);
        analogWrite(redLeds[2], ledFade);
        analogWrite(redLeds[3], ledFade);
        analogWrite(redLeds[4], ledFade);
        delayTime();
      }
      if (currentDelay - previousDelay >= interval) 
      { 
        previousDelay = currentDelay;  
        for (int ledFade = 0; ledFade <= 255; ledFade++) 
        {
          analogWrite(redLeds[0], ledFade);
          analogWrite(redLeds[1], ledFade);
          analogWrite(redLeds[2], ledFade);
          analogWrite(redLeds[3], ledFade);
          analogWrite(redLeds[4], ledFade);
          delayTime();
        }
      }
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
          break;
        case 2:
          digitalWrite(redLeds[0], HIGH);
          break;
        case 3:
          digitalWrite(redLeds[1], HIGH);
          break;
        case 4:
          digitalWrite(redLeds[2], HIGH);
          break;
        case 5:
          digitalWrite(redLeds[3], HIGH);
          break;
        case 6:
          digitalWrite(redLeds[4], HIGH);
          break;  
        case 7:
          ledCounter=0;
          break;  
      }

      if (currentDelay - previousDelay >= interval) 
      { 
        previousDelay = currentDelay;  
        ledCounter++;
      }  
      break;     
  }
  Serial.println(interval);
  Serial.println(changeValue);
}

void choiceValue()
{
  if (millis() - lastDebouncetime > debounceDelay) 
  {
    lastDebouncetime = millis();
    previousDelay = 0; 
    counter++;
    switch(counter)
    {
      case 1:
        changeValue=2;
        digitalWrite(8, HIGH);
        digitalWrite(12, LOW);
        break;

      case 2:
        changeValue=3;
        digitalWrite(8, HIGH);
        digitalWrite(12, HIGH);
        checkOnce = true;   
        break;
    
      case 3:
        changeValue=1;

        digitalWrite(8, LOW);
        digitalWrite(12, HIGH);
        counter=0;
        break;
    }  
  }
}
