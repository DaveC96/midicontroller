#include <Arduino.h>
#include <MIDI.h>
#include "sysexmessaging.h"
#include "periphs.h"
#include "controllermodel.h"
#include <U8g2lib.h>
#include <string.h>
#include <vector>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// This is required to work around some known linker issues: https://forum.pjrc.com/threads/57192-Teensy-4-0-linker-issues-with-STL-libraries
extern "C"{
  int __exidx_start(){ return -1;}
  int __exidx_end(){ return -1; }
  int _write(){ return -1; }
}

periphs Periphs;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R2, /* reset=*/ U8X8_PIN_NONE);

void slice_str(char * str, char * buffer, size_t start, size_t end)
{
  int j = 0;
  for (int i = start; i <= end; i++) {
    buffer[j] = str[i];
    j++;
  }
  buffer[j] = 0;
}

std::vector<uint8_t> getName(uint8_t * data)  // Pass a pointer to the pre-string length byte
{
  std::vector<uint8_t> buffer;
  buffer.reserve(data[0]);
  for (uint8_t i = 1; i <= data[0]; i++)
  {
    buffer.push_back(data[i]);
  }
  buffer.push_back('\0');
  return buffer;
}

void drawMockupUI()
{
  oled.clearDisplay();
  #ifdef UI_FRAMES
  oled.drawFrame(0, 0, 128, 64);
  oled.drawRFrame(0, -5, 128, 22, 7);
  #endif
  oled.setFont(u8g2_font_9x15_me);
  oled.drawStr(10, 13, "Test Layer 2");

  oled.drawFrame(8, 24, 112, 16);
  oled.drawRBox(10, 26, 80, 12, 2);

  oled.setFont(u8g2_font_7x13_me);
  oled.drawStr(3, 52, "0");
  oled.drawStr(105, 52, "127");

  oled.setFont(u8g2_font_10x20_me);
  oled.drawStr(54, 59, "95");

  
  oled.sendBuffer();
}

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

  switch (buf[1])
  {
  case MSG_PREP_CONFIG:
    oled.clearBuffer();
    oled.setFont(u8g2_font_8x13_me);
    oled.drawStr(2, 12, "Receiving config");
    oled.sendBuffer();
    break;
  case MSG_XFER_DATA:

      // std::vector<std::vector<uint8_t>> names = parseForNames(buf);
      // uint8_t * name1 = &names[0][0];
      // uint8_t * name2 = &names[1][0];
      // uint8_t * name3 = &names[2][0];
      // uint8_t * name4 = &names[3][0];

      std::vector<uint8_t> name = getName(&buf[2]);
      uint8_t * name1 = &name[0];

      char line1[15], line2[15], line3[15], line4[15];
      slice_str((char *)name1, line1, 0, 14);
      // slice_str((char *)name2, line2, 0, 14);
      // slice_str((char *)name3, line3, 0, 14);
      // slice_str((char *)name4, line4, 0, 14);


      /*Periphs.*/oled.setDrawColor(1);
      /*Periphs.*/oled.setFont(u8g2_font_8x13_mf);
      /*Periphs.*/oled.drawStr(5,15, line1);
      // oled.drawStr(5,30, line2);
      // oled.drawStr(5,45, line3);
      // oled.drawStr(5,60, line4);
      oled.sendBuffer();
    break;
  
  default:
    break;
  }
}

void setup_() {
  usbMIDI.setHandleSystemExclusive(onRecvSysex);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(33, INPUT_PULLUP);

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LED_BUILTIN, 1);
    delay(100);
    digitalWrite(LED_BUILTIN, 0);
    delay(50);
  }

  oled.begin();
  
}

void loop_() {
  usbMIDI.read();
  Periphs.debouncer.update();
  if (Periphs.debouncer.read() == HIGH && Periphs.buttonState == LOW)
  {
    Periphs.buttonState = HIGH;
    drawMockupUI();
  } else if (Periphs.debouncer.read() == LOW && Periphs.buttonState == HIGH) {
    Periphs.buttonState = LOW;
  }
  // uint8_t * pkt;
  // pkt = generateConfigRequest(0);
  // usbMIDI.sendSysEx(sizeof(pkt)/sizeof(uint8_t *), pkt[0], true);
}