#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "MotorInterface.hpp"
#include "MotorDriver.hpp"
#include "MotorDirection.hpp"

class Motor : public MotorInterface
{
private:
  MotorDriver &mMotorDriver;
  
public:
  Motor(MotorDriver &motorDriver);
  void Run(MotorDirection direction, int speed);
  void Stop();
};

#endif
