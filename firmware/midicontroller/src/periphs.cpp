#include "periphs.h"
#include "externs.h"

#define ROTATION U8G2_R0
#define PIN_CLOCK 19
#define PIN_DATA 18
#define PIN_BUTTON 33

Periphs periphs;


//          ---         ---         ---         ---         //

uint8_t scaleEncoder(uint16_t val)
{
    return map(val, 0, 255, 0, 127);
}


//          ---         ---         ---         ---         //
void encoderIsr()
{
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        periphs.encoders[i]->service();
    }
    // See scan() for actually doing stuff with this info.
    // Want to keep the ISR as short as can be.
}

Periphs::Periphs()
{
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
    static U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(ROTATION, /* reset=*/ U8X8_PIN_NONE);
    this->oled = &oled;
    this->oledMux.begin(Wire);
    this->initDisplays();

    this->oledMux.openAll();
    this->oled->drawStr(2, 10, "Initialising periphs");

    //  --  Set up buttons
    this->oled->drawStr(7, 20, "Attaching buttons");
    this->oled->sendBuffer();
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        this->buttons[i] = Bounce();
        this->buttons[i].interval(5);
        // this->onButtonPressed[i] = std::bind(&Periphs::encoderIsr, this);
    }
    this->buttons[0].attach(PIN_BUT_1);
    this->buttons[1].attach(PIN_BUT_2);
    this->buttons[2].attach(PIN_BUT_3);
    this->buttons[3].attach(PIN_BUT_4);
    this->oled->drawStr(110, 20, "OK!");
    this->oled->sendBuffer();

    //  --  Set up encoders
    this->oled->drawStr(7, 30, "Attaching encoders");
    this->oled->sendBuffer();
    static ClickEncoder e1(PIN_ENC_1A, PIN_ENC_1B, PIN_BUT_1, ENCODER_STEPS);   // Can't have an empty Encoder array
    static ClickEncoder e2(PIN_ENC_2A, PIN_ENC_2B, PIN_BUT_2, ENCODER_STEPS);   // so we'll instead use an array of
    static ClickEncoder e3(PIN_ENC_3A, PIN_ENC_3B, PIN_BUT_3, ENCODER_STEPS);  // pointers to static Encoders
    static ClickEncoder e4(PIN_ENC_4A, PIN_ENC_4B, PIN_BUT_4, ENCODER_STEPS);  // yeah, it's a hack. Fight me.
    this->encoders[0] = &e1;
    this->encoders[1] = &e2;
    this->encoders[2] = &e3;
    this->encoders[3] = &e4;

    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        this->encoders[i]->setAccelerationEnabled(true);
    }
    this->oled->drawStr(110, 30, "OK!");
    this->oled->sendBuffer();

    Timer1.initialize(1000);
    Timer1.attachInterrupt(encoderIsr);
}

void Periphs::initDisplays()
{
    this->oledMux.openAll();
    this->oled->begin();
    this->oled->setDrawColor(1);
    this->oled->setFont(u8g2_font_5x8_mf);
    this->oled->sendBuffer();
    this->oledMux.closeAll();
}

static bool needsRedraw[5] = {true, true, true, true, true};
void drawMockupUI(uint8_t display, uint8_t num)
{
    periphs.oledMux.closeAll();
    periphs.oledMux.openChannel(oleds[display]);
  char buf[7];
  itoa(num, buf, 10);
  if (needsRedraw[display]) {
    periphs.oled->clearDisplay();
    #ifdef UI_FRAMES
    periphs.oled->drawFrame(0, 0, 128, 64);
    periphs.oled->drawRFrame(0, -5, 128, 22, 7);
    #endif
    periphs.oled->setFont(u8g2_font_9x15_me);
    periphs.oled->drawStr(10, 13, "Chan Label");
    periphs.oled->drawFrame(8, 24, 112, 16);
    periphs.oled->setFont(u8g2_font_7x13_me); 
    periphs.oled->drawStr(3, 52, "0");
    periphs.oled->drawStr(105, 52, "127");
    periphs.oled->setFont(u8g2_font_7x13_me); 
    periphs.oled->drawStr(3, 52, "0");
    periphs.oled->drawStr(105, 52, "127");
  } else {
    periphs.oled->setDrawColor(0);
    periphs.oled->drawBox(10,25,108,13);
    periphs.oled->drawBox(60, 40, 25, 20);
    periphs.oled->setDrawColor(1);
  }


  uint8_t scaled = map(num, 0, 127, 5, 108);
  periphs.oled->drawRBox(10, 26, scaled, 12, 2); // Max width 108

  periphs.oled->setFont(u8g2_font_10x20_me);
  periphs.oled->drawStr(54, 59, buf);

  
  periphs.oled->sendBuffer();

  needsRedraw[display] = false;
}

void Periphs::scan() //TODO
{
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        uint8_t event = EVENT_NONE;
        this->buttons[i].update();
        if (this->buttons[i].fell()) {
            this->onButtonPressed[i](i);
        }

        // Encoders
        // uint8_t accumulatedTicks = this->encoders[i]->getValue();
        // if (accumulatedTicks != 0) {
        //     this->lastEncoderStates[i] = this->encoderStates[i];
        //     this->encoderStates[i] += this->encoders[0]->getValue();
        // }
    }


    // TODO: DELETE ME AND REPLACE WITH EVENT HANDLER CALLBACKS ----            -----
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {
        signed char accumulatedTicks = this->encoders[i]->getValue();
        if (accumulatedTicks != 0) {
            lastEncoderStates[i] = encoderStates[i];
            if (encoderStates[i] + accumulatedTicks >= 127) {
                digitalWrite(LED_BUILTIN, HIGH);
                encoderStates[i] = 127;
            }
            else if (encoderStates[i] + accumulatedTicks <= 0)
            {
                digitalWrite(LED_BUILTIN, HIGH);
                encoderStates[i] = 0;
            }
            else {
                this->encoderStates[i] += accumulatedTicks;
            }
            digitalWrite(LED_BUILTIN, LOW);


            drawMockupUI(i, encoderStates[i]);
        }
    }
}