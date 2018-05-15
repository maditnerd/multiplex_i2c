/*
Code de test du multiplexeur TCA9548a avec 4 capteurs Si7021
Auteur: Remi Sarrailh (remi@madnerd.org)
Licence: MIT
Sources ---
Adafruit - https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout?view=all#wiring-and-test
Sparkfun - https://www.sparkfun.com/products/13763
*/

#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float sensor0_humidity = 0;
float sensor0_tempf = 0;
float sensor1_humidity = 0;
float sensor1_tempf = 0;
float sensor2_humidity = 0;
float sensor2_tempf = 0;
float sensor3_humidity = 0;
float sensor3_tempf = 0;
#define TCAADDR 0x70

//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor0;
Weather sensor1;
Weather sensor2;
Weather sensor3;

// Sélecteur de canal I2C
void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

//---------------------------------------------------------------
void setup()
{
  Serial.begin(9600);   // open serial over USB at 9600 baud
  //Initialize the I2C sensors and ping them

  tcaselect(0);
  sensor0.begin();
  tcaselect(1);
  sensor1.begin();
  tcaselect(2);
  sensor2.begin();
  tcaselect(3);
  sensor3.begin();
}
//---------------------------------------------------------------
void loop()
{
  //Get readings from all sensors
  getWeather();
  printInfo();
  delay(1000);

}
//---------------------------------------------------------------
void getWeather()
{ 
  tcaselect(0);
  sensor0_humidity = sensor0.getRH();
  sensor0_tempf = sensor0.getTempF();

  tcaselect(1);
  sensor0_humidity = sensor1.getRH();
  sensor0_tempf = sensor1.getTempF();

  tcaselect(2);
  sensor0_humidity = sensor2.getRH();
  sensor0_tempf = sensor2.getTempF();

  tcaselect(3);
  sensor0_humidity = sensor3.getRH();
  sensor0_tempf = sensor3.getTempF();

}
//---------------------------------------------------------------
void printInfo()
{
  //This function prints the weather data out to the default Serial Port
  Serial.print("Sensor0 - ");
  Serial.print("Temp:");
  Serial.print(sensor0_tempf);
  Serial.print("F, ");
  Serial.print("Humidity:");
  Serial.print(sensor0_humidity);
  Serial.println("%");

  Serial.print("Sensor1 - ");
  Serial.print("Temp:");
  Serial.print(sensor1_tempf);
  Serial.print("F, ");
  Serial.print("Humidity:");
  Serial.print(sensor1_humidity);
  Serial.println("%");

  Serial.print("Sensor2 - ");
  Serial.print("Temp:");
  Serial.print(sensor2_tempf);
  Serial.print("F, ");
  Serial.print("Humidity:");
  Serial.print(sensor2_humidity);
  Serial.println("%");

  Serial.print("Sensor3 - ");
  Serial.print("Temp:");
  Serial.print(sensor3_tempf);
  Serial.print("F, ");
  Serial.print("Humidity:");
  Serial.print(sensor3_humidity);
  Serial.println("%");
}
