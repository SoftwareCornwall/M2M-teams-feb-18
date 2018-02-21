#include "Led.hpp"
#include "TimerDriver.hpp"

Led::Led(LedDriver &driver) :
  mDriver(driver)
{
}

void Led::SetLedState(bool ledIsOn)
{
  mDriver.SetLedState(ledIsOn);
}
