#include "controllermodel.h"
#include <typeinfo>
#include <iostream>


//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Setters
void ControllerModel::setUserLabel(uint8_t layer, std::string name)
{   this->userLabel[layer] = name;      }

void ControllerModel::setControllerID(uint8_t layer, uint8_t id)
{   this->controllerID[layer] = id;     }

void ControllerModel::setMinVal(uint8_t layer, uint8_t min)
{   this->minVal[layer] = min;          }

void ControllerModel::setMaxVal(uint8_t layer, uint8_t max)
{   this->maxVal[layer] = max;          }

void ControllerModel::setMidiChannel(uint8_t layer, uint8_t chan)
{   this->midiChannel[layer] = chan;    }

void ControllerModel::setLatching(uint8_t layer, bool latch)
{   this->latching[layer] = latch;      }


//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Getters
std::vector<std::string> ControllerModel::getUserLabels()
{
    std::vector<std::string> buf;
    buf.assign(this->userLabel, this->userLabel+NUM_LAYERS);
    return buf;
}
std::string ControllerModel::getUserLabel(uint8_t layer)
{   return this->userLabel[layer];      }

std::vector<uint8_t> ControllerModel::getControllerIDs()
{
    std::vector<uint8_t> buf;
    buf.assign(this->controllerID, this->controllerID+NUM_LAYERS);
    return buf;
}
uint8_t ControllerModel::getControllerID(uint8_t layer)
{   return this->controllerID[layer];   }

std::vector<uint8_t> ControllerModel::getMinVals()
{
    std::vector<uint8_t> buf;
    buf.assign(this->minVal, this->minVal+NUM_LAYERS);
    return buf;
}
uint8_t ControllerModel::getMinVal(uint8_t layer)
{   return this->minVal[layer];         }

std::vector<uint8_t> ControllerModel::getMaxVals()
{
    std::vector<uint8_t> buf;
    buf.assign(this->maxVal, this->maxVal+NUM_LAYERS);
    return buf;
}
uint8_t ControllerModel::getMaxVal(uint8_t layer)
{   return this->maxVal[layer];         }

std::vector<uint8_t> ControllerModel::getMidiChannels()
{
    std::vector<uint8_t> buf;
    buf.assign(this->midiChannel, this->midiChannel+NUM_LAYERS);
    return buf;
}
uint8_t ControllerModel::getMidiChannel(uint8_t layer)
{   return this->midiChannel[layer];    }

std::vector<bool> ControllerModel::getLatchings()
{
    std::vector<bool> buf;
    buf.assign(this->latching, this->latching+NUM_LAYERS);
    return buf;
}
bool ControllerModel::getLatching(uint8_t layer)
{   return this->latching[layer];       }


//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Utility
uint8_t * ControllerModel::serialise()
// Don't look at me, I'm hideous
{
    size_t bufferSize = 0;
    bufferSize += sizeof(size_t);           // Length of model
    for (uint8_t i = 0; i < NUM_LAYERS; i++)
    {
        bufferSize = bufferSize         +
            sizeof(uint8_t)             +   // Length of userLabel
            this->userLabel[i].size()   +
            sizeof(this->controllerID[i])  +
            sizeof(this->minVal[i])        +
            sizeof(this->maxVal[i])        +
            sizeof(this->curVal[i])        +
            sizeof(this->midiChannel[i])   +
            sizeof(this->latching[i]);
    }

    static uint8_t * buffer = new uint8_t[bufferSize];
    uint16_t offset = 0;
    memcpy(buffer + offset, &bufferSize, sizeof(size_t));   // Buffer size
    offset += sizeof(size_t);
    for (uint8_t i = 0; i < NUM_LAYERS; i++)
    {
        uint8_t s = this->userLabel[i].size();
        memcpy(buffer + offset, &s, sizeof(uint8_t));
        offset += sizeof(uint8_t);
        memcpy(buffer + offset, this->userLabel[i].data(), s);
        offset += s;
        memcpy(buffer + offset, &this->controllerID[i], sizeof(this->controllerID[i]));
        offset += sizeof(this->controllerID[i]);
        memcpy(buffer + offset, &this->minVal[i], sizeof(this->minVal[i]));
        offset += sizeof(this->minVal[i]);
        memcpy(buffer + offset, &this->maxVal[i], sizeof(this->maxVal[i]));
        offset += sizeof(this->maxVal[i]);
        memcpy(buffer + offset, &this->curVal[i], sizeof(this->curVal[i]));
        offset += sizeof(this->curVal[i]);
        memcpy(buffer + offset, &this->midiChannel[i], sizeof(this->midiChannel[i]));
        offset += sizeof(this->midiChannel[i]);
        memcpy(buffer + offset, &this->latching[i], sizeof(this->latching[i]));
        offset += sizeof(this->latching[i]);

    }
    return buffer;
}

std::istream& ControllerModel::deserialise(std::istream& is) const
{
    //TODO
    return is;
}

ControllerModel::ControllerModel()
{
    for (uint8_t layer = 0; layer < NUM_LAYERS; layer++)
    {
        this->userLabel     [layer] = "";
        this->controllerID  [layer] = 0;
        this->minVal        [layer] = 0;
        this->maxVal        [layer] = 127;
        this->midiChannel   [layer] = 0;
        this->latching      [layer] = false;
    }
}
