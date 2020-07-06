#include "sysexmessaging.h"
#include <stdint.h>

/**********************************************
 * This doesn't quite work, yet... I think... *
 **********************************************/

uint8_t _checksum(uint8_t msgtype, uint8_t * data[], uint8_t length)
{
    uint8_t counter = msgtype;
    for (uint8_t byte = 0; byte < length; byte++)
    {
        if (counter + byte > 127) { counter = 0; }
        counter += byte;
    }
    return counter;
}

uint8_t * _packetise(uint8_t msgtype, uint8_t * data[], uint8_t length)
{
    uint8_t buf[length+4];
    bool valid = true;
    // Check that all data bytes are within range
    for (uint8_t i = 0; i < length; i++)
    {
        if (*data[i] < 0 || *data[i] > 127) { valid = false; }
    }

    // Begin constructing the packet
    buf[0] = SYX_HEADER;
    if (!valid)
    {
        // Create a logic error packet instead
        buf[1] = MSG_LOGIC_ERROR;
        buf[2] = _checksum(MSG_LOGIC_ERROR, nullptr, 0);
        buf[3] = SYX_TERMINATOR;
        return buf;
    } else {
        // All good, let's make the packet we were asked to
        buf[1] = msgtype;
        for (uint8_t i = 0; i < length; i++)
        {
            buf[i+2] = *data[i];
        }
        buf[sizeof(buf)/sizeof(uint8_t)-1] = _checksum(msgtype, data, length);
        buf[sizeof(buf)/sizeof(uint8_t)] = SYX_TERMINATOR;
        return buf;
    }
}

uint8_t * generateConfigRequest(uint8_t controllerID)
{
    uint8_t * data[1] = {&controllerID};
    return _packetise(MSG_REQ_CONFIG, data, 1);
}

uint8_t * generateConfigAck(uint8_t controllerID)
{
    uint8_t * data[1] = {&controllerID};
    return _packetise(MSG_REQ_ACK, data, 1);
}

uint8_t * generatePrep(uint8_t controllerID)
{
    uint8_t * data[1] = {&controllerID};
    return _packetise(MSG_PREP_CONFIG, data, 1);
}

uint8_t * generatePrepAck(uint8_t controllerID)
{
    uint8_t * data[1] = {&controllerID};
    return _packetise(MSG_PREP_ACK, data, 1);
}

uint8_t * generateConfigError()   {   return _packetise(MSG_REQ_ERROR, nullptr, 0);   }
uint8_t * generatePrepError()     {   return _packetise(MSG_PREP_ERROR, nullptr, 0);  }
uint8_t * generateXferError()     {   return _packetise(MSG_XFER_ERROR, nullptr, 0);  }
uint8_t * generateXferDone()      {   return _packetise(MSG_XFER_DONE, nullptr, 0);   }
uint8_t * generateXferData(uint8_t * data[], uint8_t length)  {   return _packetise(MSG_XFER_DATA, data, length);     }
