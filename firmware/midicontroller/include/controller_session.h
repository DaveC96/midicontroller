#ifndef CONTROLLER_SESSION_H
#define CONTROLLER_SESSION_H

#include "externs.h"
#include "consts.h"

namespace cSession
{
    void onButtonPressed(uint8_t which);

    void init();

    void update();
};

#endif