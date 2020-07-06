#ifndef SYSEXMESSAGING_H
#define SYSEXMESSAGING_H

#define MSG_REQ_CONFIG  0x10
#define MSG_REQ_ACK     0x11
#define MSG_REQ_ERROR   0x14
#define MSG_PREP_CONFIG 0x20
#define MSG_PREP_ACK    0x21
#define MSG_PREP_ERROR  0x24
#define MSG_XFER_DATA   0x32
#define MSG_XFER_DONE   0x33
#define MSG_XFER_ERROR  0x34
#define MSG_LOGIC_ERROR 0x44

#define SYX_HEADER      0xF0
#define SYX_TERMINATOR  0xF7

#include <stdint.h>
#include <vector>

void _packetise(std::vector<uint8_t> * data);

std::vector<uint8_t> generateConfigRequest  (uint8_t controllerID);
std::vector<uint8_t> generateConfigAck      (uint8_t controllerID);
std::vector<uint8_t> generatePrep           (uint8_t controllerID);
std::vector<uint8_t> generatePrepAck        (uint8_t controllerID);
std::vector<uint8_t> generateXferData       (std::vector<uint8_t> data);
std::vector<uint8_t> generateXferDone       ();
std::vector<uint8_t> generateXferError      ();
std::vector<uint8_t> generateConfigError    ();
std::vector<uint8_t> generatePrepError      ();



#endif
