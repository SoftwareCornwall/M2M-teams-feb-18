#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor
{
private:
  int speed = 0;
  int enable_pin = 0;
  int forward_pin = 0;
  int reverse_pin = 0;
  volatile unsigned long pulse_count = 0;

public:
  static const int max_speed = 100;
  Motor(int _enable_pin, int _forward_pin, int _reverse_pin);

  void set_speed(int speed = max_speed);
  int get_speed() const { return speed; }
  void forward(int speed = max_speed);
  void reverse(int speed = max_speed);
  void stop(int speed = max_speed);
  void disable();
  void inc_pulse() { pulse_count++; }
  unsigned long get_pulse_count() const { return pulse_count; }
};
 
#endif

