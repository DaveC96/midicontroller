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

DeviceModel deviceModel = { CONTROLLER_STARTUP };


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
}
