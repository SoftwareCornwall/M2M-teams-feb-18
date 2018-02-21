#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "MotorDirection.hpp"

class MotorInterface
{
public:
  virtual void Run(MotorDirection direction, int speed) = 0;
  virtual void Stop() = 0;
};

#endif
