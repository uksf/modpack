#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an active air threat mission for tracking.
        Sets the mission type on the group and notifies the server.
        Can be called from HC or server.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>
        2: Mission type <STRING> - "cap", "recon", "cas", "strike", "intercept"

    Return Value:
        Nothing

    Example:
        [_group, _vehicle, "cap"] call uksf_airthreat_fnc_registerMission
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]], ["_missionType", "", [""]]];

_group setVariable [QGVAR(missionType), _missionType, true];

// Server tracks active missions — fire event if called from HC
if (isServer) then {
    GVAR(activeMissions) pushBack [_group, _vehicle, _missionType];
    INFO_2("Mission registered: %1 (active: %2)",_missionType,count GVAR(activeMissions));
} else {
    [QGVAR(registerMission), [_group, _vehicle, _missionType]] call CBA_fnc_serverEvent;
};
