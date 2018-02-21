int volatile left = 152;
int volatile right = 150;
int lL = 0;
int lM = 0;
int lR = 0;
void setup() {
    #define triggerb 4
    #define echob 5
    #define trigger 13//4
    #define echo 17//5
    #define left 8 //yellow left LED pin 5
    #define right 12 //green LED pin 4
    #define leftb 7
    #define rightb 11
    #define lefta 9
    #define righta 10
    #define button1 2 //left
    #define button2 3 //right
    #define lightL 7
    #define lightM 6
    #define lightR 2
    
    Serial.begin(9600);

    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(leftb, OUTPUT);
    pinMode(rightb, OUTPUT);
    pinMode(left, OUTPUT);   
    pinMode(right, OUTPUT);
    pinMode(lefta, OUTPUT);
    pinMode(righta, OUTPUT); //trigger and echo for ultra sonic 
    pinMode(trigger,OUTPUT);
    pinMode(echo,INPUT);
    
    digitalWrite(button1, HIGH);
    digitalWrite(button2, HIGH);
    

}
void cliff(){
   long duration, distanceCm, distanceIn;
   //pulses
   //distanceCm = 1;
   digitalWrite(trigger, LOW);
   delayMicroseconds(2);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   //echo 
   duration = pulseIn(echo,HIGH);
   // convert the time into a distance
   distanceCm = duration / 29.1 / 2 ;
   distanceIn = duration / 74 / 2;
   Serial.print(distanceCm);
   Serial.print("cm");
   /*if (distanceCm <= 0 || distanceCm >= 100){
    Serial.println("Out of range");
    Serial.print(distanceCm);
    Serial.print("cm");
    }*/
   if (distanceCm <= 10){
    Serial.println("forward");
    Serial.print(distanceCm);
    Serial.print("cm");
    forward(100);
   }
   else if (distanceCm > 13){
    Serial.print("stop");
    Serial.print(distanceCm);
    Serial.print("cm");
    stop_();
    delay(1000);
    switch_ = 1;
   }
   else {
    Serial.print(distanceCm);
    Serial.print("cm");
    Serial.println();
   }

   }
   else if(switch_ == 1){
    reverse(5000);
    Serial.print("switched");
    delay(2000);
   }
}   

void forward(int value){
  Serial.println("forward");
  analogWrite(righta, 150);
  analogWrite(lefta, 152);
  digitalWrite(left,HIGH); //255
  digitalWrite(right,HIGH); //255
  digitalWrite(leftb, LOW);
  digitalWrite(rightb, LOW);
  delay(value);
  stop_();
}


void reverse(int value){
      Serial.println("reverse");
      analogWrite(lefta, 152);
      analogWrite(righta, 150);
      digitalWrite(leftb, HIGH);
      digitalWrite(rightb, HIGH);
      digitalWrite(left, LOW);
      digitalWrite(right, LOW);
      delay(value);
      stop_();
}
void rturn(int value){
  Serial.println("rturnr");
  analogWrite(lefta,152);
  analogWrite(righta,150);
  digitalWrite(left, LOW);
  digitalWrite(rightb, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(leftb, HIGH);
  delay(value);
  stop_();
  }
void rturnl(int value){
  Serial.println("turnl");
  analogWrite(lefta,152);
  analogWrite(righta,150);
  digitalWrite(left, HIGH);
  digitalWrite(rightb, HIGH);
  digitalWrite(right, LOW);
  digitalWrite(leftb, LOW);
  delay(value);
  stop_();
  }

void turn(int value){
  Serial.println("turnr");
  analogWrite(lefta,152);
  analogWrite(righta,150);
  digitalWrite(left, HIGH);
  digitalWrite(rightb, HIGH);
  digitalWrite(right, LOW);
  digitalWrite(leftb, LOW);
  delay(value);
  stop_();
  }

void turnl(int value){
  Serial.println("turnl");
  analogWrite(lefta,152);
  analogWrite(righta,150);
  digitalWrite(left, LOW);
  digitalWrite(rightb, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(leftb, HIGH);
  delay(value);
  stop_();
  }

void stop_(){
  Serial.println("stop");
  analogWrite(lefta, 0);
  analogWrite(righta, 0);
  //digitalWrite(lefta, LOW);
  //digitalWrite(righta, LOW);
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
  digitalWrite(leftb, LOW);
  digitalWrite(rightb, LOW);
  }
void light(){
  delay(1000);
  lL = analogRead(lightL);
  lM = analogRead(lightM);
  lR = analogRead(lightR);
  Serial.println(lL);
  Serial.println(lM);
  Serial.println(lR);
}
void follow_light(){
  light();
   delay(500); 
   if (lL < lM && lL < lR){
    turnl(500);
   }
   else if (lM < lL && lM < lR){
    forward(500);
   }
   else if(lR < lL && lR < lM){
    turn(500);
   }
   else{
    
   }
}

void loop() {
   
}
   
   /*int difference=counterright-counterleft;
   if (difference <= 0){ 
    right+difference;
    }
    else {
      left+difference;
      }
      */
      
   //forward 8 
     
   
   

/*void foward_back_foward() {
   digitalWrite(lefta, HIGH);
   digitalWrite(righta, HIGH);
   digitalWrite(left, HIGH);
   digitalWrite(right, HIGH);
   delay(1000);
   digitalWrite(lefta, LOW);
   digitalWrite(righta, LOW);
   digitalWrite(left, LOW);
   digitalWrite(right, LOW);
   delay(1000);
   digitalWrite(lefta, HIGH);
   digitalWrite(righta, HIGH);
   digitalWrite(leftb, HIGH);
   digitalWrite(rightb, HIGH);     
   delay(1000);
   digitalWrite(lefta, LOW);
   digitalWrite(righta, LOW);
   digitalWrite(leftb, LOW);
   digitalWrite(rightb, LOW);
   delay(1000);
}*/

/*void setup() {
    #define red 4 //red LED pin 3
    #define yellow 5 //yellow left LED pin 5
    #define green 3 //green LED pin 4
    #define yellow2 2 //yellow right LED pin 2 
    pinMode(red, OUTPUT);
    pinMode(yellow,OUTPUT);
    pinMode(yellow2,OUTPUT);
    pinMode(green, OUTPUT);
}*/

/*void reverse_lights{
   digitalWrite(green, HIGH);
   delay(10000);
   digitalWrite(green, LOW);
   digitalWrite(red, HIGH);
   delay(1000);
   digitalWrite(red, LOW);
   digitalWrite(yellow, HIGH);
   digitalWrite(yellow2, HIGH);
   delay(1000);
   digitalWrite(yellow, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(red, HIGH);
   delay(1000);
   digitalWrite(red, LOW);
}*/

/*void LED_Blink (){
  //setup
  #define LED_1 3 // 
  #define LED_2 4 //
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  //loop
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);   
  delay(1000);                       
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);     
  delay(1000); 
}*/

