#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Finalize one delayed contact session and emit CONTACT_REPORT/intel updates.

    Parameters:
        0: Commander module <OBJECT>
        1: Group key <STRING>

    Return Value:
        None
*/

params [
    ["_commander", objNull, [objNull]],
    ["_groupKey", "", [""]]
];

if (isNull _commander || {_groupKey isEqualTo ""}) exitWith {};

private _sessions = _commander getVariable [QGVAR(contactSessions), createHashMap];
if !(_sessions isEqualType createHashMap) exitWith {};

private _session = _sessions getOrDefault [_groupKey, createHashMap];
if !(_session isEqualType createHashMap) exitWith {};
if (_session isEqualTo createHashMap) exitWith {};

_session set ["confirmPending", false];

private _group = _session getOrDefault ["group", grpNull];
if (isNull _group) exitWith {
    _sessions deleteAt _groupKey;
    _commander setVariable [QGVAR(contactSessions), _sessions];
};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _aliveUnits = units _group select {alive _x};
if (_aliveUnits isEqualTo []) exitWith {
    _session set ["nextReportEligibleAt", _now + ((_commander getVariable [QGVAR(followupContactCooldownSec), 30]) max 5)];
    _session set ["shooters", createHashMap];
    _sessions set [_groupKey, _session];
    _commander setVariable [QGVAR(contactSessions), _sessions];
};

private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
private _entry = createHashMap;
private _entryIndex = _managedGroups findIf {(_x getOrDefault ["group", grpNull]) isEqualTo _group};
if (_entryIndex >= 0) then {_entry = _managedGroups#_entryIndex;};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _gridCellSize = _commander getVariable [QGVAR(gridCellSize), 500];

private _enemyByGroup = createHashMap;
private _seenUnitKeys = createHashMap;
private _seenGroupKeys = createHashMap;

private _fnc_addObserved = {
    params ["_entity", "_fromShooter", "_fromKnown"];
    if (isNull _entity || {!alive _entity}) exitWith {};

    private _unit = if (_entity isKindOf "Man") then {_entity} else {
        private _crew = crew _entity;
        if (_crew isEqualTo []) then {objNull} else {_crew#0}
    };

    private _side = if (!isNull _unit) then {side _unit} else {side _entity};
    if (_side isEqualTo _commanderSide || {_side isEqualTo sideUnknown}) exitWith {};

    private _group = if (!isNull _unit) then {group _unit} else {grpNull};
    private _groupKeyInner = if (isNull _group) then {format ["obj:%1", str _entity]} else {str _group};
    private _entryInner = _enemyByGroup getOrDefault [_groupKeyInner, createHashMap];
    if (_entryInner isEqualTo createHashMap) then {
        private _pos = getPosATL _entity;
        private _pos2D = [_pos#0, _pos#1];
        _entryInner = createHashMapFromArray [
            ["groupKey", _groupKeyInner],
            ["type", [_entity] call FUNC(classifyContactType)],
            ["unitCount", 0],
            ["fromShooter", false],
            ["fromKnownTargets", false],
            ["vehicleClass", if (vehicle _entity isEqualTo _entity) then {typeOf _entity} else {typeOf (vehicle _entity)}],
            ["position2D", _pos2D],
            ["grid", [_pos2D, _gridCellSize] call FUNC(getGridCoord)]
        ];
    };

    private _unitKey = if (!isNull _unit) then {str _unit} else {str _entity};
    if !(_seenUnitKeys getOrDefault [_unitKey, false]) then {
        _seenUnitKeys set [_unitKey, true];
        _entryInner set ["unitCount", (_entryInner getOrDefault ["unitCount", 0]) + 1];
    };

    if !(_seenGroupKeys getOrDefault [_groupKeyInner, false]) then {
        _seenGroupKeys set [_groupKeyInner, true];
    };

    if (_fromShooter) then {_entryInner set ["fromShooter", true];};
    if (_fromKnown) then {_entryInner set ["fromKnownTargets", true];};

    _enemyByGroup set [_groupKeyInner, _entryInner];
};

private _shooters = _session getOrDefault ["shooters", createHashMap];
if (_shooters isEqualType createHashMap) then {
    {
        private _obs = _shooters getOrDefault [_x, createHashMap];
        private _obsUnit = _obs getOrDefault ["unit", objNull];
        [_obsUnit, true, false] call _fnc_addObserved;
    } forEach keys _shooters;
};

{
    [_x, false, true] call _fnc_addObserved;
} forEach ([_group, _commanderSide] call FUNC(collectKnownEnemyObjects));

private _enemyEntries = [];
{
    _enemyEntries pushBack (_enemyByGroup getOrDefault [_x, createHashMap]);
} forEach keys _enemyByGroup;

if (_enemyEntries isEqualTo []) exitWith {
    _session set ["shooters", createHashMap];
    _sessions set [_groupKey, _session];
    _commander setVariable [QGVAR(contactSessions), _sessions];
};

private _primaryEnemy = _enemyEntries findIf {_x getOrDefault ["fromShooter", false]};
if (_primaryEnemy < 0) then {
    _primaryEnemy = _enemyEntries findIf {_x getOrDefault ["fromKnownTargets", false]};
};
if (_primaryEnemy < 0) then {_primaryEnemy = 0;};
private _primaryEnemyEntry = _enemyEntries#_primaryEnemy;
private _enemyGroupKeyPrimary = _primaryEnemyEntry getOrDefault ["groupKey", "unknown"];
private _enemyPosPrimary = _primaryEnemyEntry getOrDefault ["position2D", [0, 0]];
private _enemyGridPrimary = _primaryEnemyEntry getOrDefault ["grid", [0, 0]];

private _unitsTotal = 0;
{
    _unitsTotal = _unitsTotal + (_x getOrDefault ["unitCount", 0]);
} forEach _enemyEntries;

private _groupsTotal = count _enemyEntries;
private _groupsFromShooter = {
    _x getOrDefault ["fromShooter", false]
} count _enemyEntries;
private _groupsFromKnown = {
    _x getOrDefault ["fromKnownTargets", false]
} count _enemyEntries;
private _typeCounts = createHashMapFromArray [
    ["man", 0],
    ["car", 0],
    ["apc", 0],
    ["tank", 0],
    ["air", 0],
    ["other", 0]
];

{
    private _type = _x getOrDefault ["type", "other"];
    _typeCounts set [_type, (_typeCounts getOrDefault [_type, 0]) + (_x getOrDefault ["unitCount", 0])];

    private _grid = _x getOrDefault ["grid", []];
    if (_grid isEqualType [] && {count _grid >= 2}) then {
        [_commander, _grid, "enemy_present", createHashMapFromArray [
            ["enemyUnits", _unitsTotal],
            ["enemyGroups", _groupsTotal],
            ["source", "contact_report"]
        ]] call FUNC(updateIntelGrid);
    };
} forEach _enemyEntries;

private _friendlyLeader = leader _group;
private _friendlyPos = if (!isNull _friendlyLeader) then {getPosATL _friendlyLeader} else {[0, 0, 0]};
private _friendlyPos2D = [_friendlyPos#0, _friendlyPos#1];
private _friendlyGrid = [_friendlyPos2D, _gridCellSize] call FUNC(getGridCoord);

["CONTACT_REPORT", _commander, createHashMapFromArray [
    ["actionId", _entry getOrDefault ["actionId", "none"]],
    ["reason", "engaged"],
    ["message", format [
        "group=%1 task=%2 target=%3 friendly_pos=%4,%5 friendly_grid=%6,%7 enemy_group=%8 enemy_pos=%9,%10 enemy_grid=%11,%12 enemy_groups=%13 enemy_units=%14 confidence{shooter:%15 known:%16} buckets{man:%17 car:%18 apc:%19 tank:%20 air:%21 other:%22}",
        _groupKey,
        _entry getOrDefault ["actionType", "none"],
        _entry getOrDefault ["targetObjectiveName", "none"],
        round (_friendlyPos2D#0),
        round (_friendlyPos2D#1),
        _friendlyGrid#0,
        _friendlyGrid#1,
        _enemyGroupKeyPrimary,
        round (_enemyPosPrimary#0),
        round (_enemyPosPrimary#1),
        _enemyGridPrimary#0,
        _enemyGridPrimary#1,
        _groupsTotal,
        _unitsTotal,
        _groupsFromShooter,
        _groupsFromKnown,
        _typeCounts getOrDefault ["man", 0],
        _typeCounts getOrDefault ["car", 0],
        _typeCounts getOrDefault ["apc", 0],
        _typeCounts getOrDefault ["tank", 0],
        _typeCounts getOrDefault ["air", 0],
        _typeCounts getOrDefault ["other", 0]
    ]]
]] call FUNC(logExecution);

private _cooldown = (_commander getVariable [QGVAR(followupContactCooldownSec), 30]) max 5;
_session set ["lastReportAt", _now];
_session set ["nextReportEligibleAt", _now + _cooldown];
_session set ["shooters", createHashMap];
_sessions set [_groupKey, _session];

{
    private _sessionInner = _sessions getOrDefault [_x, createHashMap];
    if !(_sessionInner isEqualType createHashMap) then {continue};
    if (_sessionInner isEqualTo createHashMap) then {continue};

    private _lastHitAt = _sessionInner getOrDefault ["lastHitAt", -1];
    private _pending = _sessionInner getOrDefault ["confirmPending", false];
    if (!_pending && {_lastHitAt > -1} && {(_now - _lastHitAt) > (_cooldown * 3)}) then {
        _sessions deleteAt _x;
    };
} forEach keys _sessions;

_commander setVariable [QGVAR(contactSessions), _sessions];
