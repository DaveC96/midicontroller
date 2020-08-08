#ifndef VIEW_SESSION_H
#define VIEW_SESSION_H
#include <stdint.h>
#include <string.h>
#include <Arduino.h>

#include "consts.h"
#include "externs.h"
#include "controller_session.h"



namespace sessionView {
    void drawUI(uint8_t, uint8_t);
}


#endif