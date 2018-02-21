class robot_functions{
  public:
    void lights_on{
      digitalWrite(light_l, HIGH)
      digitalWrite(light_r, HIGH)
    }
    void lights_off{
      digitalWrite(light_l, LOW)
      digitalWrite(light_r, LOW)
    }
    void square{
      Forward();
      delay(3000);
      turnLeft();
      Forward();
      delay(3000);
      turnLeft();
      delay(3000);
      Forward();
      delay(3000);
      turnLeft();
    }
    void light_beacon{
    leftLight = analogRead(light_sensor_l);
    middleLight = analogRead(light_sensor_m);
    rightLight = analogRead(light_sensor_r);
    delay(500);
    if (leftLight < middleLight&& leftLight < rightLight{
      turnLeft();
    }
    else if(middleLight < leftLight && middleLight < rightLight)
      Forward();
    }
    else if (rightLight < leftLight && rightLight < middleLight){
      turnRight();
    }
    else{
      
    }
    void cliff_edge{
      pinMode(triggerDown, OUTPUT);
      digitalWrite(triggerDown, LOW);
      delayMicroseconds(2);
      digitalWrite(triggerDown, HIGH);
      delayMicroseconds(5);
      digitalWrite(triggerDown, LOW);
      pinMode(echoDown, INPUT);
      duration = pulseIn(echoDown, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      if(cm>9){
        hardStop();
        delay(1000);
        Reverse();
        hardStop();
        turnRight();
      }
      
    }
    void wall{
      pinMode(triggerForward, OUTPUT);
      digitalWrite(triggerForward, LOW);
      delayMicroseconds(2);
      digitalWrite(triggerForward, HIGH);
      delayMicroseconds(5);
      digitalWrite(triggerForward, LOW);
      pinMode(echoForward, INPUT);
      duration = pulseIn(echoForward, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      if(cm>10){
        hardStop();
        delay(1000);
        Reverse();
        hardStop();
        turnLeft();
      }
    }
  private:
    const int right_activate = 10; //analogue
    const int left_activate = 9; //analogue
    const int right_forward = 12; //digital
    const int right_reverse = 11; //digital
    const int left_forward = 8; //digital
    const int left_reverse = 7; //digital
    const int light_sensor_l = 7; //analogue
    const int light_sensor_m = 6; //analogue
    const int light_sensor_r = 2; //analogue
    const int light_l = 14; //digital
    const int light_r = 15; //digital
    const float cm_pulse = 4.63; //
    const int echoDown = 17; //digital
    const int triggerDown = 13;//digital
    int counter;
    const int triggerForward = 4;
    const int echoForward = 5;
    long duration;
    long cm;
    long inches; 
    
}; 
    

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
