#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


int randomNumbers[] = {1700, 2000, 2300, 2500, 2800, 3000};
int blueLeds[] = {22, 25, 28};
int redLeds[] = {23, 26, 29};
int greenLeds[] = {24, 27, 30};

  //Create the UART connection to the module

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

  pinMode(blueLed1, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  
  pinMode(blueLed2, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);

  pinMode(blueLed3, OUTPUT);
  pinMode(redLed3, OUTPUT);
  pinMode(greenLed3, OUTPUT);

  softwareSerial.begin(9600);
  myPlayer.begin(softwareSerial); 
  myPlayer.volume(10);
    
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
    for (int i = 0; i < 3; i++){
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

            Serial.print("Delay: ");
      Serial.println(randomNumbers[randomNumber]);

    choiceValue = random(1,7);
   

     Serial.print("Random: ");
     Serial.println(randomNumber2);

    switch(choiceValue)
    {
      case 1:
     // Blue
      randomNumber2 = random(1,4);
        digitalWrite(blueLeds[randomNumber2], HIGH);
        digitalWrite(redLeds[randomNumber2], LOW);
        digitalWrite(greenLeds[randomNumber2], LOW);

      case 2: 
    // Red
     randomNumber2 = random(1,4);
       digitalWrite(blueLeds[randomNumber2], LOW);
       digitalWrite(redLeds[randomNumber2], HIGH);
       digitalWrite(greenLeds[randomNumber2], LOW);   
   
  //Green
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
    Serial.print("Choichvalue: ");
     Serial.println(choiceValue);
        Serial.print("Blue: ");
      Serial.println(blueLeds[randomNumber2]);
     Serial.print("Red: ");
      Serial.println(redLeds[randomNumber2]);
         Serial.print("Green: ");
      Serial.println(greenLeds[randomNumber2]);
     delayTime();
  }
  else
  {
     randomNumber = random(7);
     switch(randomNumber)
     {
       case 1:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], LOW);
       }
       break;

       case 2:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], LOW);
       }
       break;

       case 3:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 

       case 4:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], LOW);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 

       case 5:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], LOW);
        digitalWrite(greenLeds[i], HIGH);
       }
       break; 
      
      case 6:
       for (int i = 0; i < 3; i++)
       {
        digitalWrite(blueLeds[i], HIGH);
        digitalWrite(redLeds[i], HIGH);
        digitalWrite(greenLeds[i], LOW);
          Serial.println(greenLeds[i]);
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
