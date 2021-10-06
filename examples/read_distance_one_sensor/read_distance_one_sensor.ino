/*
    This sketch is to measure the distance of an obstacle using SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.

    Only one unit of Ultimate SR04 RGB Ultrasonic Sensor is connected to I2C bus
*/

#include "SGBotic_SR04_RGB.h"

#define i2cAddr 0x60  //default i2c address

SGBotic_SR04_RGB sr04_rgb(i2cAddr);

void setup() {
  Serial.begin(9600);
  
  sr04_rgb.begin();
}


void loop() {
  
  sr04_rgb.trigger(); // start measurement
  delay(50); //wait for the sensor to acquire data
  
  Serial.print("cm: ");
  Serial.println(sr04_rgb.read_cm()); // read distance in cm
  
  delay(100); // short delay of 0.1 second
}
