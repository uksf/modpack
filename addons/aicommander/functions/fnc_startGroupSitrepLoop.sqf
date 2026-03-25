#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Start a per-group SITREP loop if not already active.

    Parameters:
        0: Commander module <OBJECT>
        1: Group <GROUP>

    Return Value:
        None
*/

params [
    ["_commander", objNull, [objNull]],
    ["_group", grpNull, [grpNull]]
];

if (isNull _commander || {isNull _group}) exitWith {};

private _existingPFH = _group getVariable [QGVAR(sitrepPFH), -1];
if (_existingPFH >= 0) exitWith {};

if (isNull (leader _group) || {!alive (leader _group)}) exitWith {
    [_commander, _group, "kia"] call FUNC(reportGroupStatus);
};

[ "SITREP_LOOP_ATTACH", _commander, createHashMapFromArray [
    ["actionId", _group getVariable [QGVAR(actionId), "none"]],
    ["reason", "attached"],
    ["message", format ["group=%1 interval=%2", str _group, (_commander getVariable [QGVAR(sitrepIntervalSec), 180]) max 30]]
]] call FUNC(logExecution);

[_commander, _group, "initial"] call FUNC(emitGroupSitrep);

private _interval = (_commander getVariable [QGVAR(sitrepIntervalSec), 180]) max 30;
private _pfh = [{
    params ["_args", "_idPFH"];
    _args params ["_commanderPFH", "_groupPFH"];

    if (isNull _commanderPFH || {isNull _groupPFH}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        if (!isNull _groupPFH) then {
            _groupPFH setVariable [QGVAR(sitrepPFH), -1];
        };
    };

    if (isNull (leader _groupPFH) || {!alive (leader _groupPFH)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        _groupPFH setVariable [QGVAR(sitrepPFH), -1];
        [_commanderPFH, _groupPFH, "kia"] call FUNC(reportGroupStatus);
    };

    [_commanderPFH, _groupPFH, "periodic"] call FUNC(emitGroupSitrep);
}, _interval, [_commander, _group]] call CBA_fnc_addPerFrameHandler;

_group setVariable [QGVAR(sitrepPFH), _pfh];
