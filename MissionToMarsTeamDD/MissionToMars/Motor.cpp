#include "Motor.hpp"

Motor::Motor(MotorDriver &motorDriver) :
  mMotorDriver(motorDriver)
{
  Stop();
}

void Motor::Run(MotorDirection direction, int speed)
{
  switch (direction)
  {
    case MotorDirection::Clockwise:
      mMotorDriver.SetMotorClockwiseDrive(true);
      mMotorDriver.SetMotorAntiClockwiseDrive(false);
      break;
      
    case MotorDirection::AntiClockwise:
      mMotorDriver.SetMotorClockwiseDrive(false);
      mMotorDriver.SetMotorAntiClockwiseDrive(true);
      break;

    default:
      Stop();
      break;
  }

  mMotorDriver.SetMotorSpeed(speed);
}

void Motor::Stop()
{  
  mMotorDriver.SetMotorClockwiseDrive(true);
  mMotorDriver.SetMotorAntiClockwiseDrive(true);

  // Use the clockwise and anti-clockwise drive to brake
  mMotorDriver.SetMotorSpeed(255);
}

