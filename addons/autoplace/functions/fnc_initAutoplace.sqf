#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Parses and sanitises module settings.

    Parameters:
        0: Module logic <OBJECT>

    Return Value:
        Settings array

    Example:
        [_logic] call uksf_autoplace_fnc_initBuildingOccupation
*/
params ["_logic"];

private _unitListRaw = _logic getVariable [QGVAR(unitListString), []];
private _unitList = [_unitListRaw] call EFUNC(common,convertToArray);
_unitList = _unitList select {_x isEqualType "" && {_x != ""}};

private _helperClassnamesRaw = _logic getVariable [QGVAR(helperClassnamesString), []];
private _helperClassnames = [_helperClassnamesRaw] call EFUNC(common,convertToArray);
_helperClassnames = _helperClassnames select {_x isEqualType "" && {_x != ""}};

private _sideIndex = (_logic getVariable [QGVAR(side), 0]) max 0 min 2;
private _side = [east, independent, west]#_sideIndex;

private _coveragePercent = (_logic getVariable [QGVAR(coveragePercent), 100]) max 0 min 100;
private _enablePatrols = _logic getVariable [QGVAR(enablePatrols), false];
private _numberOfPatrols = (_logic getVariable [QGVAR(numberOfPatrols), 0]) max 0;
private _patrolRadius = (_logic getVariable [QGVAR(patrolRadius), 150]) max 1;
private _patrolSoldierCount = ((_logic getVariable [QGVAR(patrolSoldierCount), 4]) max 1) min 10;
private _occupyEmptyStatics = _logic getVariable [QGVAR(occupyEmptyStatics), false];

[
    _unitList,
    _helperClassnames,
    _side,
    _coveragePercent,
    _enablePatrols,
    _numberOfPatrols,
    _patrolRadius,
    _patrolSoldierCount,
    _occupyEmptyStatics
]
