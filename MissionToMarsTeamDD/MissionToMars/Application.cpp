#include "Application.hpp"
#include "TimerDriver.hpp"

static const int LeftMotorSpeedPin = 9;
static const int LeftMotorClockwiseDrivePin = 7;
static const int LeftMotorAntiClockwiseDrivePin = 8;
static const double LeftMotorClockwiseEqualiser = 4250.0 / 4250.0;
static const double LeftMotorAntiClockwiseEqualiser = 4300.0 / 4500.0;

static const int RightMotorSpeedPin = 10;
static const int RightMotorClockwiseDrivePin = 12;
static const int RightMotorAntiClockwiseDrivePin = 11;
static const double RightMotorClockwiseEqualiser = 4500.0 / 4500.0;
static const double RightMotorAntiClockwiseEqualiser = 4200.0 / 4250.0;

void Application::Setup()
{
  mLeftMotorDriver = new MotorDriver(LeftMotorSpeedPin,
                                     LeftMotorClockwiseDrivePin,
                                     LeftMotorAntiClockwiseDrivePin,
                                     LeftMotorClockwiseEqualiser,
                                     LeftMotorAntiClockwiseEqualiser);
  mLeftMotor = new Motor(*mLeftMotorDriver);
  
  mRightMotorDriver = new MotorDriver(RightMotorSpeedPin,
                                      RightMotorClockwiseDrivePin,
                                      RightMotorAntiClockwiseDrivePin,
                                      RightMotorClockwiseEqualiser,
                                      RightMotorAntiClockwiseEqualiser);
  mRightMotor = new Motor(*mRightMotorDriver);
  
  mRover = new Rover(*mLeftMotor, *mRightMotor);
  
  mRover->MoveForwards(50);
  TimerDriver::DelayMs(14000);
  mRover->Stop();
}

void Application::Loop()
{
}

