#ifndef MIDI_H
#define MIDI_H

#include "/usr/local/include/rtmidi.h"

int openPort(RtMidiOut * midiout, std::string target);

#endif // MIDI_H
