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
    return this->userLabel;
}
std::string ControllerModel::getUserLabel(uint8_t layer)
{
    return this->userLabel[layer];
}

std::vector<uint8_t> ControllerModel::getControllerIDs()
{
    return this->controllerID;
}
uint8_t ControllerModel::getControllerID(uint8_t layer)
{   return this->controllerID[layer];   }

std::vector<uint8_t> ControllerModel::getMinVals()
{
    return this->minVal;
}
uint8_t ControllerModel::getMinVal(uint8_t layer)
{   return this->minVal[layer];         }

std::vector<uint8_t> ControllerModel::getMaxVals()
{
    return this->maxVal;
}
uint8_t ControllerModel::getMaxVal(uint8_t layer)
{   return this->maxVal[layer];         }

std::vector<uint8_t> ControllerModel::getMidiChannels()
{
    return this->midiChannel;
}
uint8_t ControllerModel::getMidiChannel(uint8_t layer)
{   return this->midiChannel[layer];    }

std::vector<bool> ControllerModel::getLatchings()
{
    return this->latching;
}
bool ControllerModel::getLatching(uint8_t layer)
{   return this->latching[layer];       }


//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Utility
std::vector<uint8_t> ControllerModel::serialise()
{
    std::vector<uint8_t> buf;
    for (uint8_t layer = 0; layer < NUM_LAYERS; layer++)
    {
        const char * characters = this->userLabel[layer].c_str();
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

void ControllerModel::deserialise(std::vector<uint8_t> buf)
{
    // Clear model
    this->userLabel.clear();
    this->controllerID.clear();
    this->minVal.clear();
    this->maxVal.clear();
    this->curVal.clear();
    this->midiChannel.clear();
    this->latching.clear();

    /*
     *  0               1               2
     *  Sysex Start     Function byte   Model length
     *  3               4...n           n+1             n+2             n+3             n+4             n+5             n+6
     *  String length   buf[3] chars    CC ID           Min value       Max value       Current value   MIDI channel    Latching
     */
    uint8_t layer = 0;
    uint8_t offset = 3;
    while (offset < buf[2])
    {
        char * reconstructedName;
        // Start on the label string length byte
        for (uint8_t c = 0; c < buf[offset]; c++)
        {
            reconstructedName[c] = buf[offset];
            offset++;
        }
        this->userLabel.push_back(std::string(reconstructedName));
        this->controllerID.push_back(buf[offset++]);
        this->minVal[layer] = buf[offset++];
        this->maxVal[layer] = buf[offset++];
        this->curVal[layer] = buf[offset++];
        this->midiChannel[layer] = buf[offset++];
        this->latching[layer] = buf[offset++];

        layer++;
    }
}

ControllerModel::ControllerModel()
{
    this->userLabel.reserve(NUM_LAYERS);
    this->controllerID.reserve(NUM_LAYERS);
    this->minVal.reserve(NUM_LAYERS);
    this->maxVal.reserve(NUM_LAYERS);
    this->midiChannel.reserve(NUM_LAYERS);
    this->latching.reserve(NUM_LAYERS);
    for (uint8_t layer = 0; layer < NUM_LAYERS; layer++)
    {
        this->userLabel.push_back("");
        this->controllerID.push_back(0);
        this->minVal.push_back(0);
        this->maxVal.push_back(127);
        this->midiChannel.push_back(0);
        this->latching.push_back(0);
    }
}
