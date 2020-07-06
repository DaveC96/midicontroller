#include "sysexmessaging.h"
#include <stdint.h>
#include <vector>

/**********************************************
 * This doesn't quite work, yet... I think... *
 **********************************************/

void _packetise(std::vector<uint8_t> * data)
{
    // Checksum
    uint8_t counter = 0;
    for (uint8_t byte : (*data))
    {
        if (counter + byte > 127) { counter = 0; }
        counter += byte;
    }
    data->push_back(counter);

    // Sysex start & end bytes
    data->insert(data->begin(), SYX_HEADER);
    data->push_back(SYX_TERMINATOR);
}

std::vector<uint8_t> generateConfigRequest(uint8_t controllerID)
{
    std::vector<uint8_t> buf = { MSG_REQ_CONFIG, controllerID   };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generateConfigAck(uint8_t controllerID)
{
    std::vector<uint8_t> buf = { MSG_REQ_ACK, controllerID      };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generatePrep(uint8_t controllerID)
{
    std::vector<uint8_t> buf = { MSG_PREP_CONFIG, controllerID  };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generatePrepAck(uint8_t controllerID)
{
    std::vector<uint8_t> buf = { MSG_PREP_ACK, controllerID     };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generateConfigError()
{
    std::vector<uint8_t> buf = { MSG_REQ_ERROR  };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generatePrepError()
{
    std::vector<uint8_t> buf = { MSG_PREP_ERROR };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generateXferError()
{
    std::vector<uint8_t> buf = { MSG_XFER_ERROR };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generateXferDone()
{
    std::vector<uint8_t> buf = { MSG_XFER_DONE };
    _packetise(&buf);
    return buf;
}

std::vector<uint8_t> generateXferData(std::vector<uint8_t> data)
{
    std::vector<uint8_t> buf = data;
    buf.insert(buf.begin(), MSG_XFER_DATA);
    _packetise(&buf);
    return buf;
}
