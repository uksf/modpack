#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler for the performance log.
        Counts frames of 100, 250 and 500 ms or more, writes a line for each frame of 250 ms or more,
        and writes a summary line every 10 s with fps, slow-frame counts, local AI, groups and running scripts.

    Parameter(s):
        CBA per-frame handler arguments (unused)

    Return Value:
        None

    Example:
        [[], 0] call uksf_common_fnc_perfLogTick
*/
private _now = diag_tickTime;
private _frameMs = (_now - GVAR(perfLogLastFrameAt)) * 1000;
GVAR(perfLogLastFrameAt) = _now;
GVAR(perfLogFrames) = GVAR(perfLogFrames) + 1;
GVAR(perfLogMaxMs) = GVAR(perfLogMaxMs) max _frameMs;

{
    if (_frameMs >= _x) then {
        GVAR(perfLogSlowCounts) set [_forEachIndex, (GVAR(perfLogSlowCounts) select _forEachIndex) + 1];
    };
} forEach [100, 250, 500];

if (_frameMs >= 250) then {
    INFO_1("%1",format [ARR_4("[PERFLOG][SLOW] %1 t=%2 ms=%3",GVAR(perfLogMachine),round CBA_missionTime,round _frameMs)]);
};

private _windowSeconds = _now - GVAR(perfLogWindowStart);
if (_windowSeconds < 10) exitWith {};

private _localUnits = {local _x} count allUnits;
private _localGroups = {local _x} count allGroups;
private _scripts = diag_activeScripts;
private _summary = format [
    "[PERFLOG] %1 t=%2 fps=%3 frames=%4 ge100=%5 ge250=%6 ge500=%7 maxMs=%8 localAI=%9 localGroups=%10 spawn=%11 execVM=%12 exec=%13 fsm=%14",
    GVAR(perfLogMachine),
    round CBA_missionTime,
    round (GVAR(perfLogFrames) / _windowSeconds),
    GVAR(perfLogFrames),
    GVAR(perfLogSlowCounts) select 0,
    GVAR(perfLogSlowCounts) select 1,
    GVAR(perfLogSlowCounts) select 2,
    round GVAR(perfLogMaxMs),
    _localUnits,
    _localGroups,
    _scripts select 0,
    _scripts select 1,
    _scripts select 2,
    _scripts select 3
];
INFO_1("%1",_summary);

GVAR(perfLogWindowStart) = _now;
GVAR(perfLogFrames) = 0;
GVAR(perfLogSlowCounts) = [0, 0, 0];
GVAR(perfLogMaxMs) = 0;
