#ifndef ROBOT_H
#define ROBOT_H

#include "Arduino.h"
#include "Logger.h"
#include "Motor.h"

namespace {
  const auto left_motor_pin_enable = 9;
  const auto left_motor_pin_forward = 8;
  const auto left_motor_pin_reverse = 7;
  const auto right_motor_pin_enable = 10;
  const auto right_motor_pin_forward = 12;
  const auto right_motor_pin_reverse = 11;
}

class Robot
{
private:
  Motor left_motor;
  Motor right_motor;
  Logger& logger;

  void check_motors();

public:
  Robot(Logger& _logger):
    left_motor{left_motor_pin_enable, left_motor_pin_forward, left_motor_pin_reverse},
    right_motor{right_motor_pin_enable, right_motor_pin_forward, right_motor_pin_reverse},
    logger{_logger}
  {}

  void forward(byte speed = Motor::max_speed);
  void reverse(byte speed = Motor::max_speed);
  void stop(byte speed = Motor::max_speed);
  void disable();

  void inc_left_motor_pulse() { left_motor.inc_pulse(); check_motors(); }
  unsigned long get_left_motor_pulse_count() const { return left_motor.get_pulse_count(); }
  void inc_right_motor_pulse() { right_motor.inc_pulse(); check_motors(); }
  unsigned long get_right_motor_pulse_count() const { return right_motor.get_pulse_count(); }
  int get_left_motor_speed() const { return left_motor.get_speed(); }
  int get_right_motor_speed() const { return right_motor.get_speed(); }
};

#endif
