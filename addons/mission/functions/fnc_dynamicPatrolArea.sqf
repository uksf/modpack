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
private _globalGroupCount = count GVAR(dynamicPatrolGroups);
private _groupCountToAdd = round (random [_minGroups, round (_maxGroups / 1.5) max _minGroups, _maxGroups + 1]);

// Don't spawn more groups than the area limit
if ((_areaGroupCount + _groupCountToAdd) > _groupLimit) then {
    _groupCountToAdd = _groupLimit - _areaGroupCount;
};

// Don't spawn more groups than the global limit
if ((_globalGroupCount + _groupCountToAdd) > GVAR(dynamicPatrolGroupLimit)) then {
    _groupCountToAdd = GVAR(dynamicPatrolGroupLimit) - _globalGroupCount;
};

if (_groupCountToAdd > 0) then {
    while {_groupCountToAdd > 0} do {
        [{call FUNC(dynamicPatrolSpawn)}, _this, _groupCountToAdd * 2] call CBA_fnc_waitAndExecute;
        _groupCountToAdd = _groupCountToAdd - 1;
    };
};

[{call FUNC(dynamicPatrolArea)}, _this, _cooldown] call CBA_fnc_waitAndExecute;
