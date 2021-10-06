#ifndef _SGBOTIC_SR04_RGB_
#define _SGBOTIC_SR04_RGB_

#include <Arduino.h>

#if defined(ESP32)
#include <pgmspace.h>
#define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif
#if defined(ESP8266)
#include <pgmspace.h>
#define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif
#ifdef avr
#include <util/delay.h>
#endif


#define Ultimate_SR04_RGB_I2C_ADDRESS 0x60 /**< Default Ultimate SR04 RGB I2C Slave Address */
#define I2C_ADDR_LOW    0X08
#define I2C_ADDR_HIGH   0X71
#define TRIGGER_SONAR_REG       0x01 //trigger sonar
#define TRIGGER_SONAR           0x01

#define SET_RGB                 0X02
#define SET_R_VALUE             SET_RGB
#define SET_G_VALUE             SET_R_VALUE + 1
#define SET_B_VALUE             SET_G_VALUE + 1


#define GET_SONAR_CM            0x0A
#define GET_SONAR_CM_H          GET_SONAR_CM
#define GET_SONAR_CM_L          GET_SONAR_CM_H + 1

#define GET_SONAR_US            0x0C
#define GET_SONAR_US_H          GET_SONAR_US
#define GET_SONAR_US_L          GET_SONAR_US_H + 1

//set I2C address
#define SET_I2C_ADDR            0xE0
    //read software
#define GET_VERSION             0xF0

#define red 0x01
#define green 0x02
#define blue 0x03

class SGBotic_SR04_RGB
{
public:
    SGBotic_SR04_RGB();
    SGBotic_SR04_RGB(const uint8_t addr);
    void begin();
    void trigger();
    uint16_t read_cm();
    uint16_t read_us();
    void setLED(uint8_t color, uint8_t brightness);
    void offAllLED();
    uint8_t readVersion();
    void setI2CAddress(uint8_t newAddr);

private:
    uint8_t _i2cAddr;

    uint8_t readWire8(uint8_t reg);
    uint16_t readWire16(uint8_t reg);
    void writeWire8(uint8_t reg, uint8_t d);
};

#endif