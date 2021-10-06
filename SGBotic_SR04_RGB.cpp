/*
 *  Library for the SGBotic Ultimate SR04 RGB ultrasonic sensor.
 *
 *Support Arduino Atmega boards, ESP8266, ESP32
 */

#include "SGBotic_SR04_RGB.h"
#include <Wire.h>

SGBotic_SR04_RGB::SGBotic_SR04_RGB()
{
    _i2cAddr = Ultimate_SR04_RGB_I2C_ADDRESS;
    
}

SGBotic_SR04_RGB::SGBotic_SR04_RGB(const uint8_t addr)
{
    _i2cAddr = addr;
     
}
void SGBotic_SR04_RGB::begin()
{
    Wire.begin();
}
void SGBotic_SR04_RGB::trigger()
{
    writeWire8(TRIGGER_SONAR_REG, TRIGGER_SONAR);
    _delay_ms(1);
}

uint16_t SGBotic_SR04_RGB::read_cm()
{
    uint16_t cm = readWire16(GET_SONAR_CM);
    _delay_ms(1);
    return (cm);
}

uint16_t SGBotic_SR04_RGB::read_us()
{
    uint16_t us = readWire16(GET_SONAR_US);
    _delay_ms(1);
    return (us);
}

void SGBotic_SR04_RGB::setLED(uint8_t color, uint8_t brightness)
{
    if (color == red)
    {
        writeWire8(SET_R_VALUE, brightness);
    }
    else if (color == green)
    {
        writeWire8(SET_G_VALUE, brightness);
    }
    else if (color == blue)
    {
        writeWire8(SET_B_VALUE, brightness);
    }
    _delay_ms(1);
}

void SGBotic_SR04_RGB::offAllLED()
{
    writeWire8(SET_R_VALUE, 0);
    _delay_ms(1);
    writeWire8(SET_G_VALUE, 0);
    _delay_ms(1);
    writeWire8(SET_B_VALUE, 0);
    _delay_ms(1);
}
uint8_t SGBotic_SR04_RGB::readVersion()
{
    uint8_t ver = readWire8(GET_VERSION);
    _delay_ms(1);
    return (ver);
}

void SGBotic_SR04_RGB::setI2CAddress(uint8_t newAddr)
{
    if ((newAddr >= I2C_ADDR_LOW) && (newAddr <= I2C_ADDR_HIGH))
    {
        writeWire8(SET_I2C_ADDR, newAddr);
    }
}

uint8_t SGBotic_SR04_RGB::readWire8(uint8_t reg)
{
    Wire.beginTransmission(_i2cAddr);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom((uint8_t)_i2cAddr, (uint8_t)1);
    return Wire.read();
}

uint16_t SGBotic_SR04_RGB::readWire16(uint8_t reg)
{
    uint8_t data_H, data_L;
    uint16_t data16;

    Wire.beginTransmission(_i2cAddr);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom((uint8_t)_i2cAddr, (uint8_t)2);
    if (Wire.available() >= 1)
    {
        data_H = Wire.read();
        data_L = Wire.read();
    }
    data16 = ((uint16_t)data_H << 8) | ((uint16_t)data_L);
    return data16;
}

void SGBotic_SR04_RGB::writeWire8(uint8_t reg, uint8_t d)
{
    Wire.beginTransmission(_i2cAddr);
    Wire.write(reg);
    Wire.write(d);
    Wire.endTransmission();
}
