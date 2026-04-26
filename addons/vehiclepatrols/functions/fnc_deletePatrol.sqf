#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Deletes patrol vehicle and its crew. Crew group is auto-deleted by the engine
        when empty (created with deleteWhenEmpty in spawnPatrol).

    Parameters:
        0: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_vehicle] call uksf_vehiclepatrols_fnc_deletePatrol
*/

params [
    ["_vehicle", objNull, [objNull]]
];

deleteVehicleCrew _vehicle;
deleteVehicle _vehicle;
