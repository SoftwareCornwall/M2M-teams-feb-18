#include <ArduinoUnit.h>
#include "Rover.hpp"
#include "RoverDirection.hpp"
#include "MockMotor.hpp"

extern RoverDirection Rover_Direction;
extern int Rover_Speed;

test(Rover_Move_Forwards)
{
  MockMotor leftMotor;
  MockMotor rightMotor;
  Rover rover(leftMotor, rightMotor);

  int speed = 100;
  rover.MoveForwards(speed);

  assertEqual(speed, leftMotor.mSpeed);
  assertEqual(MotorDirection::AntiClockwise, leftMotor.mDirection);
  
  assertEqual(speed, rightMotor.mSpeed);
  assertEqual(MotorDirection::Clockwise, rightMotor.mDirection);
}

test(Rover_Move_Backwards)
{
  MockMotor leftMotor;
  MockMotor rightMotor;
  Rover rover(leftMotor, rightMotor);

  int speed = 100;
  rover.MoveBackwards(speed);

  assertEqual(speed, leftMotor.mSpeed);
  assertEqual(MotorDirection::Clockwise, leftMotor.mDirection);
  
  assertEqual(speed, rightMotor.mSpeed);
  assertEqual(MotorDirection::AntiClockwise, rightMotor.mDirection);
}


