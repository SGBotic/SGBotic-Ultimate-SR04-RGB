/*
    This sketch is to read the firmware version of SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.
*/

#include "SGBotic_SR04_RGB.h"

#define i2cAddr 0x60  //default i2c address

SGBotic_SR04_RGB sr04_rgb(i2cAddr);

void setup() {
  Serial.begin(9600);

  sr04_rgb.begin();
  Serial.println("");
  Serial.print("firmware version: ");
  Serial.println(sr04_rgb.readVersion());
}


void loop() {

  /** do nothing here **/

}
