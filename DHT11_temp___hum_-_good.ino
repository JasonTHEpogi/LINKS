/*
Displaying the humidity and temperature on the serial monitor.
The DHT11 sensor is programmed to measure the humidity and temperature and displays the readings 
on the serial monitor.
*/

#include "DHT.h";  //including the library for DHT sensor. This library is written by AdaFruit; must install this library.

#define DHTPIN 12 //defining a variable and assigning it to pin 12 on the Arduino board.
#define DHTTYPE DHT11  //defining a variable and enabling the DHT type which is the DHT11 type in the program since our sensor is the DHT11 one.
float hum = 0.0; //declaring a variable to be used to store the reading of humidity.
float temp = 0.0;  //declaring a variable to be used to store the reading of temperature.

DHT dht (DHTPIN,DHTTYPE);  //initialize the dht sensor.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  //establishing a serial communication at 9600 baudrate.
dht.begin();  //enabling the dht command to read the hum and temp.
}

void loop() {
  // put your main code here, to run repeatedly:
 hum = dht. readHumidity();  //reading the humidity and storing it to the variable "hum".
 temp = dht. readTemperature(); //reading the temperature and storing the value in "temp".

Serial.print("Hum:");  //printing the word "Hum:" on the serial monitor.
Serial.print(hum);  //printing the value of hum on the serial monitor next to the word "Hum:".
Serial.print(" %");  //printing the " %" symbol as well.
Serial.print("\t");  //creating a space between this reading and the next one when displaying them on the serial monitor.

Serial.print("Temp:");  //printing the word "Temp:" on the serial monitor.
Serial.print(temp);  //printing the value of the temperature(temp).
Serial.print(" C");  //printing the " C" to display the unit of temperature.
Serial.print("\t");  //creating space.
Serial.println();  // printing these readings vertically.

}
