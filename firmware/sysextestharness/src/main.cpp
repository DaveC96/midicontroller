#include <Arduino.h>
#include <MIDI.h>
#include "sysexmessaging.h"

void onRecvSysex(byte * data, unsigned int length)
{
  digitalWrite(LED_BUILTIN, 1);
  byte buf[length];
  for (byte i = 0; i < length; i++)
  {
    buf[i] = *(data + i);
  }
  digitalWrite(LED_BUILTIN, 0);
  usbMIDI.sendSysEx(length, buf, true);
}

void setup() {
  usbMIDI.setHandleSystemExclusive(onRecvSysex);
  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LED_BUILTIN, 1);
    delay(100);
    digitalWrite(LED_BUILTIN, 0);
    delay(50);
  }
}

void loop() {
  usbMIDI.read();
  // uint8_t * pkt;
  // pkt = generateConfigRequest(0);
  // usbMIDI.sendSysEx(sizeof(pkt)/sizeof(uint8_t *), pkt[0], true);
}