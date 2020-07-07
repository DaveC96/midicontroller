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
std::vector<uint8_t> ControllerModel::serialise()
{
    std::vector<uint8_t> buf;
    for (uint8_t layer = 0; layer < NUM_LAYERS; layer++)
    {
        const char * characters = this->userLabel[layer].data();
        buf.push_back(this->userLabel[layer].size());
        for (uint8_t i = 0; i < this->userLabel[layer].size(); i++)
        {
            buf.push_back(characters[i]);
        }
        buf.push_back(this->controllerID[layer]);
        buf.push_back(this->minVal[layer]);
        buf.push_back(this->maxVal[layer]);
        buf.push_back(this->curVal[layer]);
        buf.push_back(this->midiChannel[layer]);
        buf.push_back(this->latching[layer]);
    }
    return buf;
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
