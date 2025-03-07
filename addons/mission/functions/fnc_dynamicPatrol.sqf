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

[GVAR(dynamicPatrolDistance), GVAR(dynamicPatrolVehicleDistanceCoef)] call FUNC(cleanupDynamicPatrolGroups);

private _groupCount = count GVAR(dynamicPatrolGroups);
private _groupCountToAdd = round (random [GVAR(dynamicPatrolMinGroups), round (GVAR(dynamicPatrolMaxGroups) / 1.5) max GVAR(dynamicPatrolMinGroups), GVAR(dynamicPatrolMaxGroups) + 1]);

// Don't spawn more groups than the limit
if ((_groupCount + _groupCountToAdd) > GVAR(dynamicPatrolGroupLimit)) then {
    _groupCountToAdd = GVAR(dynamicPatrolGroupLimit) - _groupCount;
};

if (_groupCountToAdd > 0) then {
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
        GVAR(dynamicPatrolSide),
        QGVAR(dynamicPatrolStartDelay),
        {true}
    ];

    while {_groupCountToAdd > 0} do {
        [{
            [QGVAR(dynamicPatrolSpawn), _this] call EFUNC(common,headlessEvent);
        }, [_values], _groupCountToAdd * 2] call CBA_fnc_waitAndExecute;
        _groupCountToAdd = _groupCountToAdd - 1;
    };
};

[{
    [QGVAR(dynamicPatrol), []] call EFUNC(common,headlessEvent);
}, [], GVAR(dynamicPatrolCooldown)] call CBA_fnc_waitAndExecute;
