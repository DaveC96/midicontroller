#ifndef APPSPACE_H
#define APPSPACE_H

#include <stdint.h>

struct ControllerConfig
{
    char[]  userLabel[8];
    uint8_t controllerID[8];
    uint8_t minVal[8];
    uint8_t maxVal[8];
    bool    latching[8];
};

struct AppSpace
{
    ControllerConfig controllers[8];
    uint8_t midiChannel[8];
    uint8_t currentMode;
};

#endif