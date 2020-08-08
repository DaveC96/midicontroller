#include "controller_session.h"

std::vector<char> getName(byte * data) // Pass a pointer to the pre-string length byte
{   /*
    *  Parse a config byte array and reconstruct the name into a C-style string
    */

    std::vector<char> buf;
    buf.reserve(data[0]);
    for (uint8_t offset = 1; offset <= data[0]; offset++) {
        buf.push_back(data[offset]);
    }
    buf.push_back('\0');
    return buf;
}

void cSession::onButtonPressed(uint8_t which)
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void cSession::onRecvSysex(byte * data, unsigned int length)
{
    byte buf[length];
    for (byte i = 0; i < length; i++) {
        buf[i] = *(data + i);
    }
    usbMIDI.sendSysEx(length, buf, true); // Loopback for debug

    switch(buf[1]) // Message type byte
    {
        case MSG_PREP_CONFIG:
            // Don't think we need to do anything here really?
            break;

        case MSG_XFER_DATA:
            // TODO: This parsing needs doing properly
            std::vector<char> name = getName(&buf[2]); // Just one for now
            deviceModel.midiControllers[0].setUserLabel(0, &name[0]);
    }
}

void cSession::init()
{
    deviceModel.setCurrentController(CONTROLLER_SESSION);
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {        // Register callbacks
        periphs.onButtonPressed[i] = std::bind(onButtonPressed, std::placeholders::_1);
    }
}

void cSession::update()
{

}