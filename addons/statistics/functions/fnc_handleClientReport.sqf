#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a client event report on the server. Appends received events
        into the server buffer for later API delivery.

    Parameters:
        0: Events <ARRAY> — array of event hashmaps (each containing uid and name)

    Return Value:
        None

    Example:
        [_events] call uksf_statistics_fnc_handleClientReport
*/
if (GVAR(killswitch)) exitWith {};

params [["_events", [], [[]]]];

if (_events isEqualTo []) exitWith {};

// Route combat damage events to the damage ledger, everything else to the server buffer
{
    if (_x getOrDefault ["type", ""] isEqualTo "combatDamage") then {
        [_x] call FUNC(handleDamageRelay);
    } else {
        GVAR(serverBuffer) pushBack _x;
    };
} forEach _events;
