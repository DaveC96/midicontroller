#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "consts.h"
#include "periphs.h"

// This is required to work around some known linker issues: https://forum.pjrc.com/threads/57192-Teensy-4-0-linker-issues-with-STL-libraries
extern "C"{
  int __exidx_start(){ return -1;}
  int __exidx_end(){ return -1; }
  int _write(){ return -1; }
}

Periphs periphs;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

static uint8_t lastPos[4];
void loop()
{
  // periphs.scan();
  for (uint8_t i = 0; i < 4; i++) { periphs.buttons[i].update(); }  // In the meantime...


  periphs.oledMux.closeAll();
  for (uint8_t i = 0; i < 4; i++) {
    uint8_t x = -periphs.encoders[i]->read();
    if (x != lastPos[i]) {
      periphs.oledMux.openChannel(oleds[i]);
      periphs.oled->clearBuffer();
      periphs.oled->drawBox(x, 20, 15, 15);
      periphs.oled->sendBuffer();
      periphs.oledMux.closeChannel(oleds[i]);
      lastPos[i] = x;
    }

    if (periphs.buttons[i].fell()) {
      periphs.encoders[i]->write(0);
    }
  }
}
