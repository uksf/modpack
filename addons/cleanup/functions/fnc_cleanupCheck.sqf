#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Run cleanup every 1/4 of delay time

    Parameters:
        None

    Return value:
        Nothing
*/
if (!GVAR(enabled)) exitWith {};

private _newKilled = [];
{
    _x params ["_object", "_time"];
    
    if (!(_object getVariable [QGVAR(excluded), false])) then {                
        private _multiplier = [2, 1] select (_object isKindOf "Man");
        if ((_time + (GVAR(delay) * _multiplier)) < CBA_missionTime) then {
            deleteVehicle _object;
        } else {
            _newKilled pushBack _x;
        };
    };
} forEach GVAR(killed);
GVAR(killed) = _newKilled;

[{[] call FUNC(cleanupCheck)}, [], GVAR(delay) / 4] call CBA_fnc_waitAndExecute;
