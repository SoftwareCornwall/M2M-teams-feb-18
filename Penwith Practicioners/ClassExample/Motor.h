#include <Arduino.h>
#include <ArduinoUnit.h>

class Motor
{
  private:
    int leftMotorFeedback 2
    int leftMotorEnable 9
    int leftMotorForward 8
    int leftMotorBack 7
    
    int rightMotorFeedback 3
    int rightMotorEnable 10
    int rightMotorBack 11
    int rightMotorForward 12
    
    const float baseDistance = 4.63;
    
    int rightPwmCount = 0;
    int leftPwmCount = 0;
  public:
    void HardStop() {
      digitalWrite(rightMotorForward, LOW);
      digitalWrite(leftMotorForward, LOW);
      digitalWrite(rightMotorBack, LOW);
      digitalWrite(leftMotorBack, LOW);
      analogWrite(leftMotorForward, 0);
      analogWrite(rightMotorForward, 0);
      analogWrite(leftMotorBack, 0);
      analogWrite(rightMotorBack, 0);
    }

    void Forward(float distance, int velocity) {
      float calcDistance = distance * baseDistance;
      while (rightPwmCount < calcDistance || leftPwmCount < calcDistance){
        Serial.println("forward");
        digitalWrite(rightMotorForward, HIGH);
        digitalWrite(leftMotorForward, HIGH);
        digitalWrite(rightMotorBack, LOW);
        digitalWrite(leftMotorBack, LOW);
       
        if (rightPwmCount == leftPwmCount){
          analogWrite(leftMotorEnable, velocity);
          analogWrite(rightMotorEnable, velocity);
        }
        else if (rightPwmCount < leftPwmCount){
          int leftV = velocity-1;
          int rightV = velocity;
          analogWrite(leftMotorEnable, leftV);
          analogWrite(rightMotorEnable, rightV);
          Serial.println(leftV);
          Serial.println(rightV); 
          delay(1000);     
        }
        else if (leftPwmCount < rightPwmCount){
          int leftV = velocity;
          int rightV = velocity-1;
          analogWrite(leftMotorEnable, leftV);
          analogWrite(rightMotorEnable, rightV); 
          Serial.println(leftV);
          Serial.println(rightV);
          delay(1000);      
        }
        Serial.println(rightPwmCount);
      }
      rightPwmCount = 0;
      leftPwmCount = 0;
      HardStop();
    }    

}
