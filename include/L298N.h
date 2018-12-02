#pragma once

#include <Arduino.h>

class L298N {
private:
    uint8_t pin_FWD;
    uint8_t pin_BWD;
    uint8_t pin_EN;
    uint8_t pwm;
public:
    static const uint8_t FORWARD = 0;
    static const uint8_t BACKWARD = 1;
    void init(uint8_t pin_FWD, uint8_t pin_BWD, uint8_t pin_EN);
    void setPwm(uint8_t pwm, uint8_t dir);
    ~L298N();
};