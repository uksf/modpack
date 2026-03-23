#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a client/HC event report on the server. Appends all events
        to the server buffer for API delivery.

    Parameters:
        0: Events <ARRAY> — array of event hashmaps

    Return Value:
        None

    Example:
        [_events] call uksf_statistics_fnc_handleClientReport
*/
if (GVAR(killswitch)) exitWith {};

params [["_events", [], [[]]]];

if (_events isEqualTo []) exitWith {};

GVAR(serverBuffer) append _events;
