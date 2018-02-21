#include <ArduinoUnit.h>
#include "MotorDriver.hpp"
#include "Motor.hpp"

extern bool MotorDriver_MotorIsBeingDrivenClockwise;
extern bool MotorDriver_MotorIsBeingDrivenAntiClockwise;
extern int MotorDriver_MotorSpeed;

test(Motor_Run_sets_the_motor_speed_and_direction)
{
  MotorDriver driver;
  Motor motor(driver);

  int expectedSpeed = 100;
  motor.Run(MotorDirection::AntiClockwise, expectedSpeed);

  assertFalse(MotorDriver_MotorIsBeingDrivenClockwise);
  assertTrue(MotorDriver_MotorIsBeingDrivenAntiClockwise);
  assertEqual(expectedSpeed, MotorDriver_MotorSpeed);
}

test(Motor_Stop_stops_the_motor_with_braking)
{
  MotorDriver driver;
  Motor motor(driver);

  motor.Stop();

  int expectedSpeed = 255;
  assertTrue(MotorDriver_MotorIsBeingDrivenClockwise);
  assertTrue(MotorDriver_MotorIsBeingDrivenAntiClockwise);
  assertEqual(expectedSpeed, MotorDriver_MotorSpeed);
}

