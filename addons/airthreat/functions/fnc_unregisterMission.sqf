#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes an air threat mission from active tracking.
        Server only.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle] call uksf_airthreat_fnc_unregisterMission
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]]];

if !(isServer) exitWith {};

private _index = GVAR(activeMissions) findIf {(_x select 0) isEqualTo _group};
if (_index isEqualTo -1) exitWith {};

private _missionType = (GVAR(activeMissions) select _index) select 2;
GVAR(activeMissions) deleteAt _index;

INFO_2("Mission unregistered: %1 (active: %2)",_missionType,count GVAR(activeMissions));
