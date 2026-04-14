#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Executes one-shot building occupation and optional patrol/static occupancy.

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>

    Return Value:
        Nothing

    Example:
        [_logic, _area] call uksf_autoplace_fnc_runBuildingOccupation
*/
params ["_logic", "_area"];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_area isEqualTo []) exitWith {};

private _settings = [_logic] call FUNC(initAutoplace);
_settings params [
    "_unitList",
    "_side",
    "_coveragePercent",
    "_enablePatrols",
    "_numberOfPatrols",
    "_patrolRadius",
    "_patrolSoldierCount",
    "_occupyEmptyStatics"
];

if (_unitList isEqualTo []) exitWith {
    WARNING_1("Building occupation module has no unit list: %1",_logic);
};

private _centre = getPosATL _logic;
_area params ["_areaRadiusA", "_areaRadiusB"];
private _searchRadius = (_areaRadiusA max _areaRadiusB) + 25;

private _helperObjects = nearestObjects [_centre, ["CBA_BuildingPos"], _searchRadius, true];
_helperObjects = _helperObjects select {[_x, _centre, _area] call EFUNC(common,objectInArea)};

private _positionMap = createHashMap;
private _availablePositions = [];
{
    params ["_helperObject"];
    private _position = getPosATL _helperObject;
    private _direction = getDir _helperObject;
    private _key = format ["%1_%2_%3", round ((_position#0) * 10), round ((_position#1) * 10), round ((_position#2) * 10)];
    if !(_positionMap getOrDefault [_key, false]) then {
        _positionMap set [_key, true];
        _availablePositions pushBack [_position, _direction];
    };
} forEach _helperObjects;

[_availablePositions, true] call CBA_fnc_shuffle;

_logic setVariable [QGVAR(availablePositions), _availablePositions, false];
_logic setVariable [QGVAR(finalised), false, false];
_logic setVariable [QGVAR(finaliseArea), _area, false];
_logic setVariable [QGVAR(finaliseSide), _side, false];
_logic setVariable [QGVAR(finaliseUnitList), _unitList, false];
_logic setVariable [QGVAR(finaliseEnablePatrols), _enablePatrols, false];
_logic setVariable [QGVAR(finaliseNumberOfPatrols), _numberOfPatrols, false];
_logic setVariable [QGVAR(finalisePatrolRadius), _patrolRadius, false];
_logic setVariable [QGVAR(finalisePatrolSoldierCount), _patrolSoldierCount, false];

private _targetCount = floor ((count _availablePositions) * (_coveragePercent / 100));
_targetCount = _targetCount min (count _availablePositions);

if (_occupyEmptyStatics) then {
    [_logic, _area, _side, _unitList] call FUNC(occupyEmptyStatics);
};

if (_targetCount > 0) then {
    [_logic, _targetCount, _side, _unitList] call FUNC(spawnGarrisonGroups);
} else {
    [_logic] call FUNC(finaliseAutoplace);
};
