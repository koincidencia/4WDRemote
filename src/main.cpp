#include <Arduino.h>
#include "L298N.h"

L298N leftMotor;
L298N rightMotor;

void setup() {
  Serial.begin(115200);
  leftMotor.init(4, 2, 3);
  rightMotor.init(6, 7, 5);
}

uint8_t cntr = 255;
uint8_t state = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Ping");
  switch(state) {
    case 0:
      leftMotor.setPwm(cntr, L298N::FORWARD);
      rightMotor.setPwm(cntr, L298N::FORWARD);
      if (cntr == 0) {
        state = 1;
        cntr = 255;
      }
      break;
    case 1:
      leftMotor.setPwm(cntr, L298N::BACKWARD);
      rightMotor.setPwm(cntr, L298N::BACKWARD);
      if (cntr == 0) {
        state = 0;
        cntr = 255;
      }
      break;
    default:
      state = 0;
      break;
  }
  cntr--;
  delay(20);
}
