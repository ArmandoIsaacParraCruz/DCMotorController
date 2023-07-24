#include <Arduino.h>
#include "DCMotorController.h"

DCMotorController motor(23);
void setup() {
  Serial.begin(115200);
  motor.setEncoderPins(2,3);
}

void loop() {
   
}