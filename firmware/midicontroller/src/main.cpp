#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "consts.h"
#include "TCA9548A.h"

TCA9548A oledMux;


void selectOled(uint8_t i) {
  if (i > 7) return;
  for (uint8_t i = 0x70; i < 0x80; i++)
  {
    Wire.beginTransmission(i);
    Wire.write(1 << i);
    Wire.endTransmission();  
  }
}

void setup() {
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R2, /* reset=*/ U8X8_PIN_NONE);

  // selectOled(i);
  // delay(50);

  oledMux.begin(Wire);
  oledMux.closeAll();
  oledMux.openChannel(0);
  oledMux.openChannel(1);
  oledMux.openChannel(2);
  oledMux.openChannel(3);
  oledMux.openChannel(4);
  oledMux.openChannel(5);
  oledMux.openChannel(6);
  oledMux.openChannel(7);



  oled.begin();
  oled.clearDisplay();
  oled.setDrawColor(1);
  oled.drawBox(10, 10, 25, 25);
  oled.sendBuffer();

 

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

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

    
}

void loop() {
  // put your main code here, to run repeatedly:
    if (!digitalRead(PIN_BUT_3) || !digitalRead(PIN_BUT_4) || !digitalRead(PIN_BUT_1) || !digitalRead(PIN_BUT_2)) {
      digitalWrite(LED_BUILTIN, HIGH);
    }

    if (!digitalRead(PIN_ENC_1A) || !digitalRead(PIN_ENC_2A) || !digitalRead(PIN_ENC_3A) || !digitalRead(PIN_ENC_4A)) {
      digitalWrite(LED_BUILTIN, HIGH);
    }

  digitalWrite(LED_BUILTIN, LOW);
}