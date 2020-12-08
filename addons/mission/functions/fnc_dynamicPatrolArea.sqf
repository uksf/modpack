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

if !(alive _logic) exitWith {
    TRACE_1("4) Area failed alive check, won't queue execution",alive _logic);
};

if !(GVAR(dynamicPatrolAreasEnabled)) exitWith {
    TRACE_1("4) Area failed enabled check, re-queueing execution",GVAR(dynamicPatrolAreasEnabled));
    [{
        [QGVAR(dynamicPatrolArea), _this, selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
    }, _this, _cooldown] call CBA_fnc_waitAndExecute;
};

TRACE_1("4) Area data",_this);

TRACE_2("4) Area pre-cleanup groups",GVAR(dynamicPatrolGroups),_logic getVariable [QGVAR(groups), []]);
[_distance, _vehicleDistanceCoef, _logic] call FUNC(cleanupDynamicPatrolGroups);
[GVAR(dynamicPatrolDistance), GVAR(dynamicPatrolVehicleDistanceCoef)] call FUNC(cleanupDynamicPatrolGroups);
TRACE_2("4) Area post-cleanup groups",GVAR(dynamicPatrolGroups),_logic getVariable [QGVAR(groups), []]);

private _areaGroupCount = count (_logic getVariable [QGVAR(groups), []]);
private _globalGroupCount = count GVAR(dynamicPatrolGroups);
private _groupCountToAdd = round (random [_minGroups, round (_maxGroups / 1.5) max _minGroups, _maxGroups + 1]);
TRACE_3("4) Area group counts",_areaGroupCount,_globalGroupCount,_groupCountToAdd);

// Don't spawn more groups than the area limit
if ((_areaGroupCount + _groupCountToAdd) > _groupLimit) then {
    _groupCountToAdd = _groupLimit - _areaGroupCount;
};
TRACE_3("4) Area group counts post-area limit",_areaGroupCount,_globalGroupCount,_groupCountToAdd);

// Don't spawn more groups than the global limit
if ((_globalGroupCount + _groupCountToAdd) > GVAR(dynamicPatrolGroupLimit)) then {
    _groupCountToAdd = GVAR(dynamicPatrolGroupLimit) - _globalGroupCount;
};
TRACE_3("4) Area group counts post-global limit",_areaGroupCount,_globalGroupCount,_groupCountToAdd);

if (_groupCountToAdd > 0) then {
    while {_groupCountToAdd > 0} do {
        TRACE_1("4) Area group iteration",_groupCountToAdd);
        [{call FUNC(dynamicPatrolSpawn)}, _this, _groupCountToAdd * 2] call CBA_fnc_waitAndExecute;
        _groupCountToAdd = _groupCountToAdd - 1;
    };
};

[{
    [QGVAR(dynamicPatrolArea), _this, selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
}, _this, _cooldown] call CBA_fnc_waitAndExecute;
