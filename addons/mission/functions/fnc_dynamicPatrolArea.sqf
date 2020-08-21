#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs area dynamic patrol handling. Spawns groups of units and vehicles from a pool. Respects global spawning limits
        Called by dynamic patrol area module

    Parameters:
        0: Values <ARRAY>
        1: Logic <OBJECT>
        2: Area <ARRAY>

    Return value:
        Nothing
*/
params ["_values", "_logic", "_area"];
_values params ["_cooldown", "_distance", "_groupLimit", "", "", "_minGroups", "_maxGroups", "", "_vehicleDistanceCoef"];

if !(GVAR(dynamicPatrolAreasEnabled)) exitWith {};

[_distance, _vehicleDistanceCoef, _logic] call FUNC(cleanupDynamicPatrolGroups);
[GVAR(dynamicPatrolDistance), GVAR(dynamicPatrolVehicleDistanceCoef)] call FUNC(cleanupDynamicPatrolGroups);

private _areaGroupCount = count (_logic getVariable [QGVAR(groups), []]);
private _addGroupCount = round (random [_minGroups, round (_maxGroups / 1.5) max _minGroups, _maxGroups + 1]);
if ((_areaGroupCount + _addGroupCount) < _groupLimit && count GVAR(dynamicPatrolGroups) < GVAR(dynamicPatrolGroupLimit)) then {
    while {_addGroupCount > 0} do {
        [{call FUNC(dynamicPatrolSpawn)}, _this, _addGroupCount * 2] call CBA_fnc_waitAndExecute;
        _addGroupCount = _addGroupCount - 1;
    };
};

[{call FUNC(dynamicPatrolArea)}, _this, _cooldown] call CBA_fnc_waitAndExecute;
