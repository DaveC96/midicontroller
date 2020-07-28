#include "periphs.h"


#define ROTATION U8G2_R0
#define PIN_CLOCK 19
#define PIN_DATA 18
#define PIN_BUTTON 33


Periphs::Periphs()
{
    static U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R2, /* reset=*/ U8X8_PIN_NONE);

    this->oled = &oled;

    pinMode(PIN_BUT_1, INPUT_PULLUP);
    pinMode(PIN_BUT_2, INPUT_PULLUP);
    pinMode(PIN_BUT_3, INPUT_PULLUP);
    pinMode(PIN_BUT_4, INPUT_PULLUP);
    pinMode(PIN_ENC_1A, INPUT_PULLUP);
    pinMode(PIN_ENC_1B, INPUT_PULLUP);
    pinMode(PIN_ENC_2A, INPUT_PULLUP);
    pinMode(PIN_ENC_2B, INPUT_PULLUP);
    pinMode(PIN_ENC_3A, INPUT_PULLUP);
    pinMode(PIN_ENC_3B, INPUT_PULLUP);
    pinMode(PIN_ENC_4A, INPUT_PULLUP);
    pinMode(PIN_ENC_4B, INPUT_PULLUP);

    Wire.begin();
    this->oledMux.begin(Wire);
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        this->buttons[i] = Bounce();
        this->buttons[i].interval(5);
    }
    this->buttons[0].attach(PIN_BUT_1);
    this->buttons[1].attach(PIN_BUT_2);
    this->buttons[2].attach(PIN_BUT_3);
    this->buttons[3].attach(PIN_BUT_4);


    // this->buttonState = this->debouncer[0].read();

    this->initDisplays();
}

void Periphs::initDisplays()
{
    this->oledMux.openAll();
    this->oled->begin();
    this->oled->setDrawColor(1);
    this->oled->sendBuffer();
    this->oledMux.closeAll();
}