/*DC motor - ON/OFF using a relay
The DC motor is connected to a relay and this relay was programmed to turn ON or OFF the motor.
When the relay is energized, the motor will turn ON, and when it is denergized, the motor will turn OFF.
*/

int pin = 8; //declaring a variable to be used as an output.

void setup() {
  // put your setup code here, to run once:
pinMode(pin, OUTPUT);  // making the variable pin as a Digital Output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin, HIGH);  //set this pin to HIGH; the Normally Open contact inside the relay will close, 
                          //allowing the current to flow that turns on the motor.
delay(5000);              //delay for five seconds before turning off the motor.

digitalWrite(pin, LOW);  //set this pin to LOW, creating an open circuit inside the relay which cuts the power and turns off the motor.
delay(5000);             //delay for 5 seconds before looping back.
}
