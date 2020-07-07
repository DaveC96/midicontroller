#ifndef MODEL_H
#define MODEL_H

#include "../../common/controllermodel.h"
#include "midi.h"
#define NUM_CONTROLLERS 4

struct AppModel {
    ControllerModel controllers[NUM_CONTROLLERS];
    uint8_t currentLayer;
    RtMidiOut * midiOut;
};


#endif // MODEL_H
