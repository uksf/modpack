#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets up a waypoint inside the area for suicide bombers to follow

    Parameters:
        0: Suicide unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

private _group = _unit getVariable [QGVAR(sucideUnitGroup), grpNull];
private _areaArray = _unit getVariable [QGVAR(areaArray), []];

if (isNull _group || _areaArray isEqualTo []) exitWith {};

private _position = [_areaArray] call CBA_fnc_randPosArea;
_position set [2, 0];

private _waypoint = [_group, _position, 0, "MOVE", "SAFE", "YELLOW", "LIMITED", "WEDGE", "[this] call uksf_ied_fnc_setWaypoint", [0,0,0], 30] call CBA_fnc_addWaypoint;

