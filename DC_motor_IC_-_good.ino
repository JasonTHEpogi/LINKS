/*
 Controlling the direction of a dc motor using the IC chip - CW or CCW
 
 The IC chip is a component that allows us to choose which direction the DC motor to rotate(CW or CCW).
 If we want the direction to be counter-clockwise(CCW), simply set the pin to HIGH where the IN1 on the IC chip is attached on the board, 
 and the pin where the IN2 is connected on the Arduino UNO board to LOW. By doing this, the direction of the motor will be CCW.
 However, if the desired direction is clockwise(CW), then make sure that IN1 is set to LOW and IN2 is set to HIGH.
 */
 
int Speed = 5;  // attach the enable pin(pin1) to any PWM pins on the arduino UNO to enable the speedpin of the IC chip.
int Direction1 = 7;  // attach the IN1 pin(pin2) to any digital pins on the arduino; this pin is one of the designated pin for the direction of the motor.
int Direction2 = 8;  // attach the IN2 pin(pin7) to any digital pins on the arduino; this pin is one of the designated pin for the direction of the motor.

int speedvalue = 255;  // use the maximum analog value to turn on the motor at the max speed.
                       // NOTE: the speed of the motor should be set around 200 analog values for the motor to run smoothly. 
  // put your setup code here, to run once:
void setup()
{
pinMode(Speed, OUTPUT);  // set the variable 'Speed' as an ANALOG OUTPUT.
pinMode(Direction1, OUTPUT);  // set the variable 'Direction1' as a DIGITAL OUTPUT.
pinMode(Direction2, OUTPUT);  // set the variable 'Direction2' as a DIGITAL OUTPUT.
}

void loop() {
  // put your main code here, to run repeatedly:
 
analogWrite(Speed, speedvalue);  // making the motor run to the desired speed based on what is entered in the variable "speedvalue".
                                 // the speed can be controlled by simply altering the analog value.

//CCW Section:
//this section is to run the motor counter-clockwise(CCW). Multi-comment this section to enable the code for the CW section.                                
digitalWrite(Direction1, HIGH);  // when direction1 is set to HIGH which is connected to pin2 or the IN1 pin on the IC chip, and
                                 // while Direction2 or pin7 on the IC chip is LOW, the motor will be rotating counter clockwise (CCW).
digitalWrite(Direction2, LOW);   // Direction2 is set to LOW.

//CW Section:
//this section is to run the motor clockwise(CW). Delete the multi-comment in this section and then multi-comment the CCW section.
/*digitalWrite(Direction1, LOW);  // Set Direction1 to LOW.
  digitalWrite(Direction2, HIGH); // when Direction2 is HIGH and Direction1 is LOW, the direction of the motor will be ClockWise(CW). 
*/
}
