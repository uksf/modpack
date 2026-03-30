#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an active air threat mission for tracking.
        Sets the mission type on the group and adds to active missions.
        Server only.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>
        2: Mission type <STRING> - "cap", "recon", "cas", "strike", "intercept"
        3: Zone index <NUMBER> - Index into interceptZones for per-zone tracking (default: -1)

    Return Value:
        Nothing

    Example:
        [_group, _vehicle, "cap"] call uksf_airthreat_fnc_registerMission
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]], ["_missionType", "", [""]], ["_zoneData", -1, [0]]];

_group setVariable [QGVAR(missionType), _missionType, true];

GVAR(activeMissions) pushBack [_group, _vehicle, _missionType, _zoneData];
INFO_2("Mission registered: %1 (active: %2)",_missionType,count GVAR(activeMissions));
