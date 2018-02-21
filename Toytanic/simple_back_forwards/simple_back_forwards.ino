
#include "Robot.h"

namespace {
Robot *robot_singleton = nullptr;
Logger *logger_singleton = nullptr;
}

void setup()
{
  logger_singleton = new Logger{};
  auto& logger = *logger_singleton;
  robot_singleton = new Robot{logger};
  logger.log(Logger::Level::summary, "Toytanic FTW!");
}

void loop()
{
  const auto speed = 192;
  const auto delay_time = 8 * 1000;
  const auto short_delay_time = 2 * 1000;
  auto& robot = *robot_singleton;
  auto& logger = *logger_singleton;
  logger.log(Logger::Level::summary, "\n\n============= LOOP ==============\n");
  
  robot.forward(speed);
  delay(delay_time);
  robot.stop();
  delay(short_delay_time);
  robot.reverse(speed);
  delay(delay_time);
  robot.disable();
  delay(short_delay_time);
}

