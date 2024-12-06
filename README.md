# Christmas Leds
Christmas Leds is a Arduino project, whose RGB leds can be uses for example as a Christmas decorative lighting, which the project's name refers to.
It also conist of small speaker which can play MP3 songs.

The code is written in C++ programming language with the Arduino IDE complitator. You can find more info about Arduino IDE from this link.
https://www.arduino.cc/en/software

This project consist of
- Arduino Mega 2560
- DFMini player
- PAM8403 Audio amplifire
- 2 pcs 3watt speakers
- Push button
- 9 pcs RGB LEDs
- 9 pcs 330 Ohm resistors that are connected to RGB leds.
- 1k Ohm resistor
- Jumpwires
  
Pushbutton's purpose is to switch between two diiferent led funtions, which are
- Random blinking leds
- Running leds
  
Movedetection sensor's task is to sense when a person approaching to a certain distance and then send a signal to DFMini player to play a MP3 song
of your choosing. 

## Schematics
![image](https://github.com/user-attachments/assets/c6226249-231a-4ef6-a6ad-85058707638c)

- RGG LEds are connected to the pins between 22 and 48.
- Push button is connected to pin 18.
- Movedetection sensor is connected to pin 19.
- Arduino Mega's pin 10 is connected to DFMini player according the yellow wire.
- Arduino Mega's pin 11 is connected to DFMini player according the green wire.
- Connect DFMini player is connected to PAM8403 Audio amplifire according the blue wire.
