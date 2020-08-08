#ifndef CONTROLLER_SESSION_H
#define CONTROLLER_SESSION_H

#include "externs.h"
#include "consts.h"
#include "sysexmessaging.h"

namespace cSession
{
    void onButtonPressed(uint8_t which);
    void onRecvSysex(byte*, unsigned int);

    void init();

    void update();
};

#endif