#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sync tick for clients and headless clients. Sends buffered events to the server
        if the buffer is non-empty. Runs as a PFH every 30 seconds.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_clientSync
*/
if (GVAR(killswitch)) exitWith {};

// Flush client-only providers before sync (not applicable on HC)
if (hasInterface) then {
    call FUNC(explosivesSync);
    call FUNC(samplerSync);
};

if (GVAR(eventBuffer) isEqualTo []) exitWith {};

private _events = GVAR(eventBuffer);
GVAR(eventBuffer) = [];
TRACE_1("Client sync",count _events);

// Inject uid into events that don't already have one (client providers)
// HC-buffered events (combat damage) already have uid set by the provider
if (hasInterface) then {
    private _uid = getPlayerUID player;
    {
        if !("uid" in _x) then {
            _x set ["uid", _uid];
        };
    } forEach _events;
};

[QGVAR(clientReport), [_events]] call CBA_fnc_serverEvent;
