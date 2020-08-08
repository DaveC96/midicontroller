#include "model_device.h"

DeviceModel::DeviceModel()
{
    this->currentController = CONTROLLER_STARTUP;
    this->currentLayer = 0;

    //TODO: Read from flash for this->midiControllers instead of defaults:
    this->midiControllers[0].setUserLabel(0, "Test1");
    this->midiControllers[3].setUserLabel(0, "Test4");
}

void DeviceModel::setCurrentController(uint8_t c)
{
    this->currentController = c;
}

uint8_t DeviceModel::getCurrentLayer()
{
    return this->currentLayer;
}