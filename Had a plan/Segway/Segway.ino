#include <PID_v1.h>

#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

const int leftENA = 9;
const int leftIN1 = 8;
const int leftIN2 = 7;
const int rightENB = 10;
const int rightIN3 = 12;
const int rightIN4 = 11;


void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
  
  //initialize the variables we're linked to
  Input = analogRead(0);
  Setpoint = -49;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);

  
  pinMode(leftENA, OUTPUT);
  pinMode(leftIN1, OUTPUT);
  pinMode(leftIN2, OUTPUT);
  pinMode(rightENB, OUTPUT);
  pinMode(rightIN3, OUTPUT);
  pinMode(rightIN4, OUTPUT);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  

  
  Input = AcY / 100;

  double gap = abs(Setpoint-Input); //distance away from setpoint
  if(gap<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID.SetTunings(aggKp, aggKi, aggKd);
  }
 
  
  myPID.Compute();
  Serial.print(Input);
  /*
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.print(AcZ); 
  
  Serial.print(" Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.print(GyZ);
//  Serial.println(" ");
*/
  Serial.print(" PID: ");
  Serial.print("AcY = "); Serial.print(Output);
  
  if(Output > 0) {
    analogWrite(leftENA, Output);
    digitalWrite(leftIN1, HIGH);
    digitalWrite(leftIN2, LOW);
    digitalWrite(rightIN3, HIGH);
    digitalWrite(rightIN4, LOW);
    analogWrite(rightENB, Output);
    Serial.print("Forward");
  } else if(Output < 0) {
    analogWrite(rightENB, Output * -1);
    digitalWrite(leftIN1, LOW);
    digitalWrite(leftIN2, HIGH);
    digitalWrite(rightIN3, LOW);
    digitalWrite(rightIN4, HIGH);
    analogWrite(leftENA, Output * -1);
    Serial.print("Backward");
  } else {
    analogWrite(leftENA, 0);
    analogWrite(rightENB, 0);
  }
  Serial.println(" ");
  
  delay(1000 / 100);
}
