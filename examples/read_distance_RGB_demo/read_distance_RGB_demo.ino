/*
    Read measured distrance from SGBotic Ultimate SR04 RGB Ultrasonic sensor

*/

#include "SGBotic_SR04_RGB.h"

#define i2cAddr 0x60  //default i2c address

uint16_t dist_cm, dist_us;

SGBotic_SR04_RGB sr04_rgb(i2cAddr);

void setup() {
  Serial.begin(9600);

  sr04_rgb.begin();

  // read firmware version
  Serial.println(sr04_rgb.readVersion());

  // switch off all LEDs
  sr04_rgb.offAllLED();
}

void loop() {

  // start distance measurement
  sr04_rgb.trigger();
  delay(50); //wait for the sensor to acquire data

  // read distance in cm
  dist_cm = sr04_rgb.read_cm();
  Serial.print("cm: ");
  Serial.println(dist_cm);
  
  // turn on blue LED if distance measured is less than 50cm
  // The sensor will return 0 if the measurement is beyond sensing range,
  // therefore the valid value shoud be higher than 0
  if ((dist_cm > 0) && (dist_cm < 50)) {
    sr04_rgb.setLED(blue, 255);
    sr04_rgb.setLED(red, 0);

    // turn on red LED if distance measured is larger than 50cm
  } else {
    sr04_rgb.setLED(blue, 0);
    sr04_rgb.setLED(red, 125);
  }

  delay(100); //delay 0.1s before start next cycle
}
