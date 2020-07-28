#ifndef PERIPHS_H
#define PERIPHS_H

#include <Arduino.h>

#include <Wire.h>

#include "consts.h"
#include <U8g2lib.h>
#include <Bounce2.h>
#include "TCA9548A.h"


class Periphs
{
private:

public:
    Periphs();
    void initDisplays();

    TCA9548A oledMux;
    bool buttonState;
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C * oled;


    Bounce buttons[NUM_CONTROLLERS];
    
};

#endif