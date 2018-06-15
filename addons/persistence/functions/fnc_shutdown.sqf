/*
    Author:
        Tim Beswick

    Description:
        Forces server shutdown after saving data

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if (!isServer) exitWith {
    [QGVAR(shutdown)] call CBA_fnc_serverEvent;
};

{
    SERVER_COMMAND serverCommand (format ["#kick %1", owner _x]);
} forEach ([] call CBA_fnc_players);

[{
    SERVER_COMMAND serverCommand "#shutdown";
}, [], 2] call CBA_fnc_waitAndExecute;
