#ifndef CONTROLLERMODEL_H
#define CONTROLLERMODEL_H

#include <stdint.h>

#define NUM_LAYERS 8
#define NUM_CONTROLLERS 4

class ControllerModel {
private:
    QString userLabel   [NUM_LAYERS];
    uint8_t controllerID[NUM_LAYERS];
    uint8_t minVal      [NUM_LAYERS];
    uint8_t maxVal      [NUM_LAYERS];
    uint8_t curVal      [NUM_LAYERS];
    uint8_t midiChannel [NUM_LAYERS];
    bool    latching    [NUM_LAYERS];
public:
//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Setters
    void setUserLabel   (uint8_t layer, std::string name);
    void setControllerID(uint8_t layer, uint8_t id      );
    void setMinVal      (uint8_t layer, uint8_t min     );
    void setMaxVal      (uint8_t layer, uint8_t max     );
    void setMidiChannel (uint8_t layer, uint8_t chan    );
    void setLatching    (uint8_t layer, bool latch      );
//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Getters
    std::vector<std::string>    getUserLabels   ();
    std::vector<uint8_t>        getControllerIDs();
    std::vector<uint8_t>        getMinVal       ();
    std::vector<uint8_t>        getMaxVal       ();
    std::vector<uint8_t>        getMidiChannel  ();
    std::vector<bool>           getLatching     ();
//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Utility
    std::ostream& serialise     (std::ostream& os);
    std::istream& deserialise   (std::istream& is);
};

#endif // CONTROLLERMODEL_H
