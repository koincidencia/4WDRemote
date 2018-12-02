#include "L298N.h"

void L298N::init(uint8_t pin_FWD, uint8_t pin_BWD, uint8_t pin_EN) {
    this->pin_EN = pin_EN;
    this->pin_FWD = pin_FWD;
    this->pin_BWD = pin_BWD;
    this->pwm = 0;

    pinMode(pin_EN, OUTPUT);
    pinMode(pin_FWD, OUTPUT);
    pinMode(pin_BWD, OUTPUT);
}

void L298N::setPwm(uint8_t pwm, uint8_t dir) {
    if (dir == FORWARD) {
        digitalWrite(pin_BWD, LOW);
        digitalWrite(pin_FWD, HIGH);
    } else {
        digitalWrite(pin_FWD, LOW);
        digitalWrite(pin_BWD, HIGH);
    }
    this->pwm = pwm;
    analogWrite(pin_EN, pwm);
}

L298N::~L298N() {
    pinMode(pin_EN, INPUT);
    pinMode(pin_FWD, INPUT);
    pinMode(pin_BWD, INPUT);
}

