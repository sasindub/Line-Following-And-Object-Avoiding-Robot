
#include<NewPing.h>

int anl1 = 10;  
int anl2 = 11;  
int MOTOR_Lr = 13; 
int MOTOR_Ll = 12; 
int MOTOR_Rr = 8; 
int MOTOR_Rl = 9;

int i ;
int r;


int RIGHT = 7;
int LEFT = 6; 
int MID = 1;

int led = 2;

#define TRIG 5 
#define ECHO 4 
#define MAX_DISTANCE 100

NewPing sonar(TRIG, ECHO, MAX_DISTANCE); 

void setup() {
  // put your setup code here, to run once:
  
pinMode(anl1, OUTPUT); 
pinMode(anl2, OUTPUT); 
pinMode(MOTOR_Rr, OUTPUT); 
pinMode(MOTOR_Rl, OUTPUT); 
pinMode(MOTOR_Lr, OUTPUT); 
pinMode(MOTOR_Ll, OUTPUT); 
pinMode(RIGHT, INPUT); 
pinMode(LEFT, INPUT);
pinMode(MID, INPUT);
pinMode(led, OUTPUT);

Serial.begin(9600);


}

void loop() {
   digitalWrite(led,LOW);
 
  int distance = sonar.ping_cm();
  




  
 if (digitalRead(RIGHT)==HIGH && digitalRead(LEFT)==HIGH)
 {
//      delay(70);
      if (distance == 0) 
      {
      distance = 30;
      }
       if(distance > 20 && distance < 30)
       {
         for(int a = 0; a<1; a++){
              Serial.println("done it") ;
        Serial.println(distance) ;
        digitalWrite(led,HIGH);
        turnAround();
          delay(1400);
         } 
          

   while(digitalRead(RIGHT)==LOW && digitalRead(LEFT)== LOW){
      moveForwardLast();
      }
          turnRight(); 
          delay(200);

          moveForwardLast();
          delay(300);
          
     
       }else if(distance > 30 && distance < 70){
          
          Serial.println(distance) ;
           
           Stop(); 
           delay(500); 
            
            if(r == 0){
              r = r + 1;
              turnLeft();
              Serial.print("left ") ;
              Serial.println(r) ;
              delay(1000);
               

              }else if(r == 1){
                r = r + 1;
                moveForward();
                Serial.print("fo ") ;
                Serial.println(r) ;
                 delay(200);
                 
                }else if(r == 2){
                  r = 0;
                  turnRight();
                  Serial.print("Ri ") ;
                  Serial.println(r) ;
                  delay(1000);
                  
                  }
        }
        else if(distance > 70)
        {
          Stop();
        
         }
      
  }
  else
  {

    delay(70);

      if (distance == 0) {
        distance = 30;
      }
    if(distance <=20 && distance > 1) {
      Serial.println("exit turn") ;
      for(int a = 0; a<1; a++){
      digitalWrite(led,HIGH);
      Stop();
      delay(100);
      turnRight();
      delay(700);
      moveForward();
      delay(350);
      turnLeft();
      delay(700);
      moveForward();
      delay(250);
      
      Stop();
      delay(100);
      
      turnLeft();
      delay(500);

      while(digitalRead(RIGHT)==LOW && digitalRead(LEFT)== LOW){
      moveForwardLast();
      }
      Stop();
      delay(100);

      
       turnRight();
      delay(150); 

      }

      }else{

Serial.println("else") ;

if (digitalRead(RIGHT)==LOW && digitalRead(LEFT)==LOW) {

  i = i + 1;
  if(i > 20){
     analogWrite(anl1, 150);
  analogWrite(anl2, 150);
    }else{
      analogWrite(anl1, 100);
  analogWrite(anl2, 100);
        }
  
  digitalWrite(MOTOR_Rr, HIGH);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, HIGH);
  digitalWrite(MOTOR_Lr, LOW);



}else if (digitalRead(RIGHT)== LOW && digitalRead(LEFT)== HIGH) {
  i=0;


  analogWrite(anl1, 255);
  analogWrite(anl2,  255);
   digitalWrite(MOTOR_Rr, HIGH);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, LOW);
  digitalWrite(MOTOR_Lr, LOW);
 

}else if (digitalRead(RIGHT)==HIGH && digitalRead(LEFT)==LOW) {
  i=0;

  analogWrite(anl1, 255);
  analogWrite(anl2, 255);
   digitalWrite(MOTOR_Rr, LOW);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, HIGH);
  digitalWrite(MOTOR_Lr, LOW);
  
  
}else if (digitalRead(RIGHT)==HIGH && digitalRead(LEFT)==HIGH) {
// i=0;
// if(distance <=15){
//  turnAround();
//  }else{
//     Stop(); 
//    }
// 
 
}

  Serial.println("exit") ;

      }

}
}
void Stop() {
  analogWrite(anl1, 0);
  analogWrite(anl2, 0);
  digitalWrite(MOTOR_Rr, LOW);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Lr, LOW);
  digitalWrite(MOTOR_Ll, LOW);
}

void turnRight() {
  analogWrite(anl1, 255);
  analogWrite(anl2, 255);
   digitalWrite(MOTOR_Rr, LOW);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, HIGH);
  digitalWrite(MOTOR_Lr, LOW); 
  
}

void turnLeft() {
 analogWrite(anl1, 255);
  analogWrite(anl2, 255);
   digitalWrite(MOTOR_Rr, HIGH);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, LOW);
  digitalWrite(MOTOR_Lr, LOW);
}

void moveForward() {
  analogWrite(anl1, 250);
  analogWrite(anl2, 250);
  digitalWrite(MOTOR_Rr, HIGH);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, HIGH);
  digitalWrite(MOTOR_Lr, LOW);
}

void moveForwardLast() {

        analogWrite(anl1, 90);
  analogWrite(anl2, 90);
  digitalWrite(MOTOR_Rr, HIGH);
  digitalWrite(MOTOR_Rl, LOW);
  digitalWrite(MOTOR_Ll, HIGH);
  digitalWrite(MOTOR_Lr, LOW);
      


    
}

void turnAround(){
  analogWrite(anl1, 250);
  analogWrite(anl2, 250);
  digitalWrite(MOTOR_Rr, LOW);
  digitalWrite(MOTOR_Rl, HIGH);
  digitalWrite(MOTOR_Ll,  LOW);
  digitalWrite(MOTOR_Lr, LOW);
  }
