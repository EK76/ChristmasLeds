# Christmas Leds
Christmas Leds is a Arduino project, whose leds can be used for example as a Christmas decorative lighting, which the project's name refers to.
I have also include DFPlayer Mini component for playing a christmas song as mp3 format when a pushbutton is pressed. Optionally you can leave out the DFPlayer Mini from this project and only use 
the leds. The code is written in C++ programming language with the help of Arduino IDE complitator. You can find more info about Arduino IDE from this link.
https://www.arduino.cc/en/software.

## List over the hardware for this project.
- Arduino Uno R4 WiFi (in my case) or any other compatible Arduino board of your choosing.
- 2 pcs push buttons
- 5 pcs red leds (in my case) or any other color of your choosing for the decorative lighting.
- 1 pcs rgb led (indicating status of the decorative lighting).
- 7 pcs 330 ohm resistors that are connected to leds.
- 1 pcs DFPlayer mini
- 1 psc small speaker

#### By modifing the code you add more "decorative" leds to this project.

The first pushbutton's purpose is to switch between three diiferent led funtions, which are
- Running leds.
- Fadings leds.
- Random blinking leds.

The second pushbutton's purpose is to play a christmas song of your choosing as mp3 format when it is pressed.

### DFPlayer Mini
 IT is a small, inexpensive MP3 audio playback module widely used in DIY electronics and robotics. It allows you to easily add sound, voice alerts, 
 or music to projects by reading files directly from a microSD card.
 
<img width="300" height="150" alt="dfplayer" src="https://github.com/user-attachments/assets/d3b35659-5685-4677-afb7-0c81bbcc8e85" />

A small speaker are connected to DFPlayer mini's SPK + and SPK pins. You can use the Arduino Uno device's 5V power pin and one of the GND pins to
power up DFPlayer Mini or use an external power supply with 5V DC.

### Speaker
<img width="150" height="100" alt="image" src="https://github.com/user-attachments/assets/82f566da-4efb-4694-9698-5e1e60acc259" />

The DFPlayer Mini features an onboard 3W mono amplifier, meaning it can directly drive a small speaker without needing an extra amplifier board. 
The best alternative is a passive, standard 2-3 W, and 4 ohm or 8 ohm speaker (either a small paper-cone speaker or a miniature enclosed speaker).

## Schematics
<img width="580" height="350" alt="image" src="https://github.com/user-attachments/assets/934402df-6194-442b-a7eb-08290e66a82a" />

- Leds are connected to the pins 5,6,9,10 and 11.
- Rgb led is connected to pin 8 and 12.
- Push buttons are connected to pin 2 and pin 3 (workings as interrupts).
- DFPlayer TX is conected to Arduino RX (pin 0).
- DFPlayer RX is conected to Arduino TX (pin 1).

An Arduino interrupt is a hardware mechanism that pauses your main program's execution to immediately run a specific, high-priority chunk of code. 
It ensures your board reacts instantly to events (like a button press or sensor trigger) without the lag or missed signals associated with constant polling.
