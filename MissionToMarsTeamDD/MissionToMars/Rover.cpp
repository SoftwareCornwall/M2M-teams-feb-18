#include "Rover.hpp"

Rover::Rover(MotorInterface &leftTrack, MotorInterface &rightTrack) :
  mLeftTrack(leftTrack),
  mRightTrack(rightTrack)
{
  mSpeed = 0;
  mDirection = RoverDirection::Forwards;
}

void Rover::MoveForwards(int speed)
{
  mSpeed = speed;
  mDirection = RoverDirection::Forwards;
  mRightTrack.Run(MotorDirection::Clockwise, mSpeed);
  mLeftTrack.Run(MotorDirection::AntiClockwise, mSpeed);
}

void Rover::MoveBackwards(int speed)
{ 
  mSpeed = speed;
  mDirection = RoverDirection::Backwards;
  mRightTrack.Run(MotorDirection::AntiClockwise, mSpeed);
  mLeftTrack.Run(MotorDirection::Clockwise, mSpeed);
}

void Rover::Stop()
{
  mSpeed = 0;
  mRightTrack.Stop();
  mLeftTrack.Stop();
}

