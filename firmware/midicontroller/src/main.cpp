#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "consts.h"
#include "periphs.h"

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  Periphs periphs;
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  periphs.oledMux.openAll();
  periphs.oled->drawFrame(10, 10, 10, 10);
  periphs.oled->sendBuffer();
  periphs.oledMux.closeAll();

}

void loop()
{
    if (!digitalRead(PIN_BUT_3) || !digitalRead(PIN_BUT_4) || !digitalRead(PIN_BUT_1) || !digitalRead(PIN_BUT_2)) {
      digitalWrite(LED_BUILTIN, HIGH);
    }

    if (!digitalRead(PIN_ENC_1A) || !digitalRead(PIN_ENC_2A) || !digitalRead(PIN_ENC_3A) || !digitalRead(PIN_ENC_4A)) {
      digitalWrite(LED_BUILTIN, HIGH);
    }

  digitalWrite(LED_BUILTIN, LOW);
}