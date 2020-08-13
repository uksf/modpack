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
_values params ["_cooldown", "_distance", "_groupLimit", "", "", "_minGroups", "_maxGroups"];

if !(GVAR(dynamicPatrolAreasEnabled)) exitWith {};

[GVAR(dynamicPatrolDistance), _logic, _distance] call FUNC(cleanupDynamicPatrolGroups);

private _areaGroups = _logic getVariable [QGVAR(groups), []];
if (count _areaGroups > _groupLimit || count GVAR(dynamicPatrolGroups) > GVAR(dynamicPatrolGroupLimit)) exitWith {};

private _groupCount = round (random [_minGroups, round (_maxGroups / 1.5) max _minGroups, _maxGroups + 1]);
while {_groupCount > 0} do {
    [{call FUNC(dynamicPatrolSpawn)}, _this, _groupCount * 2] call CBA_fnc_waitAndExecute;
    _groupCount = _groupCount - 1;
};

[{call FUNC(dynamicPatrolArea)}, _this, _cooldown] call CBA_fnc_waitAndExecute;
