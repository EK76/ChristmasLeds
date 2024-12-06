#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


int randomNumbers[] = {1700, 2000, 2300, 2500, 2800, 3000};
int blueLeds[] = {22, 25, 28, 49, 34, 37, 40, 43, 46};
int redLeds[] = {23, 26, 29, 32, 35, 38, 41, 50, 47};
int greenLeds[] = {24, 27, 30, 33, 36, 39, 42, 45, 48};

int blueLed[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int redLed[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int greenLed[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

SoftwareSerial softwareSerial(10,11);
DFRobotDFPlayerMini myPlayer;

int moveDetection = 19; 
int selection = 18;

int blueLed1 = 22;
int redLed1 = 23;
int greenLed1 = 24;

int blueLed2 = 25;
int redLed2 = 26;
int greenLed2 = 27;

int blueLed3 = 28;
int redLed3 = 29;
int greenLed3 = 30;

int blueLed4 = 49;
int redLed4 = 32;
int greenLed4 = 33;

int blueLed5 = 34;
int redLed5 = 35;
int greenLed5 = 36;

int blueLed6 = 37;
int redLed6 = 38;
int greenLed6 = 39;

int blueLed7 = 40;
int redLed7 = 41;
int greenLed7 = 42;

int blueLed8 = 43;
int redLed8 = 50;
int greenLed8 = 45;

int blueLed9 = 46;
int redLed9 = 47;
int greenLed9 = 48;

int setPeriod = 2000;
int period;
int stopTimer = 0;
bool beginOver = true;
bool checkOnce;
bool detection = false;
int changeValue = 0;
int counter = 0;

unsigned long time_now = 0;
long randomNumber, randomNumber2, choiceValue;

void setup() 
{
  Serial.begin(9600);
  softwareSerial.begin(9600);
  pinMode(moveDetection,INPUT_PULLUP);
  pinMode(selection,INPUT_PULLUP);

  pinMode(blueLed1, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  
  pinMode(blueLed2, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);

  pinMode(blueLed3, OUTPUT);
  pinMode(redLed3, OUTPUT);
  pinMode(greenLed3, OUTPUT);

  pinMode(blueLed4, OUTPUT);
  pinMode(redLed4, OUTPUT);
  pinMode(greenLed4, OUTPUT);

  pinMode(blueLed5, OUTPUT);
  pinMode(redLed5, OUTPUT);
  pinMode(greenLed5, OUTPUT);

  pinMode(blueLed6, OUTPUT);
  pinMode(redLed6, OUTPUT);
  pinMode(greenLed6, OUTPUT);

  pinMode(blueLed7, OUTPUT);
  pinMode(redLed7, OUTPUT);
  pinMode(greenLed7, OUTPUT);

  pinMode(blueLed8, OUTPUT);
  pinMode(redLed8, OUTPUT);
  pinMode(greenLed8, OUTPUT);

  pinMode(blueLed9, OUTPUT);
  pinMode(redLed9, OUTPUT);
  pinMode(greenLed9, OUTPUT); 

  softwareSerial.begin(9600);
  myPlayer.begin(softwareSerial); 
  myPlayer.volume(26);
    
  attachInterrupt(digitalPinToInterrupt(moveDetection), interuptPin, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(selection), interuptPin2, RISING); 
  randomSeed(analogRead(A0));  
}

void delayTime()
{ 
   time_now = millis();
   while(millis() - time_now < period){
     if (stopTimer == 1)
     {
          period = 0;
          stopTimer = 0;
          beginOver = true;
          break;
      }   
   } 
}

void loop() {

  if (beginOver == true)
  {
    beginOver = false;
    // Blue
    for (int i = 0; i < 9; i++){
      digitalWrite(blueLeds[i], HIGH);
      digitalWrite(redLeds[i],LOW);
      digitalWrite(greenLeds[i],LOW);
    }   
    delay(1500);  
  }

  if (changeValue == 0)
  {
   randomNumber = random(1,7);
    period = randomNumbers[randomNumber];
    choiceValue = random(1,7);
    switch(choiceValue)
    {
      case 1:
      randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], HIGH);
        digitalWrite(redLeds[randomNumber2], LOW);
        digitalWrite(greenLeds[randomNumber2], LOW);

      case 2: 
     randomNumber2 = random(1,4);
       digitalWrite(blueLeds[randomNumber2], LOW);
       digitalWrite(redLeds[randomNumber2], HIGH);
       digitalWrite(greenLeds[randomNumber2], LOW);    

      case 3:
       randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], LOW);
        digitalWrite(redLeds[randomNumber2], LOW);  
        digitalWrite(greenLeds[randomNumber2], HIGH);
    
      case 4:
      randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], HIGH);
        digitalWrite(redLeds[randomNumber2], LOW);  
        digitalWrite(greenLeds[randomNumber2], HIGH);

      case 5:
      randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], LOW);
        digitalWrite(redLeds[randomNumber2], HIGH);  
        digitalWrite(greenLeds[randomNumber2], HIGH);
      
      case 6:
      randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], HIGH);
        digitalWrite(redLeds[randomNumber2], HIGH);  
        digitalWrite(greenLeds[randomNumber2], LOW);
    }
     delayTime();
  }
  else
  {
     randomNumber = random(7);
     switch(randomNumber)
     {
       case 1:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], LOW);
       }
       break;

       case 2:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], LOW);
       }
       break;

       case 3:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 

       case 4:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 

       case 5:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 
      
      case 6:
       for (int i = 0; i < 9; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], LOW);
       }
       break; 
     }
   
     delayTime();
  }

  if (detection == true)
  {
    digitalWrite(22, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(24, LOW);
    
    digitalWrite(25, LOW);
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
    
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
    digitalWrite(30, LOW);
    
    digitalWrite(49, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
    
    digitalWrite(34, LOW);
    digitalWrite(35, HIGH);
    digitalWrite(36, LOW);

    digitalWrite(37, LOW);
    digitalWrite(38, HIGH);
    digitalWrite(39, LOW);

    digitalWrite(40, LOW);
    digitalWrite(41, HIGH);
    digitalWrite(42, LOW);

    digitalWrite(43, LOW);
    digitalWrite(50, HIGH);
    digitalWrite(45, LOW);

    digitalWrite(46, LOW);
    digitalWrite(47, HIGH);
    digitalWrite(48, LOW);

    Serial.println("Test1");
    myPlayer.play(1);
    delay(35000);
    detection= false;
  }
}  

void interuptPin()
{
  detection = true;
}

void interuptPin2()
{  
   beginOver = true;
   counter++;
   if (counter == 1)
   {
     changeValue = 1;
   }

   if (counter == 2)
   {
     changeValue = 0;
     counter=0;
   }
}
