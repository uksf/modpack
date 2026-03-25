#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Consume MPHit-derived unit hit events and track managed-group contact sessions.

    Parameters:
        0: Hit unit <OBJECT>
        1: Shooter <OBJECT>

    Return Value:
        None
*/

params [
    ["_unit", objNull, [objNull]],
    ["_shooter", objNull, [objNull]]
];

if (isNull _unit) exitWith {};

if (!isServer) exitWith {
    [QGVAR(hitRawForward), [_unit, _shooter]] call CBA_fnc_serverEvent;
};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _matchedCommander = objNull;
private _matchedGroup = grpNull;

{
    private _commander = _x;
    if (isNull _commander) then {continue};

    private _managed = _commander getVariable [QGVAR(managedGroups), []];
    private _entryIndex = _managed findIf {
        private _group = _x getOrDefault ["group", grpNull];
        !isNull _group && {_unit in units _group}
    };

    if (_entryIndex >= 0) exitWith {
        _matchedCommander = _commander;
        _matchedGroup = (_managed#_entryIndex) getOrDefault ["group", grpNull];
    };
} forEach GVAR(commanders);

if (isNull _matchedCommander || {isNull _matchedGroup}) exitWith {};

private _commanderSide = _matchedCommander getVariable [QGVAR(side), sideUnknown];
private _sessions = _matchedCommander getVariable [QGVAR(contactSessions), createHashMap];
if !(_sessions isEqualType createHashMap) then {_sessions = createHashMap;};

private _groupKey = str _matchedGroup;
private _session = _sessions getOrDefault [_groupKey, createHashMap];
if !(_session isEqualType createHashMap) then {_session = createHashMap;};

if (_session isEqualTo createHashMap) then {
    _session = createHashMapFromArray [
        ["group", _matchedGroup],
        ["lastHitAt", _now],
        ["lastReportAt", -1],
        ["nextReportEligibleAt", 0],
        ["confirmPending", false],
        ["shooters", createHashMap]
    ];
};

_session set ["group", _matchedGroup];
_session set ["lastHitAt", _now];

private _shooters = _session getOrDefault ["shooters", createHashMap];
if !(_shooters isEqualType createHashMap) then {_shooters = createHashMap;};

if (!isNull _shooter && {alive _shooter} && {side _shooter isNotEqualTo _commanderSide}) then {
    private _shooterKey = str _shooter;
    _shooters set [_shooterKey, createHashMapFromArray [
        ["unit", _shooter],
        ["group", group _shooter],
        ["vehicle", vehicle _shooter],
        ["side", side _shooter],
        ["time", _now]
    ]];
};
_session set ["shooters", _shooters];

private _confirmDelay = (_matchedCommander getVariable [QGVAR(contactConfirmDelaySec), 2]) max 2;
private _nextReportEligibleAt = _session getOrDefault ["nextReportEligibleAt", 0];
private _confirmPending = _session getOrDefault ["confirmPending", false];

if (_now >= _nextReportEligibleAt && {!_confirmPending}) then {
    _session set ["confirmPending", true];

    [{
        params ["_commander", "_groupKey"];
        [_commander, _groupKey] call FUNC(processContactSession);
    }, [_matchedCommander, _groupKey], _confirmDelay] call CBA_fnc_waitAndExecute;
};

_sessions set [_groupKey, _session];
_matchedCommander setVariable [QGVAR(contactSessions), _sessions];
