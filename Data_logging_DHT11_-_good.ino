/*
 This program shows how to take the readings of temperature and humidity in our surrounding by using a DHT11 sensor, and 
 saving these readings to an SD card using the SD card module adapter. The readings we achieved in this experiment
 will be plotted in a graph on Excel. 
 */

#include <SPI.h>;  //include this library when using the SD card adapter; this is serial data protocol.
#include <SD.h>;  //include this library also. 

#include "DHT.h";  //including the library for DHT sensor. This library is written by AdaFruit; must install this library.

#define DHTPIN 2 //defining a variable and assigning it to pin 2 on the Arduino board.
#define DHTTYPE DHT11  //defining a variable and enabling the DHT type which is the DHT11 type in the program since our sensor is the DHT11 one.
float hum = 0.0; //declaring a variable to be used to store the reading of humidity.
float temp = 0.0;  //declaring a variable to be used to store the reading of temperature.

DHT dht (DHTPIN,DHTTYPE);  //initialize the dht sensor.

File dataFile;  // accessing the file command and assign it to a variable.
int chipSelect = 4; //declare a variable for the CS pin and assign it to pin 4 on the Arduino.

void setup() {
  // put your setup code here, to run once:
dht.begin();  //enabling the dht command to read the hum and temp.
Serial.begin(9600);  //initialize the serial communication at 9600 baudrate.
SD.begin(chipSelect);  //initialize the SD pins.
}

void loop() {
  // put your main code here, to run repeatedly:
 hum = dht. readHumidity();  //reading the humidity and storing it to the variable "hum".
 temp = dht. readTemperature(); //reading the temperature and storing it to the variable "temp" in Celcius.
 
 dataFile = SD.open("datalog.txt", FILE_WRITE);  //open the file, and give it a name and then write to it.

 if (dataFile){  //If the SD module is able to detect the SD card, execute the following code.

 //printing the values on the serial monitor is not required for this experiment; but to check if the SD card 
 //is reading the temp and hum, then this surely helps. 
 Serial.println("SD card Found");  //print "SD card Found" if the SD card is working.
 Serial.print("Hum:");  //print the variable "Hum:".
 Serial.print(hum);  //print the value of hum.
 Serial.print("\t");  //create an space.
 Serial.print("Temp:");  //print the variable "Temp:".
 Serial.print(temp);  //print the value of temp.
 Serial.println();  //print these values vertically.
 delay(10000);  //delay 10 seconds.

//this section is to write data into the SD card. 
 dataFile.print(hum);  //write the values stored in hum.
 dataFile.print(",");  //create a space separated by comma.
 dataFile.print(temp);  //write the values stored in temp.
 dataFile.println();  //write these values vertically.
 delay(10000);        //delay 10 seconds.
 dataFile.close();    //ensure that this file is closed before starting a new file.
 }
 
 else  //this statement is TRUE if the previous condition is FALSE.
 {
  Serial.println("No SD card");  //print "No SD card" if the SD card is not working nor inserted. 
 }
}
