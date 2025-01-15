/*! Joystick.h
* Custom Joystick code written to handle a Joystick on the Arduino platform.
* Written by Kaden Duncan-Matis, January 2025.
* BSD-3 License, all text above must be included in any redistribution. 
*/

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"

class Joystick
{
  public:
    Joystick(uint8_t xInputPin, uint8_t yInputPin); // Constructor without button
    Joystick(uint8_t xInputPin, uint8_t yInputPin, uint8_t btnPin); // Constructor with button
    ~Joystick(); // Destructor
    uint16_t getRawXValue(); // Gets the raw X value mapped from 0 to 1024;
    uint16_t getRawYValue(); // Gets the raw Y value mapped from 0 to 1024;
    bool getButtonValue(); // Gets the button value if a button is assigned.
    int16_t getXValue(); // Gets the X value mapped from -512 to 512
    int16_t getYValue(); // Gets the Y value mapped from -512 to 512
    uint8_t getXPin();
    uint8_t getYPin();
    uint8_t getBtnPin();
  private:
    uint8_t _xInputPin;
    uint8_t _yInputPin;
    uint8_t _btnPin;
};

#endif