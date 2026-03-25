#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Emit SITREP for one managed group and log RTB recommendation when ineffective.

    Parameters:
        0: Commander module <OBJECT>
        1: Group <GROUP>
        2: Trigger reason <STRING>

    Return Value:
        None
*/

params [
    ["_commander", objNull, [objNull]],
    ["_group", grpNull, [grpNull]],
    ["_reason", "periodic", [""]]
];

if (isNull _commander || {isNull _group}) exitWith {};

private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
private _entryIndex = _managedGroups findIf {(_x getOrDefault ["group", grpNull]) isEqualTo _group};
if (_entryIndex < 0) exitWith {};

private _entry = _managedGroups#_entryIndex;
private _aliveUnits = {alive _x} count units _group;
private _startedStrength = (_entry getOrDefault ["startedStrength", _aliveUnits]) max 1;
private _casualtyRatio = 1 - (_aliveUnits / _startedStrength);
private _casualtyRatioRounded = (round (_casualtyRatio * 100)) / 100;
private _threshold = (_commander getVariable [QGVAR(ineffectiveCasualtyThreshold), 0.5]) max 0.1;
private _rtbRecommended = _casualtyRatio >= _threshold;

private _leader = leader _group;
private _position = if (!isNull _leader) then {getPosATL _leader} else {[0, 0, 0]};
private _position2D = [_position#0, _position#1];
private _grid = [_position2D, _commander getVariable [QGVAR(gridCellSize), 500]] call FUNC(getGridCoord);

["SITREP", _commander, createHashMapFromArray [
    ["actionId", _entry getOrDefault ["actionId", "none"]],
    ["reason", _reason],
    ["message", format [
        "group=%1 alive=%2/%3 cas=%4 pos=%5,%6 grid=%7,%8 task=%9 target=%10 rtb=%11",
        str _group,
        _aliveUnits,
        _startedStrength,
        _casualtyRatioRounded,
        round (_position2D#0),
        round (_position2D#1),
        _grid#0,
        _grid#1,
        _entry getOrDefault ["actionType", "none"],
        _entry getOrDefault ["targetObjectiveName", "none"],
        _rtbRecommended
    ]]
]] call FUNC(logExecution);

if (_rtbRecommended) then {
    ["RTB_RECOMMENDED", _commander, createHashMapFromArray [
        ["actionId", _entry getOrDefault ["actionId", "none"]],
        ["reason", "ineffective_casualty_threshold"],
        ["message", format [
            "group=%1 cas=%2 threshold=%3",
            str _group,
            _casualtyRatioRounded,
            (round (_threshold * 100)) / 100
        ]]
    ]] call FUNC(logExecution);
};

_entry set ["lastSitrepAt", if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}];
_entry set ["rtbRecommended", _rtbRecommended];
_managedGroups set [_entryIndex, _entry];
_commander setVariable [QGVAR(managedGroups), _managedGroups];
