/*
    This sketch is to measure the distance of an obstacle using SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.

    Three units of sensor with unique I2C address are connected to a single I2C bus. 
*/

#include "SGBotic_SR04_RGB.h"

#define i2cAddr01 0x59  //i2c address of first sensor
#define i2cAddr02 0x60  //i2c address of second sensor
#define i2cAddr03 0x61  //i2c address of third sensor

SGBotic_SR04_RGB sr04_rgb_01(i2cAddr01); // initialize ultrasonic sensor
SGBotic_SR04_RGB sr04_rgb_02(i2cAddr02);
SGBotic_SR04_RGB sr04_rgb_03(i2cAddr03);

void setup() {
  Serial.begin(9600);
  
  sr04_rgb_01.begin();
  sr04_rgb_02.begin();
  sr04_rgb_03.begin();
}


void loop() {
  
  sr04_rgb_01.trigger(); // start measurement of sensor #1
  sr04_rgb_02.trigger(); // start measurement of sensor #2
  sr04_rgb_03.trigger(); // start measurement of sensor #3

  delay(50); //wait for the sensor to acquire data
  
  Serial.print("#1: ");
  Serial.print(sr04_rgb_01.read_cm()); // read sensor #1distance in cm
  Serial.print("   #2: ");
  Serial.print(sr04_rgb_02.read_cm()); // read sensor #2 distance in cm
  Serial.print("   #3: ");
  Serial.println(sr04_rgb_03.read_cm()); // read sensor #3 distance in cm
  
  //delay(100); // short delay of 0.1 second
}
