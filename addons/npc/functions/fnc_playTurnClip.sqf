#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Plays a complete turn clip anchored to its NPC and drives the mouth for the
        length of the audio. Used by the non-streamed paths: a scripted line, and a
        mid-clip resync for a player who walked up part-way through.

    Parameter(s):
        0: NPC object <OBJECT>
        1: NPC netId <STRING>
        2: Turn id <STRING>
        3: WAV base64 <STRING>
        4: Clip duration in ms <NUMBER>
        5: Offset into the clip in ms <NUMBER>

    Return Value:
        None

    Example:
        [_npc, "2:16", "t7", _wav, 2400, 0] call uksf_npc_fnc_playTurnClip
*/
params ["_npc", "_npcId", "_turnId", "_wav", "_durationMs", ["_offsetMs", 0]];
if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};
if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {};

private _clipId = [format ["%1_%2", _npcId, _turnId], _npc, _wav, 1, _offsetMs] call FUNC(playClip);
if (_clipId isEqualTo "") exitWith {};

// Mark heard only once playback commits, so a not-yet-streamed NPC isn't lost to dedup.
GVAR(heardTurns) set [format ["%1|%2", _npcId, _turnId], diag_tickTime];

// setRandomLip is Effect-Local; each playing client drives the mouth. A later
// clip extends talkingUntil, so a stale timer leaves the lips alone.
private _duration = ((_durationMs - _offsetMs) / 1000) max 0.5;
private _endTime = diag_tickTime + _duration;
GVAR(talkingUntil) set [_npcId, _endTime];
_npc setRandomLip true;
[{
    params ["_npc", "_npcId", "_endTime"];
    if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {};
    if (!isNull _npc) then { _npc setRandomLip false };
}, [_npc, _npcId, _endTime], _duration] call CBA_fnc_waitAndExecute;
