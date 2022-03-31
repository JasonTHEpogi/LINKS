/*
Using a joystick to control a servo motor. The joystick is programmed to control the position of the servo motor.
The servo motor is powered by a separate battery to prevent the arduino from overheating 
whereas the joystick is attached directly to the arduino board. This way we won't burn our Arduino.
*/

#include <Servo.h>  //include this library to begin.

Servo myservo;  // create servo object to control a servo

int servopin = 11; //declaring a variable and assigning it to pin 11 on the Arduino board.

int Xpin = A0;  // declaring a variable and assigning it to one of the analog pin.
int Xval = 0;   //declaring a variable to store the value coming from the analog pin. 

void setup() {
  myservo.attach(servopin);  // configuring the servo motor and attaching it to pin 11.
}

void loop() {
  Xval = analogRead(Xpin);        // using the analogRead command to read the value of the Xpin; one of the analog pin used (value between 0 and 1023).
  Xval = map(Xval, 0, 1023, 0, 180);   //using the map function to scale the value coming from that analog pin (value between 0 degree and 180 degree angles).
  myservo.write(Xval);        // using the myservo.write command to set the position of the servo motor based on the scaled value.
}
