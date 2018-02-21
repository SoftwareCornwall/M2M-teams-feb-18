#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>

HMC5883L_Simple Compass;

#define leftMotorFeedback 2
#define leftMotorEnable 9
#define leftMotorForward 8
#define leftMotorBack 7

#define rightMotorFeedback 3
#define rightMotorEnable 10
#define rightMotorBack 11
#define rightMotorForward 12

const float baseDistance = 4.63;

float heading = 0;

int rightPwmCount = 0;
int leftPwmCount = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  /*pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBack, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBack, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);
  pinMode(rightMotorFeedback, INPUT);
  pinMode(leftMotorFeedback, INPUT);*/
  digitalWrite(rightMotorFeedback, HIGH);
  digitalWrite(leftMotorFeedback, HIGH);

  attachInterrupt(digitalPinToInterrupt(2), leftMotorInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightMotorInterrupt, RISING);
  
  Compass.SetDeclination(23, 35, 'E');
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
}

void loop() {
  heading = Compass.GetHeadingDegrees();
  Serial.print("Heading: \t");
  Serial.println( heading );   
  delay(1000);
  TurnRightByDegrees(90, 100);
  HardStop();
  delay(10000);
  //Forward(10, 155);
}

void leftMotorInterrupt() {
  leftPwmCount++;
}

void rightMotorInterrupt() {
  rightPwmCount++;
}

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

void Backwards(int distance, int velocity) {
  
}

void TurnRight(int velocity){
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorBack, HIGH);
  digitalWrite(leftMotorBack, LOW);
  analogWrite(leftMotorEnable, velocity);
  analogWrite(rightMotorEnable, velocity);
}

void TurnLeft(int velocity){
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorBack, HIGH);
  digitalWrite(leftMotorBack, LOW);
  analogWrite(leftMotorEnable, velocity);
  analogWrite(rightMotorEnable, velocity);
}

void TurnRightByDegrees(int angle, int velocity) {
  int startHeading = heading;
  if ((int)startHeading + angle > 365){
    int totalTurn = angle - (heading + angle - 365);
    while (((int)heading < 365)&&((int)heading > 275)){
      checkTurnTolerance();
      Serial.println("first while");
      Serial.println((int)heading);
      TurnRight(velocity);
    }
    Serial.println("out of first while");
    while ((int)heading < totalTurn){
      checkTurnTolerance();
      Serial.println("second while");
      Serial.println(heading);
      TurnRight(velocity);      
    }
    Serial.println("out of second while");
  }
  else{
    while ((int)heading < (startHeading + angle)){
      checkTurnTolerance();
      Serial.println("third while");
      Serial.println(heading);
      TurnRight(velocity);      
    }
    Serial.println("out of else while");    
  }
}

void TurnRightByPWM(int angle, int velocity) {
  float calcDistance = (angle / 3.5) * baseDistance;
  while (rightPwmCount < calcDistance){
    Serial.println("forward");
    TurnRight(velocity);
    Serial.println(rightPwmCount);
  }
  rightPwmCount = 0;
  leftPwmCount = 0;
  HardStop();
}

void TurnLeftByPWM(int angle, int velocity) {
  float calcDistance = (angle / 3.5) * baseDistance;
  while (leftPwmCount < calcDistance){
    Serial.println("forward");
    TurnLeft(velocity);
    Serial.println(leftPwmCount);
  }
  rightPwmCount = 0;
  leftPwmCount = 0;
  HardStop();
}

void checkTurnTolerance(){
  int newHeading = Compass.GetHeadingDegrees();
  while ((newHeading < (heading - 5)) || (newHeading > (heading + 5))){
    newHeading = Compass.GetHeadingDegrees();
  }
  heading = newHeading;
}

