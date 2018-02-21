#include "LedDriver.hpp"

bool LedDriver_LedIsOn;

LedDriver::LedDriver()
{
  LedDriver_LedIsOn = false;
}

void LedDriver::SetLedState(bool ledIsOn)
{
  LedDriver_LedIsOn = ledIsOn;
}

