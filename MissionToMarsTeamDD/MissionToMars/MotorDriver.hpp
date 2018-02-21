#ifndef MOTOR_DRIVER_HPP
#define MOTOR_DRIVER_HPP

#include "MotorDirection.hpp"

class MotorDriver
{
public:
  MotorDriver(int speedPin,
              int clockwiseDrivePin,
              int antiClockwiseDrivePin,
              double clockwiseEqualiser,
              double antiClockwiseEqualiser);

  int GetMotorSpeed();
  MotorDirection GetMotorDirection();
  void SetMotorSpeed(int speed);
  void SetMotorClockwiseDrive(bool motorIsBeingDrivenClockwise);
  void SetMotorAntiClockwiseDrive(bool motorIsBeingDrivenAntiClockwise);

private:
  int mSpeedPin;
  int mClockwiseDrivePin;
  int mAntiClockwiseDrivePin;
  double mClockwiseEqualiser;
  double mAntiClockwiseEqualiser;

  int mSpeed;
  bool mMotorIsBeingDrivenClockwise;
  bool mMotorIsBeingDrivenAntiClockwise;
};

#endif
