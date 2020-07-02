#ifndef MODEL_H
#define MODEL_H

#include <stdint.h>
#include <QApplication>

#define NUM_LAYERS 8
#define NUM_CONTROLLERS 8

struct ControllerConfig {
    QString userLabel[NUM_LAYERS];
    uint8_t controllerID[NUM_LAYERS];
    uint8_t minVal[NUM_LAYERS];
    uint8_t maxVal[NUM_LAYERS];
    uint8_t curVal[NUM_LAYERS];
    bool latching[NUM_LAYERS];
};

struct AppModel {
    ControllerConfig controllers[NUM_CONTROLLERS];
    uint8_t currentLayer;
};


#endif // MODEL_H
