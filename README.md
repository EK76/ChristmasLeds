# Christmas Leds
Christmas Leds is a Arduino project, whose leds can be used for example as a Christmas decorative lighting, which the project's name refers to.
The code is written in C++ programming language with the Arduino IDE complitator. You can find more info about Arduino IDE from this link.
https://www.arduino.cc/en/software

This project consist of
- Arduino Uno (in my case) or any other Arduino board of your choosing.
- 2 pcs push buttons
- 5 pcs red leds (in my case) or any other color of your choosing for the decorative lighting.
- 1 pcs orange led (indicating status of the delay value).
- 1 psc RGB led (indicating status of the decorative lighting).
- 7 pcs 330 Ohm resistors that are connected to leds.
- Jumpwires
  
The first pushbutton's purpose is to switch between three diiferent led funtions, which are
- Running leds (RGB led is blue).
- Fadings leds (RGB led is ref).
- Random blinking leds (RGB led is purple).

And second pushbutton's purpose is to switch between delay values, which are.
- 1.5 second
- 5 seconds
  
In my case the delay values are 1.5 second and 5 seconds. Byt you can in the code
choose your own values. When orange led is on, it means the delay value is 1.5 seconds
and when led is in off mode the delay value is 5 seconds.

## Schematics
<img width="580" height="350" alt="image" src="https://github.com/user-attachments/assets/934402df-6194-442b-a7eb-08290e66a82a" />

- Leds are connected to the pins 4,5,6,8,9,10,11 and 12.
- Push button is connected to pin 2,3 (workings as interrupts).
