#include "MockMotor.hpp"

void MockMotor::Run(MotorDirection direction, int speed)
{
  mDirection = direction;
  mSpeed = speed;
}

void MockMotor::Stop()
{
  mMotorStopped = true;
}

