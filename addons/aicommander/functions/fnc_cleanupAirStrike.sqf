#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Cleans up spawned strike aircraft and crew.
*/

params [
    ["_vehicle", objNull, [objNull]],
    ["_delaySec", 0, [0]]
];

if (isNull _vehicle) exitWith {};

if (_delaySec > 0) exitWith {
    [{
        _this call FUNC(cleanupAirStrike);
    }, [_vehicle, 0], _delaySec] call CBA_fnc_waitAndExecute;
};

if (isNull _vehicle) exitWith {};
{
    if (!isNull _x) then {
        deleteVehicle _x;
    };
} forEach crew _vehicle;
deleteVehicle _vehicle;
