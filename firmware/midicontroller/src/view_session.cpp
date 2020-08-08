#include "view_session.h"

static bool needsRedraw[5] = {true, true, true, true, true};
void sessionView::drawUI(uint8_t display, uint8_t num)
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