#include "MotorDriver.hpp"

MotorDriver::MotorDriver(int speedPin,
                         int clockwiseDrivePin,
                         int antiClockwiseDrivePin,
                         double clockwiseEqualiser,
                         double antiClockwiseEqualiser)
{
  mClockwiseEqualiser = clockwiseEqualiser;
  mAntiClockwiseEqualiser = antiClockwiseEqualiser;
  
  mSpeedPin = speedPin;
  pinMode(speedPin, OUTPUT);
  
  mClockwiseDrivePin = clockwiseDrivePin;
  pinMode(clockwiseDrivePin, OUTPUT);
  
  mAntiClockwiseDrivePin = antiClockwiseDrivePin;
  pinMode(antiClockwiseDrivePin, OUTPUT);
}

void MotorDriver::SetMotorSpeed(int speed)
{
  mSpeed = speed;

  MotorDirection direction = GetMotorDirection();
  double equaliserToUse = (direction == MotorDirection::Clockwise) ? mClockwiseEqualiser : mAntiClockwiseEqualiser;
  
  int actualMotorSpeed = (int)((double)speed * equaliserToUse);
  analogWrite(mSpeedPin, actualMotorSpeed);
}
  
void MotorDriver::SetMotorClockwiseDrive(bool motorIsBeingDrivenClockwise)
{
  mMotorIsBeingDrivenClockwise = motorIsBeingDrivenClockwise;
  
  if (motorIsBeingDrivenClockwise)
  {
    digitalWrite(mClockwiseDrivePin, 1);
  }
  else
  {
    digitalWrite(mClockwiseDrivePin, 0);
  }
}

void MotorDriver::SetMotorAntiClockwiseDrive(bool motorIsBeingDrivenAntiClockwise)
{
  mMotorIsBeingDrivenAntiClockwise = motorIsBeingDrivenAntiClockwise;
  
  if (motorIsBeingDrivenAntiClockwise)
  {
    digitalWrite(mAntiClockwiseDrivePin, 1);
  }
  else
  {
    digitalWrite(mAntiClockwiseDrivePin, 0);
  }
}

int MotorDriver::GetMotorSpeed()
{
  return mSpeed;
}

MotorDirection MotorDriver::GetMotorDirection()
{
  if (mMotorIsBeingDrivenClockwise && !mMotorIsBeingDrivenAntiClockwise)
  {
    return MotorDirection::Clockwise;
  }
  
  return  MotorDirection::AntiClockwise;
}

