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

if (!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled)) exitWith {
    TRACE_2("4.5) Groups cleanup failed enabled checks",GVAR(dynamicPatrolEnabled),GVAR(dynamicPatrolAreasEnabled));
};

TRACE_1("4.5) Groups cleanup data",_this);

private _groups = [_logic getVariable [QGVAR(groups), []], GVAR(dynamicPatrolGroups)] select (isNull _logic);
_groups = _groups - [grpNull];
TRACE_1("4.5) Groups cleanup groups",_groups);

_groupsToDelete = _groups select {
    private _distanceForGroup = _distance * 1.5;
    if !(isNull (_x getVariable [QGVAR(assignedVehicle), objNull])) then {
        _distanceForGroup = _distanceForGroup * _vehicleDistanceCoef;
    };

    !([units _x, {alive _x}] call EFUNC(common,arrayAny))
    || !([getPosATL (leader _x), _distanceForGroup] call EFUNC(common,anyNearPlayers))
};
TRACE_1("4.5) Groups cleanup groups to delete",_groupsToDelete);

{
    private _group = _x;
    _groups deleteAt (_groups find _group);

    private _aliveUnits = (units _group) select {alive _x}; // Let cleanup handle dead units
    TRACE_2("4.5) Groups cleanup alive units to delete",_group,_aliveUnits);
    _aliveUnits call CBA_fnc_deleteEntity;

    private _vehicle = _group getVariable [QGVAR(assignedVehicle), objNull];
    TRACE_1("4.5) Groups cleanup group vehicle",_vehicle);
    if (!(isNull _vehicle) && {alive _vehicle}) then {
        TRACE_1("4.5) Groups cleanup deleting group vehicle",_vehicle);
        (_group getVariable [QGVAR(assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
    };
} forEach _groupsToDelete;

if !(isNull _logic) then {
    TRACE_1("4.5) Groups cleanup setting logic groups",_groups);
    _logic setVariable [QGVAR(groups), _groups, true];
} else {
    TRACE_1("4.5) Groups cleanup setting global groups",_groups);
    GVAR(dynamicPatrolGroups) = _groups;
    publicVariable QGVAR(dynamicPatrolGroups);
};
