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
TRACE_2("Mission registered",_missionType,count GVAR(activeMissions));

// Deleted fires while the object is still valid, so vehicle identity still
// matches. PFH/RTB paths do not see a later objNull if they already exited.
if (!isNull _vehicle) then {
    _vehicle addEventHandler ["Deleted", {
        params ["_vehicle"];
        private _index = GVAR(activeMissions) findIf {(_x select 1) isEqualTo _vehicle};
        if (_index isEqualTo -1) exitWith {};
        private _group = (GVAR(activeMissions) select _index) select 0;
        [_group, _vehicle] call FUNC(unregisterMission);
        if (!isNull _group) then { deleteGroup _group };
    }];
};
