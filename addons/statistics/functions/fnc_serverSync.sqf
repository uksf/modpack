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

    Example:
        call uksf_statistics_fnc_serverSync
*/
if (GVAR(killswitch)) exitWith {};

// Drain server-local eventBuffer (from "all" locality providers running on this machine)
// Server has no clientSyncPFH, so this is the only drain point for server-local events
if (GVAR(eventBuffer) isNotEqualTo []) then {
    private _localEvents = GVAR(eventBuffer);
    GVAR(eventBuffer) = [];
    [_localEvents] call FUNC(handleClientReport);
};

if (GVAR(serverBuffer) isEqualTo []) exitWith {};

private _buffer = GVAR(serverBuffer);
GVAR(serverBuffer) = [];
TRACE_1("Server sync",count _buffer);

[
    "mission_stats",
    createHashMapFromArray [
        ["sessionId", EGVAR(api,sessionId)],
        ["mission", missionName],
        ["map", worldName],
        ["events", _buffer]
    ]
] call EFUNC(api,sendEvent);
