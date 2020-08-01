#ifndef PERIPHS_H
#define PERIPHS_H

#include <Arduino.h>
#include <functional>

#include <Wire.h>

#include "consts.h"
#include <U8g2lib.h>
#include <Bounce2.h>
#include <Encoder.h>
#include "TCA9548A.h"

uint8_t scaleEncoder(uint16_t);

class Periphs
{
private:

public:
    Periphs();
    void initDisplays();
    void scan();

    TCA9548A oledMux;
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C * oled;

    std::function<void(uint8_t)> onButtonPressed[NUM_CONTROLLERS];
    std::function<void(uint8_t)> onEncoderChanged[NUM_CONTROLLERS];

    Bounce buttons[NUM_CONTROLLERS];
    bool buttonStates[NUM_CONTROLLERS];
    Encoder * encoders[NUM_CONTROLLERS];
    
};

#endif