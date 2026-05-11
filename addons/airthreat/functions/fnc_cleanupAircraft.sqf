#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deletes a spawned air threat aircraft and its group, but only when
        the aircraft is alive — destroyed airframes are left to uksf_cleanup
        so wreckage persists naturally. Used by RTB waypoint completion and
        the stale-mission safety net. Non-RTB exits go through
        handleMissionEnd which routes alive-but-pilotless aircraft to the
        orphan sweep instead.

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
    deleteVehicleCrew _vehicle;
    deleteVehicle _vehicle;
};

if (!isNull _group) then { deleteGroup _group };
