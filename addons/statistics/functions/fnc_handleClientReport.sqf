#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a client/HC event report on the server. Routes events by type:
        - "combatDamage" events go to the damage ledger for kill/assist correlation
        - All other events go to the server buffer for API delivery

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

{
    private _eventType = _x getOrDefault ["type", ""];
    if (_eventType isEqualTo "combatDamage") then {
        [_x] call FUNC(handleDamageRelay);
    } else {
        GVAR(serverBuffer) pushBack _x;
    };
} forEach _events;
