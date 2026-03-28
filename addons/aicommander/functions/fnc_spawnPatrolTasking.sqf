#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Spawns one patrol group and assigns patrol waypoints around computed anchor.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_targetObjective", objNull, [objNull]],
    ["_stagingObjective", objNull, [objNull]],
    ["_catalogEntry", createHashMap, [createHashMap]]
];

if (isNull _commander || {isNull _targetObjective} || {isNull _stagingObjective}) exitWith {[false, "bad_inputs", grpNull]};
if (_catalogEntry isEqualTo createHashMap) exitWith {[false, "bad_catalog_entry", grpNull]};

private _targetObjectiveName = _targetObjective getVariable [QGVAR(objectiveName), ""];
if (_targetObjectiveName isEqualTo "") exitWith {[false, "missing_target_objective_name", grpNull]};

private _actionId = format ["PATROL|%1|%2", _targetObjectiveName, round (if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time})];
private _queueEntry = createHashMapFromArray [
    ["actionId", _actionId],
    ["actionType", "patrol"],
    ["targetObjectiveName", _targetObjectiveName],
    ["priority", 0],
    ["waveIndex", 1]
];

private _spawnResult = [_commander, _queueEntry, _catalogEntry] call FUNC(spawnGroupFromCatalog);
_spawnResult params ["_okSpawn", "_reasonSpawn", "_group"];
if (!_okSpawn || {isNull _group}) exitWith {[false, _reasonSpawn, grpNull]};

{
    deleteWaypoint _x;
} forEach waypoints _group;

private _spawnPosition = getPosATL (leader _group);
_spawnPosition set [2, 0];
private _targetPosition = getPosATL _targetObjective;
private _anchor = [_spawnPosition, _targetPosition] call FUNC(computePatrolAnchor);
if (_anchor isEqualTo []) then {
    _anchor = _targetPosition;
};
_anchor set [2, 0];

private _patrolDir = random 360;
private _patrolLegA = _anchor getPos [120, _patrolDir + 90];
private _patrolLegB = _anchor getPos [120, _patrolDir - 90];
_patrolLegA set [2, 0];
_patrolLegB set [2, 0];

private _wpAnchor = _group addWaypoint [_anchor, 0];
_wpAnchor setWaypointType "MOVE";
_wpAnchor setWaypointBehaviour "AWARE";
_wpAnchor setWaypointCombatMode "YELLOW";
_wpAnchor setWaypointSpeed "LIMITED";
_wpAnchor setWaypointFormation "WEDGE";

private _wpLegA = _group addWaypoint [_patrolLegA, 0];
_wpLegA setWaypointType "MOVE";
_wpLegA setWaypointBehaviour "AWARE";
_wpLegA setWaypointCombatMode "YELLOW";
_wpLegA setWaypointSpeed "LIMITED";

private _wpLegB = _group addWaypoint [_patrolLegB, 0];
_wpLegB setWaypointType "MOVE";
_wpLegB setWaypointBehaviour "AWARE";
_wpLegB setWaypointCombatMode "YELLOW";
_wpLegB setWaypointSpeed "LIMITED";

private _wpRtb = _group addWaypoint [_spawnPosition, 0];
_wpRtb setWaypointType "MOVE";
_wpRtb setWaypointBehaviour "SAFE";
_wpRtb setWaypointCombatMode "YELLOW";
_wpRtb setWaypointSpeed "FULL";
_wpRtb setWaypointStatements [
    "true",
    "(group this) setVariable [""uksf_aicommander_rtbStartedAt"", (if (!isNil ""CBA_missionTime"") then {CBA_missionTime} else {time})];"
];

[{
    params ["_args", "_idPFH"];
    _args params ["_groupPFH", "_spawnPosPFH", "_startedAtPFH"];

    if (isNull _groupPFH || {isNull leader _groupPFH} || {!alive leader _groupPFH}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
    private _rtbStartedAt = _groupPFH getVariable [QGVAR(rtbStartedAt), -1];
    if (_rtbStartedAt < 0) exitWith {};

    private _shouldCleanup = ((leader _groupPFH) distance2D _spawnPosPFH) <= 175 || {_now > (_startedAtPFH + 900)};
    if (!_shouldCleanup) exitWith {};

    [_idPFH] call CBA_fnc_removePerFrameHandler;
    private _vehicles = [];
    {
        private _veh = vehicle _x;
        if (!isNull _veh && {_veh isNotEqualTo _x}) then {
            _vehicles pushBackUnique _veh;
        };
        deleteVehicle _x;
    } forEach units _groupPFH;

    {
        deleteVehicle _x;
    } forEach _vehicles;
    deleteGroup _groupPFH;
}, 5, [_group, _spawnPosition, (if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time})]] call CBA_fnc_addPerFrameHandler;

private _managed = _commander getVariable [QGVAR(managedGroups), []];
private _idx = _managed findIf {(_x getOrDefault ["group", grpNull]) isEqualTo _group};
if (_idx >= 0) then {
    private _entry = _managed select _idx;
    _entry set ["staffRole", "patrol"];
    _entry set ["patrolAnchor", _anchor];
    _entry set ["patrolSpawnPosition", _spawnPosition];
    _entry set ["actionType", "patrol"];
    _managed set [_idx, _entry];
    _commander setVariable [QGVAR(managedGroups), _managed];
};

[true, "spawned", _group]
