#ifndef LED_HPP
#define LED_HPP

#include "LedDriver.hpp"

class Led
{
private:
  LedDriver &mDriver;
  
public:
  Led(LedDriver &driver);
  void SetLedState(bool ledIsOn);
};

#endif
