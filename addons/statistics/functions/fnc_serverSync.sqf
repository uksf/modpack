#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Server sync tick. Sends all buffered events to the API
        via the extension, then clears the buffer.
        Runs as a PFH every 60 seconds.

    Parameters:
        None

    Return Value:
        None
*/
if (GVAR(serverBuffer) isEqualTo []) exitWith {};

private _buffer = +GVAR(serverBuffer);
GVAR(serverBuffer) = [];

[
    "mission_stats",
    createHashMapFromArray [
        ["mission", missionName],
        ["map", worldName],
        ["events", _buffer]
    ]
] call EFUNC(api,sendEvent);
