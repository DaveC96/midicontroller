#ifndef PERIPHS_H
#define PERIPHS_H

#include <U8g2lib.h>
#include <Bounce2.h>

class periphs
{
private:

public:
    periphs();
    // U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled;
    bool buttonState;
    Bounce debouncer;
};

#endif