#include "Robot.h"

namespace {
Robot *robot_singleton = nullptr;
Logger *logger_singleton = nullptr;
volatile int count_2 = 0;
volatile int count_3 = 0;
const byte interrupt_pin_2 = 2;
const byte interrupt_pin_3 = 3;
const auto pulses_per_meter = 926;
}

void left_motor_pulse_interrupt()
{
  auto& robot = *robot_singleton;
  robot.inc_left_motor_pulse();
}

void right_motor_pulse_interrupt()
{
  auto& robot = *robot_singleton;
  robot.inc_right_motor_pulse();
}

void setup()
{
  logger_singleton = new Logger{};
  auto& logger = *logger_singleton;
  robot_singleton = new Robot{logger};
  logger.log(Logger::Level::summary, "Toytanic FTW!");
  pinMode(interrupt_pin_2, INPUT_PULLUP);
  pinMode(interrupt_pin_3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_2), left_motor_pulse_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_3), right_motor_pulse_interrupt, CHANGE);
}

void loop()
{
  auto& robot = *robot_singleton;
  robot.forward(50);
  do {
    
    Serial.print("PULSES - Left: ");
    Serial.print(robot.get_left_motor_pulse_count());
    Serial.print("\t:Right: ");
    Serial.print(robot.get_right_motor_pulse_count());
    Serial.print("\tSPEED - Left: ");
    Serial.print(robot.get_left_motor_speed());
    Serial.print("\t:Right: ");
    Serial.println(robot.get_right_motor_speed());
    
    delay(100);
  } while (robot.get_left_motor_pulse_count() + robot.get_right_motor_pulse_count() < 4*pulses_per_meter);
  robot.stop();
  delay(1000);
  robot.disable();
  exit(0);
}
