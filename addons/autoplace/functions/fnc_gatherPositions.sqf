#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gathers de-duplicated helper positions in module area.

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>

    Return Value:
        Position data array [[positionATL, direction], ...] <ARRAY>

    Example:
        [_logic, _area] call uksf_autoplace_fnc_gatherPositions
*/
params ["_logic", "_area"];

if (isNull _logic) exitWith {[]};
if (_area isEqualTo []) exitWith {[]};

private _centre = getPosATL _logic;
_area params ["_areaRadiusA", "_areaRadiusB"];
private _searchRadius = (_areaRadiusA max _areaRadiusB) + 25;

private _helperObjects = nearestObjects [_centre, ["CBA_BuildingPos"], _searchRadius, true];
_helperObjects = _helperObjects select {[_x, _centre, _area] call EFUNC(common,objectInArea)};

private _positionMap = createHashMap;
private _positions = [];
{
    private _position = getPosATL _x;
    private _direction = getDir _x;
    private _key = format ["%1_%2_%3", round ((_position#0) * 10), round ((_position#1) * 10), round ((_position#2) * 10)];

    if !(_positionMap getOrDefault [_key, false]) then {
        _positionMap set [_key, true];
        _positions pushBack [_position, _direction];
    };
} forEach _helperObjects;

_positions
