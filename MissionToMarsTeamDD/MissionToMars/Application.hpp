#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Rover.hpp"
#include "Motor.hpp"
#include "MotorDriver.hpp"

class Application
{
public:
  void Setup();
  void Loop();

private:
  Rover* mRover;
  
  MotorDriver* mLeftMotorDriver;
  Motor* mLeftMotor;
  
  MotorDriver* mRightMotorDriver;
  Motor* mRightMotor;
};

#endif
