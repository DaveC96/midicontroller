#ifndef CONTROLLERMODEL_H
#define CONTROLLERMODEL_H

#include <stdint.h>
#include <vector>
#include <string>

#define NUM_LAYERS 8

class ControllerModel {
private:
    std::vector<std::string> userLabel   ;
    std::vector<uint8_t>     controllerID;
    std::vector<uint8_t>     minVal      ;
    std::vector<uint8_t>     maxVal      ;
    std::vector<uint8_t>     curVal      ;
    std::vector<uint8_t>     midiChannel ;
    std::vector<bool>        latching    ;

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
    std::vector<uint8_t>        getMinVals      ();
    std::vector<uint8_t>        getMaxVals      ();
    std::vector<uint8_t>        getMidiChannels ();
    std::vector<bool>           getLatchings    ();
    std::string                 getUserLabel    (uint8_t layer);
    uint8_t                     getControllerID (uint8_t layer);
    uint8_t                     getMinVal       (uint8_t layer);
    uint8_t                     getMaxVal       (uint8_t layer);
    uint8_t                     getMidiChannel  (uint8_t layer);
    bool                        getLatching     (uint8_t layer);

//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--//--\\--// Utility
//    uint8_t * serialise         ();
    std::vector<uint8_t> serialise();
    void deserialise            (std::vector<uint8_t> buf);
    ControllerModel             ();
};

#endif // CONTROLLERMODEL_H
