#include <Arduino.h>
#include "DCMotorController.h"

DCMotorController motor(23);
void setup() {
  Serial.begin(115200);
  
}

void loop() {
   motor.startMotor();
   delay(3000);
   motor.stopMotor();
   delay(3000);
}