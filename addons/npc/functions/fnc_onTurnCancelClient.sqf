#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Stops filler and stream audio for one cancelled turn.

    Parameter(s):
        0: NPC netId <STRING>
        1: Turn id <STRING>

    Return Value:
        None
*/
params ["_npcId", ["_turnId", "", [""]]];

if (_turnId isNotEqualTo "") then {
    GVAR(cancelledTurns) set [[_npcId, _turnId] call FUNC(turnKey), diag_tickTime];
};

GVAR(pendingFiller) set [_npcId, 0];

private _fillerId = GVAR(fillerClipIds) getOrDefault [_npcId, ""];
if (_fillerId isNotEqualTo "") then {
    [_fillerId] call FUNC(stopClip);
    GVAR(fillerClipIds) deleteAt _npcId;
};

if (_turnId isEqualTo "") exitWith {};

private _clipId = format ["%1_%2", _npcId, _turnId];
if (_clipId in GVAR(streamingClips) || {_clipId in GVAR(streamHeld)}) then {
    "uksf" callExtension ["audioEnd", [_clipId]];
    [_clipId] call FUNC(stopClip);
};
GVAR(streamingClips) deleteAt _clipId;
GVAR(streamHeld) deleteAt _clipId;
GVAR(streamSamples) deleteAt _clipId;
GVAR(streamStart) deleteAt _clipId;
GVAR(heardSeq) deleteAt format ["%1|seq", [_npcId, _turnId] call FUNC(turnKey)];
[_clipId] call FUNC(stopClip);
