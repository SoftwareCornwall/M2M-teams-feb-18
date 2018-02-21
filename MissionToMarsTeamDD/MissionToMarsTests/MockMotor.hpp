#ifndef MOCK_MOTOR_HPP
#define MOCK_MOTOR_HPP

#include "MotorInterface.hpp"

class MockMotor : public MotorInterface
{
public:
  void Run(MotorDirection direction, int speed);
  void Stop();

  MotorDirection mDirection;
  int mSpeed;
  bool mMotorStopped;
};

#endif

