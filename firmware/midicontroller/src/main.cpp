#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <string>
#include "externs.h"
#include "consts.h"
#include "periphs.h"
#include "model_device.h"
#include "controller_session.h"

// This is required to work around some known linker issues: https://forum.pjrc.com/threads/57192-Teensy-4-0-linker-issues-with-STL-libraries
extern "C"{
  int __exidx_start(){ return -1;}
  int __exidx_end(){ return -1; }
  int _write(){ return -1; }
}

Periphs periphs;
DeviceModel deviceModel = { CONTROLLER_STARTUP };

static bool needsRedraw[5] = {true, true, true, true, true};
void drawMockupUI(uint8_t display, uint8_t num)
{
  char buf[7];
  itoa(num, buf, 10);
  if (needsRedraw[display]) {
    periphs.oled->clearDisplay();
    #ifdef UI_FRAMES
    periphs.oled->drawFrame(0, 0, 128, 64);
    periphs.oled->drawRFrame(0, -5, 128, 22, 7);
    #endif
    periphs.oled->setFont(u8g2_font_9x15_me);
    periphs.oled->drawStr(10, 13, "Test Layer 2");
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

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  cSession::init();
}

static uint8_t lastPos[4];
void loop()
{
  periphs.scan();
  for (uint8_t i = 0; i < 4; i++) { periphs.buttons[i].update(); }  // In the meantime...


  periphs.oledMux.closeAll();
  for (uint8_t i = 0; i < 4; i++) {
    uint8_t x = -periphs.encoders[i]->read();
    if (x != lastPos[i]) {
      periphs.oledMux.openChannel(oleds[i]);
      drawMockupUI(i, scaleEncoder(x));
      periphs.oledMux.closeChannel(oleds[i]);
      lastPos[i] = x;
    }

    if (periphs.buttons[i].fell()) {
      periphs.encoders[i]->write(0);
    }
  }
}
