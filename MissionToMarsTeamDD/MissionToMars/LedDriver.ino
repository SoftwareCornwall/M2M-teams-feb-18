#include "LedDriver.hpp"

LedDriver::LedDriver()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void LedDriver::SetLedState(bool ledIsOn)
{
  if (ledIsOn)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
