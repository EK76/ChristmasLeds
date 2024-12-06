# ChristmasLeds
Christmas Leds is Arduino project, whose RGB leds can be uses for example as a Christmas decorative lighting. which the project name refers to.
The project also consist of a pushbutton and movedetection sensor 
Pushbutton's purpose is to switch between two diiferent led funtions, which are
- Random blinking leds
- Running leds
  
Movedetection sensor task is to sense when a person comes to certain and give a signal to DFMini player to play a MP3 song
of your choosing. The code is written by c++ programming language with Arduino IDE complitator. You can find more info about Arduino IDE from this link
https://www.arduino.cc/en/software

This project consist of
- Arduino Mega 2560
- DFMini player
- PAM8403 Audio amplifire
- 2 3watt speakers
- Push button
- 9 RGB LEDs
- 9 330 Ohm resistors that are connected to RGB leds.
- 1k Ohm resistor
- Jumpwires

## Schematics
![image](https://github.com/user-attachments/assets/c6226249-231a-4ef6-a6ad-85058707638c)

- RGG LEds are connected to the pins between 22 and 48.
- Push button is connected to pin 18.
- Movedetection sensor is connected to pin 19.
- Arduino Mega's pin 10 is connected to DFMini player according the yellow wire.
- Arduino Mega's pin 11 is connected to DFMini player according the green wire.
- Connect DFMini player to PAM8403 Audio amplifire according the blue wire.
