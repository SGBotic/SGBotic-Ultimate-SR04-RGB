/*
    This sketch is to change the color of the embedded LEDs of SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.
*/

#include "SGBotic_SR04_RGB.h"

#define i2cAddr 0x60  //default i2c address

#define redLED 0x01
#define greenLED 0x02
#define blueLED 0x03

#define light_intensity_min 0x00
#define light_intensity_max 0xff

#define time_delay 10

SGBotic_SR04_RGB sr04_rgb(i2cAddr);

void setup() {
  sr04_rgb.begin();

  //switch off all LEDs
  sr04_rgb.offAllLED();
}


void loop() {

  playLED(redLED);

  playLED(greenLED);

  playLED(blueLED);
}

void playLED(byte led) {

  //from low intensity to high intensity, step of 5
  for (int i = light_intensity_min; i <= light_intensity_max; i = i + 5)
  {
    sr04_rgb.setLED(led, i);
    delay(time_delay);
  }

  //from high intensity to low intensity, step of 5
  for (int i = light_intensity_max; i >= light_intensity_min; i = i - 5)
  {
    sr04_rgb.setLED(led, i);
    delay(time_delay);
  }

}
