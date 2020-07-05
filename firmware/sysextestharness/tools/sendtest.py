import mido
import time

interval = 1
payloads = [
    # [0, 0, 0],
    # [127, 0, 0],
    # [0, 127, 0],
    # [0, 0, 127],
    # [127, 127, 0],
    # [0, 127, 127],
    [127, 0, 127],
    # [127, 127, 127]

    # [1],
    # [1, 2],
    # [1, 2, 3],
    # [1, 2, 3, 4],
    # [1, 2, 3, 4, 5]
]

with mido.open_output("Teensy MIDI") as teensy:
    for payload in payloads:
        for byte in payload:
            if byte > 127 or type(byte) != int:
                raise Exception("Not a valid payload: {byte}")
        msg = mido.Message("sysex", data=payload)
        teensy.send(msg)
        print(f"Sent: {msg}")
        time.sleep(interval)
        

