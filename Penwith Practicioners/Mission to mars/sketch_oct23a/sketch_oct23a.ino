#include <ArduinoUnit.h>


const int left_light =   13;    
const int right_light =  14;    

const int right_activate = 10; 
const int right_forward =  12; 
const int right_reverse =  11;  
    
const int left_activate =  9;   
const int left_forward =   8;   
const int left_reverse =   7; 
    
const int left_pulse = 2 ;
const int right_pulse = 3 ;
    
int rPulse, lPulse, sLPulse, sRPulse;
const float cm_pulse = 4.63;

int right_speed = 170;
int left_speed = 170;

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(left_pulse), counter_left, RISING);
  attachInterrupt(digitalPinToInterrupt(right_pulse), counter_right, RISING);
  
  //straight(200);
  
}

void testOutputToInput(int out, int in) {
    pinMode(out, OUTPUT);
    pinMode(in, INPUT);

    int cycleCount = 2;
    int cycleLength = 2;
    int cycle[] = { HIGH, LOW };

    for (int i = 0; i < cycleCount; i++) {
        for (int j = 0; j < cycleLength; j++) {
            digitalWrite(out, cycle[j]);
            assertEqual(cycle[j], in);
        }
    }
}

void testPulse(int pulse, int counter) {
    testOutputToInput(pulse, counter);   
}

test(left) {
    testPulse(left_pulse, counter_left);
}

void loop() {
  Serial.print("hello");
  analogForward(175, 175);
  delay(1000);
  straight_line();
  delay(4000);
  straight_line();
  delay(4000);
  hardStop();
  while (true); 
  
}

void counter_left(){
  lPulse++;
  sLPulse++;
  
}

void counter_right(){
  rPulse++;
  sRPulse++;
  
}



/*void straight(int distance) {
  Forward();
  float pulseDistance = cm_pulse * (float) distance;
  Serial.println(pulseDistance);

  while((lPulse < pulseDistance) || (rPulse < pulseDistance)){
    Serial.println(lPulse);
    Serial.println(rPulse);
    if ((sLPulse) == (sRPulse))
    { 
      Serial.println("I'm moving forward");
      delay(100);
    }    
    else if((sLPulse) > (sRPulse))
    {
       sRPulse = 0;
       sLPulse = 0;
       left_speed = left_speed - 1;
       right_speed = right_speed + 1;
       analogWrite(right_activate,right_speed);
       analogWrite(left_activate,left_speed);
       Serial.println("Im reducing Left Motor");
       delay(100);
    }
    else if((sLPulse) < (sRPulse))
    {
       sRPulse = 0;
       sLPulse = 0;
       right_speed = right_speed - 1;
       left_speed = left_speed + 1;
       analogWrite(left_activate,left_speed);
       analogWrite(right_activate,right_speed);
       Serial.println("I'm reducing Right Motor");
       delay(100);
    }
  }
  hardStop();
  delay(1000);
}
*/
void story_five() {
  analogForward(175, 175);
  delay(1000);
  straight_line();
  delay(4000);
  straight_line();
  delay(4000);
  hardStop();
  while (true);
}
void straight_line() {
  ratio_calc();
}

void ratio_calc() {

  if (lPulse > rPulse) {
    float pulse, motor_l;

    pulse = ((float)rPulse / (float)lPulse);
    motor_l = ((float)pulse * (float)175);
    Serial.println(motor_l);
    analogForward(motor_l, 175);


  }

  if (rPulse > lPulse) {
    float pulse, motor_r;

    pulse = ((float)lPulse / (float)rPulse);
    motor_r = ((float)pulse * (float)175);
    Serial.println(motor_r);
    analogForward(175, motor_r);
  }
}


void hardStop(){
  digitalWrite(left_forward, HIGH);
  digitalWrite(right_forward, HIGH);
  digitalWrite(left_reverse, HIGH);
  digitalWrite(right_reverse, HIGH);
  delay(500);
  digitalWrite(left_forward, LOW);
  digitalWrite(right_forward, LOW);
  digitalWrite(left_reverse, LOW);
  digitalWrite(right_reverse, LOW);
  
}
void analogForward(float motorpwm_l, float motorpwm_r) {
  digitalWrite(right_forward, HIGH);
  digitalWrite(left_forward, HIGH);
  Serial.println("right");
  Serial.println(motorpwm_r);
  Serial.println("left");
  Serial.println(motorpwm_l);
  analogWrite(right_activate, motorpwm_r);
  analogWrite(left_activate, motorpwm_l);
}

/*void Forward() {
 analogWrite(left_activate, 170);
 analogWrite(right_activate, 170);
 analogWrite(left_light,200);//LED
 digitalWrite(left_forward, HIGH);
 digitalWrite(right_forward, HIGH);
 digitalWrite(left_reverse, LOW);
 digitalWrite(right_reverse, LOW);
 digitalWrite(left_light, HIGH);
 Serial.println("im going");
}
*/
