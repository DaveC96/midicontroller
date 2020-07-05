# Sysex Spec
This document outlines the protocol for software<->firmware comms over Sysex.
All sysex messages respect the standard 0xF0 header and 0xF7 terminator.
The identification header byte is used to specify a message type.
The final byte before the terminator is a checksum detailed below.

# Checksum
The final byte is to be calculated by copying the function byte to a counter.
Each of the following data bytes is then added one by one to the counter.
If an addition exceeds 127, the counter wraps to 0 and the remainder is added.

# Message Types
The top 4 bits signify logical separations of functionality.
The bottom 4 bits follow this scheme:
0 - Request (expects acknowledgement)
1 - Acknowledgement with readback
2 - Data transfer
3 - Error


| Byte  | Direction             | Purpose                   | Parameters        | Example                                                           |
| :---: | :----                 | :----                     | :----             | :-----                                                            |
| 0x10  | Software -> Firmware  | Request controller config | 1: controller id  | 0xF0 0x10 0x02 0x12 0xF7 -- Request controller 02 data            |
| 0x11  | Software <- Firmware  | Acknowledge 0x10          | 1: controller id  | 0xF0 0x11 0x02 0x13 0xF7 -- Readback and OK for previous example  |
| 0x13  | Software <> Firmware  | Error                     | None              | 0xF0 0x13 0x13 0xF7      -- Request not understood or invalid     |
| 0x20  | Software -> Firmware  | Prepare to receive config | 1: controller id  | 0xF0 0x20 0x00 0x21 0xF7 -- Prepare to receive controller 00 data |
| 0x21  | Software <- Firmware  | Acknowledge 0x20          | 1: controller id  | 0xF0 0x21 0x00 0x21 0xF7 -- Readback for previous example         |
| 0x23  | Software <> Firmware  | Error                     | None              | 0xF0 0x23 0x23 0xF7      -- Request not understood or invalid     |
| 0x32  | Software <> Firmware  | Send controller config    | <255 bytes data   | 0xF0 0x32 0x12 0x34 0x78 0xF7 -- Sending config data (12 34)      |