#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        For transport only, AI should wait for everyone / nearly everyone to be dismounted before getting next waypoint

    Parameters:
        0: Leader <OBJECT>

    Return value:
        Nothing
*/
#define TIME_PER_UNIT 2

params ["_leader"];

if !(local _leader) exitWith {};

private _group = group _leader;
{unassignVehicle _x} forEach units _group;
_group setBehaviour "AWARE";

[{
    params ["_group"];

    private _playerPosition = _group getVariable [QGVAR(playerPosition), []];
    if (_playerPosition isEqualTo []) exitWith {
        [_group, _group, 300, "SAD", "AWARE"] call CBA_fnc_taskPatrol;
    };

    [_group, _playerPosition, 100, "SAD", "AWARE", "YELLOW", "NORMAL", "LINE", QUOTE([group this] call FUNC(selectStayBehindForce))] call CBA_fnc_addWaypoint;
}, [_group], (2 max (count units _group)) * TIME_PER_UNIT] call CBA_fnc_waitAndExecute;
