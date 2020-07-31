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


class Periphs
{
private:

public:
    Periphs();
    void initDisplays();
    void scan();

    void testCallback();
    void (* callback)();

    TCA9548A oledMux;
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C * oled;

    std::function<void()> onButtonPressed[NUM_CONTROLLERS];

    Bounce buttons[NUM_CONTROLLERS];
    bool buttonStates[NUM_CONTROLLERS];
    Encoder * encoders[NUM_CONTROLLERS];
    
};

#endif