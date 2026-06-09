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
if (isNull _requester) exitWith {};

private _clip = GVAR(activeClips) getOrDefault [_npcId, []];
if (_clip isEqualTo []) exitWith {};
_clip params ["_turnId", "_wav", "_dispatchTime", "_durationMs"];

private _elapsedMs = (diag_tickTime - _dispatchTime) * 1000;
if (_elapsedMs >= _durationMs) exitWith {
    GVAR(activeClips) deleteAt _npcId; // finished; reclaim
};

[QGVAR(audioChunkSink), [_requester], ["audio", _npcId, _turnId, _durationMs, _elapsedMs], _wav] call FUNC(pushClipChunks);
