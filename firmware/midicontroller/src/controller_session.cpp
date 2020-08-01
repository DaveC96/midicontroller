#include "controller_session.h"

void cSession::onButtonPressed(uint8_t which)
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void cSession::init()
{
    deviceModel.currentController = CONTROLLER_SESSION;
    for (uint8_t i = 0; i < NUM_CONTROLLERS; i++) {        // Register callbacks
        periphs.onButtonPressed[i] = std::bind(onButtonPressed, std::placeholders::_1);
    }
}

void cSession::update()
{

}