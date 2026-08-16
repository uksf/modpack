#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. A client entering a talkable NPC's audio range requests its
        in-flight clip. If one is still playing, resend it to that client only,
        with the elapsed offset so playback is synced to the NPC and other
        listeners. No active/expired clip -> silently ignore.

    Parameter(s):
        0: NPC netId <STRING>
        1: Requesting client (player object) <OBJECT>

    Return Value:
        None
*/
params ["_npcId", "_requester"];
if (isNull _requester || {!(_requester in ALL_PLAYERS)}) exitWith {};
private _npc = objectFromNetId _npcId;
if (isNull _npc || {(_requester distance _npc) > GVAR(audioRange)}) exitWith {};

// An open stream wins over a one-shot clip: replay the frames so far and the
// client continues on live frames (deduped by seq).
private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo []) exitWith {
    _stream params ["_turnId", "_frames"];
    if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith { GVAR(activeStreams) deleteAt _npcId; };
    {
        if (!isNil "_x") then {
            [QGVAR(streamFrameSink), [_npcId, _turnId, _forEachIndex, _x], [_requester]] call CBA_fnc_targetEvent;
        };
    } forEach _frames;
};

private _clip = GVAR(activeClips) getOrDefault [_npcId, []];
if (_clip isEqualTo []) exitWith {};
_clip params ["_turnId", "_wav", "_dispatchTime", "_durationMs"];
if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith { GVAR(activeClips) deleteAt _npcId; };

private _elapsedMs = (diag_tickTime - _dispatchTime) * 1000;
if (_elapsedMs >= _durationMs) exitWith {
    GVAR(activeClips) deleteAt _npcId; // finished; reclaim
};
// Too little left to be worth a chunked resend that would arrive after the clip ends.
if (_durationMs - _elapsedMs < 500) exitWith {};

[QGVAR(audioChunkSink), [_requester], ["audio", _npcId, _turnId, _durationMs, _elapsedMs], _wav] call FUNC(pushClipChunks);
