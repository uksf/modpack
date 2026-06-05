#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Per-frame audio spatialisation. Sets the OpenAL listener orientation to
        the local player's facing and feeds every active source its position as
        a raw world-axis delta from the player's eye. Mirrors ArmaRadio's
        manager tick. Self-removes when no clips are active.

    Parameter(s):
        0: PFH args (unused) <ARRAY>
        1: PFH id <NUMBER>

    Return Value:
        None
*/
params ["", "_idPFH"];

if (GVAR(active) isEqualTo []) exitWith {
    GVAR(tickRunning) = false;
    [_idPFH] call CBA_fnc_removePerFrameHandler;
};

private _player = call CBA_fnc_currentUnit;
private _eyePosition = eyePos _player;
private _forward = eyeDirection _player;
private _up = vectorUp _player;
"uksf" callExtension ["audioListener", [_forward#0, _forward#1, _forward#2, _up#0, _up#1, _up#2]];

{
    _x params ["_clipId", "_npc"];
    if (isNull _npc || {!alive _npc}) then {
        "uksf" callExtension ["audioStop", [_clipId]];
        GVAR(active) = GVAR(active) - [_x];
    } else {
        private _delta = (getPosASL _npc) vectorDiff _eyePosition;
        "uksf" callExtension ["audioPos", [_clipId, _delta#0, _delta#1, _delta#2]];
    };
} forEach GVAR(active);
