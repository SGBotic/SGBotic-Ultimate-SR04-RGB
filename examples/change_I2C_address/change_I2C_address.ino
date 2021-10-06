/*
    This sketch is to change the I2C address of SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.

    To change the I2C address of the sensor, make sure the sensors connected to the I2C bus
    have unique address. 

    Once the I2C address is successfully modified, the LED on the transceiver will blink for 
    4 times. The new address will permanently stored until next request occurs.

    For the sensor to run on new I2C address, you need to reset the sensor by power cycle 
    the sensor (remove and re-connect the power).

    To reset the I2C address to default I2C address (0x60), short the SCL pin to ground then 
    apply power to sensor. The green LED will blink for 3 times at 1 second interval to indicate the
    sensor is sucessfully reset to default value (0x60). 
*/

#include "SGBotic_SR04_RGB.h"

#define existing_addr 0x60
#define new_addr 0x61  //valid I2C address: 0x08 to 0x71

SGBotic_SR04_RGB sr04_rgb(existing_addr);

void setup() {
  sr04_rgb.begin();
  sr04_rgb.setI2CAddress(new_addr);
  
  // IMPORTANT
  //Remember to power cycle the sensor for this change to take effect.
}

void loop() {

  /***  do nothing;  ***/

}
