#include "Arduino.h"
#include "Motor.h"

namespace {
static const byte max_speed_value = 255;
}

Motor::Motor(int _enable_pin, int _forward_pin, int _reverse_pin):
  enable_pin{_enable_pin}, forward_pin{_forward_pin}, reverse_pin{_reverse_pin}
{
  pinMode(enable_pin, OUTPUT);
  pinMode(forward_pin, OUTPUT);
  pinMode(reverse_pin, OUTPUT);
  disable();
}

void Motor::set_speed(int _speed)
{
  speed = _speed;
  analogWrite(enable_pin, (speed * max_speed_value) / 100);
}

void Motor::forward(int speed)
{
  set_speed(speed);
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, LOW);
}

void Motor::reverse(int speed)
{
  set_speed(speed);
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, HIGH);
}

void Motor::stop(int speed)
{
  set_speed(speed);
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, HIGH);    
}

void Motor::disable()
{
  set_speed(0);
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, LOW);      
}
