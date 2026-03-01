#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Client sync tick. Sends buffered events to the server if the buffer is non-empty.
        Runs as a PFH every 30 seconds.

    Parameters:
        None

    Return Value:
        None
*/
if (GVAR(eventBuffer) isEqualTo []) exitWith {};

private _uid = getPlayerUID player;

// Inject uid into each event
private _events = GVAR(eventBuffer) apply {
    private _event = +_x;
    _event set ["uid", _uid];
    _event
};

GVAR(eventBuffer) = [];

[QGVAR(clientReport), [_events]] call CBA_fnc_serverEvent;
