#include "midi.h"

int openPort(RtMidiOut * midiout, std::string target)
{
    int portCount = midiout->getPortCount();
    if (portCount == 0)
    {
    } else {
        for (int i = 0; i < portCount; i++)
        {
            if (midiout->getPortName(i) == target)
            {
                midiout->openPort(i);
                return 0;
            }
        }
    }
    return 1;
}
