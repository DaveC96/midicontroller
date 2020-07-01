#ifndef APPSPACE_H
#define APPSPACE_H

#include <stdint.h>
#include "consts.h"

struct ControllerConfig
{
    char[]  userLabel[NUM_LAYERS];
    uint8_t controllerID[NUM_LAYERS];
    uint8_t minVal[NUM_LAYERS];
    uint8_t maxVal[NUM_LAYERS];
    uint8_t curVal[NUM_LAYERS];
    uint8_t latchingBitmask;
};

struct AppSpace
{
    ControllerConfig controllers[8];
    uint8_t midiChannel[8];
    uint8_t currentMode;
    uint8_t currentLayer;
};

#endif