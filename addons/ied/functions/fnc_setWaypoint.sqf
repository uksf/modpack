#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        sets up a waypoint inside the area for suicide bombers to follow

    Parameters:
        0: _group <GROUP>

    Return value:
        Nothing
*/
params ["_group", "_areaArray"];

private _position = [_areaArray] call CBA_fnc_randPosArea;

private _waypoint = [_group, _position, 0, "MOVE", "SAFE", "YELLOW", "LIMITED", "WEDGE", "[(this getVariable ['uksf_ied_sucideUnitGroup', grpNull]), (this getVariable ['uksf_ied_areaArray', []])] call uksf_ied_fnc_setWaypoint", [0,0,0], 30] call CBA_fnc_addWaypoint;

