/*
    This sketch uses moving average filter to smoothen the measurement.

*/
#include "SGBotic_SR04_RGB.h"

#define i2cAddr 0x60  //default i2c address

uint16_t dist_cm;

// variable declariation for moving average filter
/*****************************/
uint8_t index_t = 0;
const uint8_t sample_size = 5;
uint16_t sum = 0;
uint16_t readings[sample_size];
uint16_t dist_average = 0;
/*****************************/

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

  //wait for the sensor to acquire data
  delay(50);

  // read distance in cm
  dist_cm = sr04_rgb.read_cm();

  dist_average = movingAverage(dist_cm);

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

  //print to serial console
  Serial.print("cm: ");
  Serial.println(dist_average);

  delay(10); //short delay before next cycle
}

//funcation to compute average value of distance read from sensor
uint16_t movingAverage(uint16_t) {
  uint16_t getAverage;

  // remove oldest entry
  sum = sum - readings[index_t];

  // Add the newest reading to the array
  readings[index_t] = dist_cm;

  // Add the newest reading to the sum
  sum = sum + dist_cm;

  // Increment the index, and wrap to 0 if it exceeds the sample size
  index_t = (index_t + 1) % sample_size;

  // get the average of the distance meansured
  getAverage = sum / sample_size;

  return getAverage;
}
