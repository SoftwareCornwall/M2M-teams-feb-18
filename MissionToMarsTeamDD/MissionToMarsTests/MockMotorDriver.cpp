#include "MotorDriver.hpp"

bool MotorDriver_MotorIsBeingDrivenClockwise;
bool MotorDriver_MotorIsBeingDrivenAntiClockwise;
int MotorDriver_MotorSpeed;

MotorDriver::MotorDriver()
{
  MotorDriver_MotorIsBeingDrivenClockwise = false;
  MotorDriver_MotorIsBeingDrivenAntiClockwise = false;
  MotorDriver_MotorSpeed = 0;
}

void MotorDriver::SetMotorSpeed(int speed)
{
  MotorDriver_MotorSpeed = speed;
}

void MotorDriver::SetMotorClockwiseDrive(bool motorIsBeingDrivenClockwise)
{
  MotorDriver_MotorIsBeingDrivenClockwise = motorIsBeingDrivenClockwise;
}

void MotorDriver::SetMotorAntiClockwiseDrive(bool motorIsBeingDrivenAntiClockwise)
{
  MotorDriver_MotorIsBeingDrivenAntiClockwise = motorIsBeingDrivenAntiClockwise;
}

