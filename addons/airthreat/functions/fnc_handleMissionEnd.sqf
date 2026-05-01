#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles non-RTB mission termination. Always unregisters the mission.
        If the vehicle is dead or null, deletes the group (wreck handled by
        uksf_cleanup). If the vehicle is alive but the pilot is gone, marks
        it as orphaned for the commander loop to sweep up after the orphan
        timeout. Server only.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle] call uksf_airthreat_fnc_handleMissionEnd
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]]];

if !(isServer) exitWith {};

[QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_localEvent;

if (isNull _vehicle || {!alive _vehicle}) exitWith {
    if (!isNull _group) then { deleteGroup _group };
};

_vehicle setVariable [QGVAR(orphanedAt), time];
GVAR(orphanedAircraft) pushBack [_group, _vehicle];
