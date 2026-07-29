#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Executes one-shot autoplace orchestration for statics, garrisons, then patrols.

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>

    Return Value:
        Nothing

    Example:
        [_logic, _area] call uksf_autoplace_fnc_runAutoplace
*/
params ["_logic", "_area"];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_area isEqualTo []) exitWith {};

private _unitListRaw = _logic getVariable [QGVAR(unitListString), []];
private _unitList = [_unitListRaw] call EFUNC(common,convertToArray);
_unitList = _unitList select {_x isEqualType "" && {_x isNotEqualTo ""}};

private _sideIndex = (_logic getVariable [QGVAR(side), 0]) max 0 min 2;
private _side = [east, independent, west]#_sideIndex;

private _coveragePercent = (_logic getVariable [QGVAR(coveragePercent), 100]) max 0 min 100;
private _enablePatrols = _logic getVariable [QGVAR(enablePatrols), false];
private _numberOfPatrols = (_logic getVariable [QGVAR(numberOfPatrols), 0]) max 0;
private _patrolRadius = (_logic getVariable [QGVAR(patrolRadius), 150]) max 1;
private _patrolSoldierCount = ((_logic getVariable [QGVAR(patrolSoldierCount), 4]) max 1) min 10;
private _occupyEmptyStatics = _logic getVariable [QGVAR(occupyEmptyStatics), false];

if (_unitList isEqualTo []) exitWith {
    WARNING_1("Autoplace module has no unit list: %1",_logic);
};

private _garrisonPositions = [_logic, _area] call FUNC(gatherPositions);
[_garrisonPositions, true] call CBA_fnc_shuffle;

if (_coveragePercent < 100) then {
    private _targetCount = floor ((count _garrisonPositions) * (_coveragePercent / 100));
    _garrisonPositions resize _targetCount;
};

private _onGarrisonsDone = {
    params [
        "_logic",
        "_area",
        "_enablePatrols",
        "_numberOfPatrols",
        "_side",
        "_unitList",
        "_patrolRadius",
        "_patrolSoldierCount"
    ];

    if (_enablePatrols && {_numberOfPatrols > 0}) then {
        [_logic, _area, _numberOfPatrols, _side, _unitList, _patrolRadius, _patrolSoldierCount] call FUNC(spawnPatrols);
    };
};

private _onGarrisonsDoneArgs = [
    _logic,
    _area,
    _enablePatrols,
    _numberOfPatrols,
    _side,
    _unitList,
    _patrolRadius,
    _patrolSoldierCount
];

private _startGarrisons = {
    params ["_logic", "_garrisonPositions", "_side", "_unitList", "_onGarrisonsDone", "_onGarrisonsDoneArgs"];

    if (_garrisonPositions isEqualTo []) then {
        _onGarrisonsDoneArgs call _onGarrisonsDone;
    } else {
        [_logic, _garrisonPositions, _side, _unitList, _onGarrisonsDone, _onGarrisonsDoneArgs] call FUNC(spawnGarrisons);
    };
};

private _startGarrisonsArgs = [_logic, _garrisonPositions, _side, _unitList, _onGarrisonsDone, _onGarrisonsDoneArgs];

if (_occupyEmptyStatics) then {
    [_logic, _area, _side, _unitList, _startGarrisons, _startGarrisonsArgs] call FUNC(occupyStatics);
} else {
    _startGarrisonsArgs call _startGarrisons;
};
