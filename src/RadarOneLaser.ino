#include <Servo.h>
#define laser 8
#define trig 13
#define echo 12

Servo motorRadar;
Servo motorHorizontal;
Servo motorVertical;

float duration=0, distance=0;
int angle=0;
bool safeMode=0;
int ok=0;

void setup() {
  motorRadar.attach(11);
  motorVertical.attach(10);
  motorHorizontal.attach(9);
  
  pinMode (laser, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  safeMode = true;
  ok=0;
  for(angle = 15; angle <= 165; angle += 2){
    motorRadar.write(angle);
    if(checkRadar() < 30){
      if(ok==0)
       moveLaser();
      ok = 1;
    }
    else ok = 0;
    delay(60); 
  }

  if (safeMode == true)
    digitalWrite(laser, LOW);

  safeMode = true;
  ok=0;
  for(angle = 165; angle >= 15; angle -= 2){
    motorRadar.write(angle);
    if(checkRadar() < 30){
      if(ok==0)
       moveLaserback();
      ok = 1;
    }
    else ok = 0;
    delay(60);
  }

  if (safeMode == true)
    digitalWrite(laser, LOW);
}

int checkRadar(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = 0.017 * duration;

  return distance;
}

void moveLaser(){
  safeMode = false;
  digitalWrite(laser, HIGH);
  motorHorizontal.write(angle+30);
  motorVertical.write(0);
}

void moveLaserback(){
  safeMode = false;
  digitalWrite(laser, HIGH);
  motorHorizontal.write(angle-30);
  motorVertical.write(0);
}

