#ifndef ROVER_HPP
#define ROVER_HPP

#include "RoverDirection.hpp"
#include "MotorInterface.hpp"

class Rover
{
private:
  MotorInterface &mRightTrack;
  MotorInterface &mLeftTrack;
  int mSpeed;
  RoverDirection mDirection;

public:
  Rover(MotorInterface &leftTrack, MotorInterface &rightTrack);
  void MoveForwards(int speed);
  void MoveBackwards(int speed);
  void Stop();
};

#endif
