#include "periphs.h"
#include <U8g2lib.h>
#include <Bounce2.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define ROTATION U8G2_R0
#define PIN_CLOCK 19
#define PIN_DATA 18
#define PIN_BUTTON 33


periphs::periphs()
{
    
    // this->oled = o;
    // this->oled.begin();
    // this->oled.drawBox(1, 1, 128, 64);
    this->debouncer = Bounce();
    this->debouncer.attach(PIN_BUTTON);
    this->debouncer.interval(5);
    this->buttonState = this->debouncer.read();
}