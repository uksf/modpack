#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assigns waypoints to hunter forces

    Parameters:
        None

    Return value:
        Nothing
*/

params ["_group","_bluforMortarPos"];

_fnc_getWPPos = {
    params ["_bluforMortarPos"];
    private _initialWPPos = [_bluforMortarPos,800] call CBA_fnc_randPos;
    _initialWPPos
};

private _groupStartPos = getPos leader _group;

private _initialWPPos = [_bluforMortarPos] call _fnc_getWPPos;
private _helipad = "Land_HelipadEmpty_F" createVehicle _initialWPPos;

if ((_bluforMortarPos distance2D _initialWPPos) < 700) then {
    private _initialWPPos = [_bluforMortarPos] call _fnc_getWPPos;
    if ((vehicle leader _group) isKindOf "Helicopter") then {
        [_group, _initialWPPos, 0, "TR UNLOAD"] call CBA_fnc_addWaypoint;
        [_group, _groupStartPos, 0, "MOVE", "AWARE","YELLOW","FULL","","[this] call uksf_antiMortar_fnc_handleDelete;"] call CBA_fnc_addWaypoint;
    } else {
        [_group, _initialWPPos, 0, "GETOUT", "AWARE", "YELLOW", "NORMAL", "WEDGE", "", [10,20,30]] call CBA_fnc_addWaypoint;
        [_group, _bluforMortarPos, 0, "MOVE", "AWARE"] call CBA_fnc_addWaypoint;
    };
} else {
    if ((vehicle leader _group) isKindOf "Helicopter") then {
        [_group, _initialWPPos, 0, "TR UNLOAD"] call CBA_fnc_addWaypoint;
        [_group, _groupStartPos, 0, "MOVE", "AWARE","YELLOW","FULL","","[this] call uksf_antiMortar_fnc_handleDelete;"] call CBA_fnc_addWaypoint;
    } else {
        [_group, _initialWPPos, 0, "GETOUT", "AWARE", "YELLOW", "NORMAL", "WEDGE", "", [10,20,30]] call CBA_fnc_addWaypoint;
        [_group, _bluforMortarPos, 0, "MOVE", "AWARE"] call CBA_fnc_addWaypoint;
    };
};
