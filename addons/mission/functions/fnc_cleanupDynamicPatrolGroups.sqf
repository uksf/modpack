#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Cleans up dynamic patrol groups

    Parameters:
        0: Distance <SCALAR>
        1: Vehicle distance coef <SCALAR>
        2: Area Logic (Optional) <OBJECT>

    Return value:
        Nothing
*/
params ["_distance", "_vehicleDistanceCoef", ["_logic", objNull]];

if (!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled)) exitWith {};

private _groups = [_logic getVariable [QGVAR(groups), []], GVAR(dynamicPatrolGroups)] select (isNull _logic);
_groups = _groups - [grpNull];

_groupsToDelete = _groups select {
    private _distanceForGroup = _distance * 1.5;
    if !(isNull (_x getVariable [QGVAR(assignedVehicle), objNull])) then {
        _distanceForGroup = _distanceForGroup * _vehicleDistanceCoef;
    };

    !([units _x, {alive _x}] call EFUNC(common,arrayAny))
    || !([getPosATL (leader _x), _distanceForGroup] call EFUNC(common,anyNearPlayers))
};

{
    _groups deleteAt (_groups find _x);
    (_x getVariable [QGVAR(assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
    _x call CBA_fnc_deleteEntity;
} forEach _groupsToDelete;

if !(isNull _logic) then {
    _logic setVariable [QGVAR(groups), _groups, true];
} else {
    GVAR(dynamicPatrolGroups) = _groups;
    publicVariable QGVAR(dynamicPatrolGroups);
};
