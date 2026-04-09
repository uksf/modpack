#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs optional static occupancy and patrol spawning after garrison spawn completes.

    Parameters:
        0: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_logic] call uksf_autoplace_fnc_finaliseOccupation
*/
params ["_logic"];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_logic getVariable [QGVAR(finalised), false]) exitWith {};

_logic setVariable [QGVAR(finalised), true, false];

private _area = _logic getVariable [QGVAR(finaliseArea), []];
private _side = _logic getVariable [QGVAR(finaliseSide), east];
private _unitList = _logic getVariable [QGVAR(finaliseUnitList), []];
private _occupyEmptyStatics = _logic getVariable [QGVAR(finaliseOccupyEmptyStatics), false];
private _enablePatrols = _logic getVariable [QGVAR(finaliseEnablePatrols), false];
private _numberOfPatrols = _logic getVariable [QGVAR(finaliseNumberOfPatrols), 0];
private _patrolRadius = _logic getVariable [QGVAR(finalisePatrolRadius), 150];
private _patrolSoldierCount = _logic getVariable [QGVAR(finalisePatrolSoldierCount), 4];

if (_occupyEmptyStatics) then {
    [_logic, _area, _side, _unitList] call FUNC(occupyEmptyStatics);
};

if (_enablePatrols && {_numberOfPatrols > 0}) then {
    [_logic, _numberOfPatrols, _side, _unitList, _patrolRadius, _patrolSoldierCount] call FUNC(spawnPatrolGroups);
};
