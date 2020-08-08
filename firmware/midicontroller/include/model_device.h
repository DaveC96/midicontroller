#ifndef MODEL_DEVICE_H
#define MODEL_DEVICE_H

#include "consts.h"
#include "controllermodel.h"
#include <stdint.h>

class DeviceModel {
public:
    DeviceModel();

    void setCurrentController(uint8_t);
    uint8_t getCurrentLayer();

    ControllerModel midiControllers[NUM_CONTROLLERS];

private:
    uint8_t currentLayer;
    uint8_t currentController;
};

#endif