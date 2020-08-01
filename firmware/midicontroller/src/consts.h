#ifndef CONSTS_H
#define CONSTS_H

#define NUM_LAYERS      8
#define NUM_CONTROLLERS 4

#define BUTTON_HOLD_TIME 500

#define EVENT_NONE      0
#define EVENT_PRESSED   1
#define EVENT_RELEASED  2
#define EVENT_HELD      3

//  ==      ==      ==      Pin assignments
//      --      Encoders
#define PIN_BUT_1   33
#define PIN_ENC_1A  35
#define PIN_ENC_1B  34
#define PIN_BUT_2   36
#define PIN_ENC_2A  38
#define PIN_ENC_2B  37
#define PIN_BUT_3   39
#define PIN_ENC_3A  41
#define PIN_ENC_3B  40
#define PIN_BUT_4   20
#define PIN_ENC_4A  22
#define PIN_ENC_4B  21
//      --      I2C
#define ADDR_MUX    119
#define PIN_MUX_SCL 19
#define PIN_MUX_SDA 18
#define PIN_OLED_1_SCL  2
#define PIN_OLED_1_SDA  2
#define PIN_OLED_2_SCL  3
#define PIN_OLED_2_SDA  3
#define PIN_OLED_3_SCL  4
#define PIN_OLED_3_SDA  4
#define PIN_OLED_4_SCL  5
#define PIN_OLED_4_SDA  5
//      --      Mux outputs
#define OLED_LL  5
#define OLED_L   4
#define OLED_R   3
#define OLED_RR  2
#define OLED_C   6
static const uint8_t oleds[5] = { OLED_LL, OLED_L, OLED_R, OLED_RR, OLED_C };


//      --      Controllers
#define CONTROLLER_STARTUP  0
#define CONTROLLER_SESSION  1
#define CONTROLLER_MENU     2


#endif