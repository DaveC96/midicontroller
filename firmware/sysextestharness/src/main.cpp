#include <Arduino.h>
#include <MIDI.h>

void onRecvSysex(byte * data, unsigned int length)
{
  digitalWrite(LED_BUILTIN, 1);
  delay(1000);
  byte buf[length];
  for (byte i = 0; i < length; i++)
  {
    buf[i] = *(data + i);
  }
  delay(1000);
  digitalWrite(LED_BUILTIN,0);
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
}