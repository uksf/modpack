#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Spawn one group from catalog entry, applying staging and force-pool rules.

    Parameters:
        0: Commander module <OBJECT>
        1: Queue entry <HASHMAP>
        2: Catalog entry <HASHMAP>

    Return Value:
        [Success <BOOL>, Reason <STRING>, Group <GROUP>, Staging objective <OBJECT>] <ARRAY>
*/

params [
    ["_commander", objNull, [objNull]],
    ["_queueEntry", createHashMap, [createHashMap]],
    ["_catalogEntry", createHashMap, [createHashMap]]
];

if (isNull _commander) exitWith {[false, "no_commander", grpNull, objNull]};
if (_queueEntry isEqualTo createHashMap || {_catalogEntry isEqualTo createHashMap}) exitWith {
    [false, "bad_inputs", grpNull, objNull]
};

private _targetObjectiveName = _queueEntry getOrDefault ["targetObjectiveName", ""];
private _actionId = _queueEntry getOrDefault ["actionId", "unknown"];
private _actionType = _queueEntry getOrDefault ["actionType", "reinforce"];

private _stagingObjective = [_commander, _targetObjectiveName] call FUNC(findStagingObjective);
if (isNull _stagingObjective) exitWith {[false, "no_staging_objective", grpNull, objNull]};

private _poolCurrent = _stagingObjective getVariable [QGVAR(forcePoolGroups), 0];
if (_poolCurrent < 1) exitWith {[false, "staging_pool_empty", grpNull, _stagingObjective]};

private _spawnPos = [_stagingObjective] call FUNC(pickSafeSpawnPos);
private _side = _commander getVariable [QGVAR(side), sideUnknown];

private _groupCfg = configFile
    >> "CfgGroups"
    >> (_catalogEntry getOrDefault ["sideCfgName", ""])
    >> (_catalogEntry getOrDefault ["faction", ""])
    >> (_catalogEntry getOrDefault ["category", ""])
    >> (_catalogEntry getOrDefault ["groupClass", ""]);

if (!isClass _groupCfg) exitWith {[false, "group_cfg_missing", grpNull, _stagingObjective]};

private _groupType = _catalogEntry getOrDefault ["type", "man"];
if (_groupType isEqualTo "unsupported") exitWith {[false, "unsupported_group_type", grpNull, _stagingObjective]};

private _group = switch (_groupType) do {
    case "car": {[_spawnPos, _side, _groupCfg] call FUNC(spawnGroupCar)};
    case "apc": {[_spawnPos, _side, _groupCfg] call FUNC(spawnGroupAPC)};
    case "tank": {[_spawnPos, _side, _groupCfg] call FUNC(spawnGroupTank)};
    default {[_spawnPos, _side, _groupCfg] call FUNC(spawnGroupMan)};
};

if (isNull _group || {isNull leader _group}) exitWith {[false, "spawn_failed", grpNull, _stagingObjective]};

_stagingObjective setVariable [QGVAR(forcePoolGroups), (_poolCurrent - 1) max 0, true];

private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
_managedGroups pushBack (createHashMapFromArray [
    ["group", _group],
    ["actionId", _actionId],
    ["actionType", _actionType],
    ["groupType", _groupType],
    ["targetObjectiveName", _targetObjectiveName],
    ["spawnedAt", if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}],
    ["stagingObjective", _stagingObjective]
]);
_commander setVariable [QGVAR(managedGroups), _managedGroups];

_group setVariable [QGVAR(commander), _commander];
_group setVariable [QGVAR(actionId), _actionId];
_group setVariable [QGVAR(targetObjectiveName), _targetObjectiveName];

private _targetObjective = objNull;
{
    if ((_x getVariable [QGVAR(objectiveName), ""]) isEqualTo _targetObjectiveName) exitWith {
        _targetObjective = _x;
    };
} forEach (synchronizedObjects _commander);

if (!isNull _targetObjective) then {
    private _wp = _group addWaypoint [getPosATL _targetObjective, 0];
    _wp setWaypointType "MOVE";
};

[true, "spawned", _group, _stagingObjective]
