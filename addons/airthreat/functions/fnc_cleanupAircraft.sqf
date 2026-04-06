#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Cleans up a spawned air threat aircraft and its crew.
        Deletes the vehicle and all crew members.
        Called on HC where the aircraft is local.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle] call uksf_airthreat_fnc_cleanupAircraft
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]]];

if (!isNull _vehicle) then {
    {
        deleteVehicle _x;
    } forEach (crew _vehicle);
    deleteVehicle _vehicle;
};

if (!isNull _group) then {
    {
        deleteVehicle _x;
    } forEach (units _group);
    deleteGroup _group;
};
