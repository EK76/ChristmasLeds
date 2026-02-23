include <SoftwareSerial.h>
int redLeds[] = {3, 5, 6, 9, 10}; 
int period=3000;
int period2=20;
int period3=1000;
int stopTimer = 0;
int stopTimer2 = 0;
int stopTimer3 = 0;
int counter=0;
int ledCounter=1;
int changeValue = 1;
long randomNumber, choiceValue;
bool checkOnce = false;
unsigned long time_now = 0;
unsigned long time_now2 = 0;
unsigned long time_now3 = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), choice, RISING);
}

void delayTime()
{ 
   time_now = millis();
   while(millis() - time_now < period){
     if (stopTimer == 1)
     {
          period = 0;
          stopTimer = 0;
          break;
      }   
   } 
}

void delayTime2()
{ 
   time_now2 = millis();
   while(millis() - time_now2 < period2){
     if (stopTimer2 == 1)
     {
          period2 = 0;
          stopTimer2 = 0;
          break;
      }   
   } 
}

void delayTime3()
{ 
   time_now3 = millis();
   while(millis() - time_now3 < period3){
     if (stopTimer3 == 1)
     {
          period3 = 0;
          stopTimer3 = 0;
          break;
      }   
   } 
}

void loop() 
{
  if (checkOnce == true)
  {
    checkOnce = false;
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(2, INPUT_PULLUP);
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
  Serial.println(changeValue);
}

void choice()
{
  counter++;
  switch(counter)
  {
    case 1:
      changeValue=1;
      break;

    case 2:
      changeValue=2;
      checkOnce = true;   
      break;
    
    case 3:
      changeValue=3;
      break;

    case 4:
      counter=0;
      break;
  }    
}
