#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs basic dynamic patrol handling. Spawns groups of units and vehicles from a unit pool

    Parameters:
        0: Distance <SCALAR>
        1: Area Logic (Optional) <OBJECT>
        2: Area logic distance (Optional) <SCALAR>

    Return value:
        Nothing
*/
params ["_distance", ["_logic", objNull], ["_logicDistance", 750]];

if !(GVAR(dynamicPatrolEnabled)) exitWith {};

private _groupsToDelete = GVAR(dynamicPatrolGroups) select {
    isNull _x ||
    {!([getPosATL (leader _x), _distance * 2] call EFUNC(common,anyNearPlayers))}
};

{
    GVAR(dynamicPatrolGroups) deleteAt (GVAR(dynamicPatrolGroups) find _x);
    ((leader _x) getVariable [QGVAR(assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
    _x call CBA_fnc_deleteEntity;
} forEach _groupsToDelete;
publicVariable QGVAR(dynamicPatrolGroups);

if !(isNull _logic) then {
    private _areaGroups = _logic getVariable [QGVAR(groups), []];
    _groupsToDelete = _areaGroups select {
        isNull _x ||
        {!([getPosATL (leader _x), _logicDistance * 2] call EFUNC(common,anyNearPlayers))}
    };

    {
        _areaGroups deleteAt (_areaGroups find _x);
        ((leader _x) getVariable [QGVAR(assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
        _x call CBA_fnc_deleteEntity;
    } forEach _groupsToDelete;
    _logic setVariable [QGVAR(groups), _areaGroups, true];
};
