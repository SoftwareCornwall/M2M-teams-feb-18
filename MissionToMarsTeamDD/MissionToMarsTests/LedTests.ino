#include <ArduinoUnit.h>
#include "LedDriver.hpp"
#include "Led.hpp"

extern bool LedDriver_LedIsOn;

test(Led_SetLedState_turns_the_LED_off)
{
  LedDriver driver;
  Led led(driver);

  bool ledIsOn = false;
  led.SetLedState(ledIsOn);

  assertFalse(LedDriver_LedIsOn);
}

test(Led_SetLedState_turns_the_LED_on)
{
  LedDriver driver;
  Led led(driver);

  bool ledIsOn = true;
  led.SetLedState(ledIsOn);

  assertTrue(LedDriver_LedIsOn);
}

