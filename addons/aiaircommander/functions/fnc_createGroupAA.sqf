#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create an AA vehicle

    Parameters:
        0: AA Site <OBJECT>

    Return value:
        Nothing
*/
params ["_emptyLocation"];

private _spawns = GVAR(aaSpawns) apply {[_x distance2D _emptyLocation, _x]};
_spawns sort true;

if (_spawns isEqualTo []) exitWith {};

private _spawn = _spawns#0#1;
[getPos _spawn, east, EGVAR(gear,gearCrew), EGVAR(gear,gearVehAA), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_emptyLocation", "_group"];

    [_group, _emptyLocation, 50, "MOVE", "SAFE", "YELLOW", "NORMAL", "", "(vehicle this) setFuel 0; (group this) setBehaviour 'AWARE'"] call CBA_fnc_addWaypoint;
}, [_emptyLocation]] call EFUNC(common,spawnGroupVehicle);

