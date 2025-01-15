/*! Joystick.cpp
* Custom Joystick code written to handle a Joystick on the Arduino platform.
* Written by Kaden Duncan-Matis, January 2025.
* BSD-3 License, all text above must be included in any redistribution. 
*/

#include "Arduino.h"
#include "Joystick.h"

Joystick::Joystick(uint8_t xInputPin, uint8_t yInputPin) // Constructor without button
{
  this->_xInputPin = xInputPin;
  this->_yInputPin = yInputPin;
  this->_btnPin = 255; // 255 = doesn't exist
}
Joystick::Joystick(uint8_t xInputPin, uint8_t yInputPin, uint8_t btnPin) // Constructor with button
{
  this->_xInputPin = xInputPin;
  this->_yInputPin = yInputPin;
  this->_btnPin = btnPin;
  pinMode(this->_btnPin, INPUT);
}
Joystick::~Joystick() // Destructor
{
  if (this->_btnPin != 255)
  {
    pinMode(this->_btnPin, INPUT); // Reset to base state
  }
}
uint16_t Joystick::getRawXValue() // Gets the raw X value mapped from 0 to 1024;
{
  return (uint16_t)analogRead(this->_xInputPin);
}
uint16_t Joystick::getRawYValue() // Gets the raw Y value mapped from 0 to 1024;
{
  return (uint16_t)analogRead(this->_yInputPin);
}
int16_t Joystick::getXValue() // Gets the X value mapped from -512 to 512
{
  return (int16_t)map(this->getRawXValue(), 0, 1023, -512, 511);
}
int16_t Joystick::getYValue() // Gets the Y value mapped from -512 to 512
{
  return (int16_t)map(this->getRawYValue(), 0, 1023, -512, 511);
}
bool Joystick::getButtonValue() // Gets the button value if a button is assigned.
{
  if (this->_btnPin == 255) return false;
  return digitalRead(this->_btnPin) == HIGH ? true : false;
}
