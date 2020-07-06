# Sysex Spec
This document outlines the protocol for software<->firmware comms over Sysex.
All sysex messages respect the standard 0xF0 header and 0xF7 terminator.
The identification header byte is used to specify a message type.
The final byte before the terminator is a checksum detailed below.

# Checksum
The final byte is to be calculated by copying the function byte to a counter.
Each of the following data bytes is then added one by one to the counter.
If an addition exceeds 127, the overflowing operation is halted, counter reset to 0, and then resumed.

# Message Types
The top 4 bits signify logical separations of functionality.
The bottom 4 bits follow this scheme:
- 0 - Request (expects acknowledgement)
- 1 - Acknowledgement with readback
- 2 - Data transfer
- 3 - Data transfer complete
- 4 - Status Error


| Byte  | Direction             | Purpose                   | Parameters        | Example                                                           |
| :---: | :----                 | :----                     | :----             | :-----                                                            |
| 0x10  | Software -> Firmware  | Request controller config | 1: controller id  | 0xF0 0x10 0x02 0x12 0xF7 -- Request controller 02 data            |
| 0x11  | Software <- Firmware  | Acknowledge 0x10          | 1: controller id  | 0xF0 0x11 0x02 0x13 0xF7 -- Readback and OK for previous example  |
| 0x14  | Software <> Firmware  | Error                     | None              | 0xF0 0x14 0x14 0xF7      -- Request not understood or invalid     |
| 0x20  | Software -> Firmware  | Prepare to receive config | 1: controller id  | 0xF0 0x20 0x00 0x21 0xF7 -- Prepare to receive controller 00 data |
| 0x21  | Software <- Firmware  | Acknowledge 0x20          | 1: controller id  | 0xF0 0x21 0x00 0x21 0xF7 -- Readback for previous example         |
| 0x24  | Software <> Firmware  | Error                     | None              | 0xF0 0x24 0x24 0xF7      -- Request not understood or invalid     |
| 0x32  | Software <> Firmware  | Send controller config    | <255 bytes data   | 0xF0 0x32 0x12 0x34 0x78 0xF7 -- Sending config data (12 34)      |
| 0x33  | Software <> Firmware  | Sending complete          | None              | 0xF0 0x33 0x33 0xF7      -- Data transfer completed               |
| 0x34  | Software <> Firmware  | Error                     | None              | 0xF0 0x34 0x34 0xF7      -- Error in data transfer                |

# User Flow Example

1. User clicks "get from device" button in control software
2. Software sends controller config request 0:  [0xF0 0x10 0x00 0x10 0xF7]
3. Firmware acknowledges request: [0xF0 0x11 0x00 0x11 0xF7]
4. Firmware transfers data: [0xF0 0x32 0x12 0x34 0x78 0xF7]
5. Firmware signals completion: [0xF0 0x33 0x33 0xF7]
6. Software sends controller config request 1... etc