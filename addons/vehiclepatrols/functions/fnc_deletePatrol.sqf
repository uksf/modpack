#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Deletes patrol vehicle, crew group, passenger group, and tracking state.

    Parameters:
        0: Vehicle <OBJECT>
        1: Crew group <GROUP>
        2: Passenger group <GROUP>

    Return Value:
        Nothing

    Example:
        [_vehicle, _crewGroup, _passengerGroup] call uksf_vehiclepatrols_fnc_deletePatrol
*/

params [
    ["_vehicle", objNull, [objNull]],
    ["_crewGroup", grpNull, [grpNull]],
    ["_passengerGroup", grpNull, [grpNull]]
];

private _unitsToDelete = [];

if !(isNull _crewGroup) then {
    {
        _unitsToDelete pushBackUnique _x;
    } forEach (units _crewGroup);
};

if !(isNull _passengerGroup) then {
    {
        _unitsToDelete pushBackUnique _x;
    } forEach (units _passengerGroup);
};

if !(isNull _vehicle) then {
    {
        _unitsToDelete pushBackUnique _x;
    } forEach (crew _vehicle);
};

{
    if !(isNull _x) then {
        deleteVehicle _x;
    };
} forEach _unitsToDelete;

if !(isNull _vehicle) then {
    deleteVehicle _vehicle;
};

if !(isNull _crewGroup) then {
    deleteGroup _crewGroup;
};

if !(isNull _passengerGroup) then {
    deleteGroup _passengerGroup;
};

GVAR(activePatrols) = GVAR(activePatrols) select {
    (_x#0) isNotEqualTo _vehicle
};
