#include <Arduino.h>
#include "L298N.h"

L298N leftMotor;
L298N rightMotor;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(500);
  Serial.println("Serial port initialized");
  leftMotor.init(4, 2, 3);
  rightMotor.init(6, 7, 5);
  Serial.println("PWM objects initialized");
}

long command;
uint8_t pwmL, pwmR, dirL, dirR;

void loop() {
  command = Serial.parseInt();
  
  pwmL = command & 0xFF;
  Serial.print("pwmL:");
  Serial.println(pwmL);
  pwmR = (command >> 8) & 0xFF;
  Serial.print("pwmR:");
  Serial.println(pwmR);
  dirL = (command >> 16) & 0x01;
  Serial.print("dirL:");
  Serial.println(dirL);
  dirR = (command >> 17) & 0x01;
  Serial.print("dirR:");
  Serial.println(dirR);

  leftMotor.setPwm(pwmL, dirL);
  rightMotor.setPwm(pwmR, dirR);
}
