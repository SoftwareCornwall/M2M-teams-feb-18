#include <ArduinoUnit.h>
#include "Robot.h"

test(TestMotorInitiallyStopped)
{
  Motor motor(1,2,3);
  assertEqual(motor.get_speed(), 0);  
}

test(TestMotorForwardSetsSpeed)
{
  Motor motor(1,2,3);
  motor.forward(75);
  assertEqual(motor.get_speed(), 75);  
}

test(TestMotorReverseSetsSpeed)
{
  Motor motor(1,2,3);
  motor.reverse(75);
  assertEqual(motor.get_speed(), 75);  
}

test(TestMotorCountsPulses)
{
  Motor motor(1,2,3);
  assertEqual(motor.get_pulse_count(), 0);
  motor.inc_pulse();  
  assertEqual(motor.get_pulse_count(), 1);  
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Test::run();

}
