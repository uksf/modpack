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

deleteVehicleCrew _vehicle;
deleteVehicle _vehicle;

if !(isNull _crewGroup) then { deleteGroup _crewGroup; };
if !(isNull _passengerGroup) then { deleteGroup _passengerGroup; };

GVAR(activePatrols) = GVAR(activePatrols) select {
    (_x#0) isNotEqualTo _vehicle
};
