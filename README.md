# Christmas Leds
Christmas Leds is a Arduino project, whose leds can be used for example as a Christmas decorative lighting, which the project's name refers to.
The code is written in C++ programming language with the help of Arduino IDE complitator. You can find more info about Arduino IDE from this link.
https://www.arduino.cc/en/software.

This project consist of
- Arduino Uno (in my case) or any other Arduino board of your choosing.
- 1 pcs push buttons
- 5 pcs red leds (in my case) or any other color of your choosing for the decorative lighting.
- 1 psc RGB led (indicating status of the decorative lighting).
- 7 pcs 330 Ohm resistors that are connected to leds.

#### By modifing the code you add more "decorative" leds to this project.

The pushbutton's purpose is to switch between three diiferent led funtions, which are
- Running leds.
- Fadings leds.
- Random blinking leds.

## Schematics
<img width="580" height="350" alt="image" src="https://github.com/user-attachments/assets/934402df-6194-442b-a7eb-08290e66a82a" />

- Leds are connected to the pins 5,6,9,10 and 11.
- Rgb led are connected to pin 8 and 12.
- Push button is connected to pin 2 (workings as an interrupt).

An Arduino interrupt is a hardware mechanism that pauses your main program's execution to immediately run a specific, high-priority chunk of code. 
It ensures your board reacts instantly to events (like a button press or sensor trigger) without the lag or missed signals associated with constant polling.
