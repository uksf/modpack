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
private _name = profileName;
private _events = +GVAR(eventBuffer);

GVAR(eventBuffer) = [];

[QGVAR(clientReport), [_uid, _name, _events]] call CBA_fnc_serverEvent;
