#include <Arduino.h>
#include <Ps3Controller.h>

// put function declarations here:
void onConnect();

void setup() {
  Ps3.begin("A0:5A:5F:33:3B:10");
}

void loop() {
  // put your main code here, to run repeatedly:
}

void onConnect(){
  printf("Controller connected succesfully\n");
}

