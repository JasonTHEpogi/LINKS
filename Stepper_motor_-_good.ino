/*
This program will demonstrate how to control the stepper motor using a joystick.
The motor is energized and rotates clockwise  as long as the joystick is being touched or turned in any direction.
 */

#include <Stepper.h>; //include this library.

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int Xpin = A0;  //Xpin to be assigned to A0, analog pin.
int Ypin = A1;  //Ypin to be assigned to A1, analog pin.
int Xvalue = 0;  //declaring a variable to store the reading coming from A0.
int Yvalue = 0;  //declaring a variable to store the reading coming from A1.

void setup() {
  // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);  //serial communication at 9600 baudrate.
}

void loop() {
Xvalue = analogRead(Xpin);  //read the value from this analog input and store it in this variable.
Yvalue = analogRead(Ypin);  //read the value from this analog input and store it in this variable.


if (Xvalue == 1023 || Yvalue == 1023 )  //if either one of these two condition inside the parenthesis is TRUE, the code below will be executed.  
{
  myStepper.step(stepsPerRevolution);  //the motor is energized.
}

else if (Xvalue == 0 || Yvalue == 0 )  //this statement is only TRUE if the condition is met.
{
  myStepper.step(stepsPerRevolution);  //the motor is energized.
}
}
