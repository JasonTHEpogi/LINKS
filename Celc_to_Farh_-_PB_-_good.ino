/*
 Displaying the humidity and temperature readings of the DHT11 sensor on the LCD screen.
 Also, converting the temperature from degree Celcius into Fahrenheit by pressing the pushbutton in the circuit.
 The pushbutton when it is pressed, the reading will be displayed in Fahrenheit; however, if it is not pressed,
 the reading should be in Celcius. 
 */

#include "DHT.h";  //including the library for DHT sensor. This library is written by AdaFruit; must install this library.
#include <LiquidCrystal.h>;  //must include the LiquidCrystal library from adaFruit.

#define DHTPIN 8  //defining a variable and assigning it to pin 8 on the Arduino board.
#define DHTTYPE DHT11  //defining a variable and enabling the DHT type which is the DHT11 type in the program since our sensor is DHT11.
#define Pb 7  //defining a variable for the PB.

float hum = 0; //declaring a variable to be used to store the reading of humidity.
float temp = 0;  //declaring a variable to be used to store the reading of temperature.
float Fahr = 0;  //declaring a variable to store the scaled temperature from C to F.
int PbState = 0;  //storing the reading coming from the pushbutton.

DHT dht (DHTPIN,DHTTYPE);  //initialize the dht sensor.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //initializing the data pins on the arduino UNO to match the LCD's pins.

void setup() {
  // put your setup code here, to run once:
dht.begin();  //enabling the dht.begin command to read the hum and temp.
lcd.begin(16, 2); //configuring the LCD to display 16 character in columns and to enable 2 rows.
pinMode(Pb, INPUT);  //set the Pb as a digital input.

}

void loop() {
PbState = digitalRead(Pb);  //reading the state of the Pb and storing it in the variable Pbstate.
hum = dht. readHumidity();  //reading the humidity and storing it in the variable "hum".
temp = dht. readTemperature(); //reading the temperature and storing the value in the variable "temp"; this temperature reading is in degree Celcius.
Fahr = temp * 1.8 + 32;  //converting Celcius into Fahrenheit using the following formula.
  
if (PbState == HIGH)  //if the condition in this IF statement is TRUE, run the code below.
{
lcd.setCursor(0,0);  //set the cursor position to upper left of the screen;(column = 0 & row = 0).
lcd.print("Humidity:");  //printing "Humidity: " on the first row of the LCD.
lcd.print(hum);  //printing the value of hum on the LCD screen.
lcd.print(" %");  //printing "%" on the screen.

lcd.setCursor(0,1);  //set the cursor position to bottom left of the screen;(column = 0 & row = 1).
lcd.print("Fahr:");  //printing "Fahr: " on the bottom row of the LCD.
lcd.print(Fahr);  //printing the value of temp in fahrenheit on the LCD screen.
lcd.print(" F");  //printing "F".
}

else  //if the condition is FALSE, execute this code.
{
lcd.setCursor(0,0);  //set the cursor position to upper left of the screen;(column = 0 & row = 0).
lcd.print("Humidity:");  ////printing "Humidity: " on the first row of the LCD.
lcd.print(hum);  //printing the value of hum on the LCD screen.
lcd.print(" %");  //printing "%" on the screen.

lcd.setCursor(0,1);  //set the cursor position to bottom left of the screen;(column = 0 & row = 1).
lcd.print("Celc:");  //printing "Celc: " on the bottom of the LCD.
lcd.print(temp);  //printing the value of temp in celcius on the LCD screen.
lcd.print(" C");  //printing "C", the unit for celcius.
}

}
