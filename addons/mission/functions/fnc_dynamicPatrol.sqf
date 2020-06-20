#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs basic dynamic patrol handling. Spawns groups of units and vehicles from a unit pool

    Parameters:
        None

    Return value:
        Nothing
*/

if !(GVAR(dynamicPatrolEnabled)) exitWith {};

[GVAR(dynamicPatrolDistance)] call FUNC(cleanupDynamicPatrolGroups);

if (count GVAR(dynamicPatrolGroups) > _groupLimit) exitWith {};

private _values = [
    GVAR(dynamicPatrolCooldown),
    GVAR(dynamicPatrolDistance),
    GVAR(dynamicPatrolGroupLimit),
    GVAR(dynamicPatrolMinUnits),
    GVAR(dynamicPatrolMaxUnits),
    GVAR(dynamicPatrolMinGroups),
    GVAR(dynamicPatrolMaxGroups),
    GVAR(dynamicPatrolVehicleProbability),
    GVAR(dynamicPatrolVehicleDistanceCoef),
    GVAR(dynamicPatrolWaypointDistance),
    GVAR(dynamicPatrolVehicleWaypointDistance),
    GVAR(dynamicPatrolUnitPool),
    GVAR(dynamicPatrolVehiclePool),
    GVAR(dynamicPatrolCombatMode),
    GVAR(dynamicPatrolSpeed),
    GVAR(dynamicPatrolSide)
];

private _groupCount = round (random [GVAR(dynamicPatrolMinGroups), round (GVAR(dynamicPatrolMaxGroups) / 1.5) max GVAR(dynamicPatrolMinGroups), GVAR(dynamicPatrolMaxGroups) + 1]);
while {_groupCount > 0} do {
    [{
        [QGVAR(dynamicPatrolSpawn), _this, selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
    }, [_values], _groupCount * 2] call CBA_fnc_waitAndExecute;
    _groupCount = _groupCount - 1;
};

[{call FUNC(dynamicPatrol)}, [], GVAR(dynamicPatrolCooldown)] call CBA_fnc_waitAndExecute;
