/*
 Displaying the humidity and temperature readings of the DHT11 sensor on the LCD screen.
 The dht11 can measure humidity and temperature which is why in this experiment, we are going to display them
 on the LCD screen.
 */

#include "DHT.h";  //including the library for DHT sensor. This library is written by AdaFruit; must install this library.
#include <LiquidCrystal.h>;  //must include the LiquidCrystal library from adaFruit.

#define DHTPIN 8  //defining a variable and assigning it to pin 8 on the Arduino board.
#define DHTTYPE DHT11  //defining a variable and enabling the DHT type which is the DHT11 type in the program since our sensor is DHT11.
float hum = 0; //declaring a variable to be used to store the reading of humidity.
float temp = 0;  //declaring a variable to be used to store the reading of temperature.

DHT dht (DHTPIN,DHTTYPE);  //initialize the dht sensor.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //initializing the data pins on the arduino UNO to match the LCD's pins.

void setup() {
  // put your setup code here, to run once:
dht.begin();  //enabling the dht command to read the hum and temp.
lcd.begin(16, 2); //configuring the LCD to display 16 character in columns and to enable 2 rows.

}

void loop() {
hum = dht. readHumidity();  //reading the humidity and storing it in the variable "hum".
temp = dht. readTemperature(); //reading the temperature and storing the value in the variable "temp".

lcd.setCursor(0,0);  //set the cursor position to upper left of the screen;(column = 0 & row = 0).
lcd.print("Hum:");  //printing "Hum: " on the bottom row of the LCD.
lcd.print(hum);  //printing the value of hum on the LCD screen.
lcd.print(" %");  //printing "%" on the screen.

lcd.setCursor(0,1);  //set the cursor position to bottom left of the screen;(column = 0 & row = 1).
lcd.print("Temp:");  //printing "Temp: " on the bottom right side row of the LCD.
lcd.print(temp);  //printing the value of temp in celcius on the LCD screen.
lcd.print(" C");  //printing "C", the unit for celcius.

}
