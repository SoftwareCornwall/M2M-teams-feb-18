#include "Arduino.h"
#include "Robot.h"

namespace {
const auto correction_pulse_interval = 40;
}

void Robot::forward(uint8_t speed)
{
  logger.log("Forward");
  left_motor.forward(speed);
  right_motor.forward(speed);
}

void Robot::reverse(uint8_t speed)
{
  logger.log("Reverse");
  left_motor.reverse(speed);
  right_motor.reverse(speed);
}

void Robot::stop(uint8_t speed)
{
  logger.log("Stop");
  left_motor.stop(speed);
  right_motor.stop(speed);
}

void Robot::disable()
{
  logger.log("Disable");
  left_motor.disable();
  right_motor.disable();
}

void Robot::check_motors()
{
  const auto& lpc = left_motor.get_pulse_count();
  const auto& rpc = right_motor.get_pulse_count();
  const auto total_pulse_count = lpc + rpc;
  
  if (!(total_pulse_count % correction_pulse_interval))
  {
    const auto delta = static_cast<long>(rpc) - static_cast<long>(lpc);
    auto correction = delta / 10.0;
    if (correction > 1)
      correction = 1;
    else if (correction < -1)
      correction = -1;
    left_motor.set_speed(50 + 15 * correction);
    right_motor.set_speed(50 - 15 * correction);
  }
}
