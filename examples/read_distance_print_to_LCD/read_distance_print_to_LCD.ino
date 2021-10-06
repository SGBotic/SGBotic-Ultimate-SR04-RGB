/*
    This sketch is to measure the distance of an obstacle using SGBotic Ultimate SR04 RGB
    Ultrasonic Sensor.

    Three units of sensor with unique I2C address are connected to a single I2C bus.

    The output of these sensors will display on serial monitor and 2x16 I2C LCD module.
    (note: the LiquidCrystal_I2C currently does not work on ESP32)
    
*/

#include "SGBotic_SR04_RGB.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sonarAddr01 0x59  //i2c address of first sensor
#define sonarAddr02 0x60  //i2c address of second sensor
#define sonarAddr03 0x61  //i2c address of third sensor

#define lcdAddr 0x27

SGBotic_SR04_RGB sr04_rgb_01(sonarAddr01);
SGBotic_SR04_RGB sr04_rgb_02(sonarAddr02);
SGBotic_SR04_RGB sr04_rgb_03(sonarAddr03);

LiquidCrystal_I2C lcd(lcdAddr, 16, 2); // set the LCD address to 0x27 for 16 chars and 2 line display

void setup() {
  Serial.begin(9600);

  lcd.init();         // initialize the lcd
  lcd.backlight();    // switch on lcd backlight

  sr04_rgb_01.begin();  // initialize ultrasonic sensor
  sr04_rgb_02.begin();
  sr04_rgb_03.begin();

}

void loop() {
  
  sr04_rgb_01.trigger(); // start measurement of sensor #1
  sr04_rgb_02.trigger(); // start measurement of sensor #2
  sr04_rgb_03.trigger(); // start measurement of sensor #3

  delay(50); //wait for the sensor to acquire data

  Serial.print("#1: ");
  Serial.print(sr04_rgb_01.read_cm()); // read distance in cm
  Serial.print("   #2: ");
  Serial.print(sr04_rgb_02.read_cm()); // read distance in cm
  Serial.print("   #3: ");
  Serial.println(sr04_rgb_03.read_cm()); // read distance in cm

  lcd.clear();
  //print to LCD
  lcd.setCursor(0, 0); // set cursor to column 1, row 0
  lcd.print("0x59:");
  lcd.print(sr04_rgb_01.read_cm());

  lcd.setCursor(8, 0); // set cursor to column 1, row 0
  lcd.print("0x60:");
  lcd.print(sr04_rgb_02.read_cm()); // read distance in cm

  lcd.setCursor(0, 1); // set cursor to column 1, row 0
  lcd.print("0x61:");
  lcd.print(sr04_rgb_03.read_cm()); // read distance in cm

  delay(500);
}
