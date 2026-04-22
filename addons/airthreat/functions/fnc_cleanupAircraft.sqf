#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Cleans up a spawned air threat aircraft and its crew.
        Only deletes if alive (RTB despawn or abandoned) — destroyed
        aircraft are left to uksf_cleanup so wreckage persists.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle] call uksf_airthreat_fnc_cleanupAircraft
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]]];

if (!isNull _vehicle && {alive _vehicle}) then {
    {
        deleteVehicle _x;
    } forEach (crew _vehicle);
    deleteVehicle _vehicle;
};

if (!isNull _group) then {
    {
        if (alive _x) then {
            deleteVehicle _x;
        };
    } forEach (units _group);
    deleteGroup _group;
};
