#include <Arduino.h>
#include <Ps3Controller.h>

#define MACADDRESS "10:06:1C:B5:A8:26"

#define MOTOR1SPEED 2
#define MOTOR1RICHTUNG 15

#define MOTOR2SPEED 32
#define MOTOR2RICHTUNG 33

#define DRIVESPEED 127
#define TURNSPEED 50

// put function declarations here:
void onConnect();
void getInput();

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR1RICHTUNG,OUTPUT);
  pinMode(MOTOR1SPEED,OUTPUT);

  pinMode(MOTOR2RICHTUNG,OUTPUT);
  pinMode(MOTOR2SPEED,OUTPUT);

  Serial.println("Connecting to Controller");
  Ps3.attachOnConnect(onConnect);
  Ps3.begin(MACADDRESS);
}

void loop() { 
  if (Ps3.isConnected())
  {
    getInput();
    delay(10);
  }
  else{
    Serial.println("Failed to connect");
  }
  
}

void onConnect(){
  printf("Controller connected succesfully\n");
}

void getInput(){
  if (Ps3.data.button.up){
  digitalWrite(MOTOR1RICHTUNG,HIGH);
  analogWrite(MOTOR1SPEED,DRIVESPEED);

  digitalWrite(MOTOR2RICHTUNG,LOW);
  digitalWrite(MOTOR2SPEED,DRIVESPEED);
  }
  if (Ps3.data.button.down){
  digitalWrite(MOTOR1RICHTUNG,LOW);
  digitalWrite(MOTOR1SPEED,DRIVESPEED);

  digitalWrite(MOTOR2RICHTUNG,HIGH);
  digitalWrite(MOTOR2SPEED,DRIVESPEED);
  }
  if (Ps3.data.button.left){
  digitalWrite(MOTOR1RICHTUNG,HIGH);
  digitalWrite(MOTOR1SPEED,TURNSPEED);

  digitalWrite(MOTOR2RICHTUNG,HIGH);
  digitalWrite(MOTOR2SPEED,TURNSPEED);
  }
  if (Ps3.data.button.right){
  digitalWrite(MOTOR1RICHTUNG,LOW);
  digitalWrite(MOTOR1SPEED,TURNSPEED);

  digitalWrite(MOTOR2RICHTUNG,LOW);
  digitalWrite(MOTOR2SPEED,TURNSPEED);
  }
}
