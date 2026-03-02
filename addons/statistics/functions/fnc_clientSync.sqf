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
if (GVAR(killswitch)) exitWith {};
if (GVAR(eventBuffer) isEqualTo []) exitWith {};

private _uid = getPlayerUID player;
private _events = GVAR(eventBuffer);
GVAR(eventBuffer) = [];

// Inject uid into each event
{_x set ["uid", _uid]} forEach _events;

[QGVAR(clientReport), [_events]] call CBA_fnc_serverEvent;
