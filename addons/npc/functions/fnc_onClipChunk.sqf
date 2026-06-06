#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Reassembles a chunked clip received from the server. Audio plays
        immediately anchored to the NPC and drives the talking mouth animation;
        fillers are cached for instant later play.

    Parameter(s):
        0: Kind "audio" or "filler" <STRING>
        1: Payload [header, index, total, chunk] <ARRAY>
            header (audio):  ["audio",  npcId, turnId,   durationMs]
            header (filler): ["filler", npcId, voiceId,  fillerId, durationMs]

    Return Value:
        None

    Example:
        ["audio", _payload] call uksf_npc_fnc_onClipChunk
*/
params ["_kind", "_payload"];
_payload params ["_header", "_index", "_total", "_chunk"];

private _key = format ["%1|%2", _kind, _header joinString "|"];
// Buffer entry is [receivedCount, chunks] so completion is O(1) per chunk.
private _entry = GVAR(clipRxBuffers) get _key;
if (isNil "_entry") then {
    private _chunks = [];
    _chunks resize _total;
    _entry = [0, _chunks];
    GVAR(clipRxBuffers) set [_key, _entry];
};
_entry params ["_count", "_chunks"];
if (isNil {_chunks select _index}) then {
    _chunks set [_index, _chunk];
    _count = _count + 1;
    _entry set [0, _count];
};
GVAR(clipRxBufferTimes) set [_key, diag_tickTime];

if (_count < _total) exitWith {};
GVAR(clipRxBuffers) deleteAt _key;
GVAR(clipRxBufferTimes) deleteAt _key;
private _wav = _chunks joinString "";

if (_kind isEqualTo "audio") exitWith {
    _header params ["", "_npcId", "_turnId", "_durationMs"];
    private _npc = objectFromNetId _npcId;
    if (isNull _npc) exitWith {};
    private _clipId = [format ["%1_%2", _npcId, _turnId], _npc, _wav] call FUNC(playClip);
    if (_clipId isEqualTo "") exitWith {};

    // setRandomLip is Effect-Local; each playing client drives the mouth. A later
    // clip extends talkingUntil, so a stale timer leaves the lips alone.
    private _duration = (_durationMs / 1000) max 0.5;
    private _endTime = diag_tickTime + _duration;
    GVAR(talkingUntil) set [_npcId, _endTime];
    _npc setRandomLip true;
    [{
        params ["_npc", "_npcId", "_endTime"];
        if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {};
        if (!isNull _npc) then { _npc setRandomLip false };
    }, [_npc, _npcId, _endTime], _duration] call CBA_fnc_waitAndExecute;
};

// Filler: cache per voiceId, skip duplicate ids.
_header params ["", "_npcId", "_voiceId", "_fillerId", "_durationMs"];
private _list = GVAR(fillers) getOrDefault [_voiceId, []];
if (_list findIf { _x#0 isEqualTo _fillerId } == -1) then {
    _list pushBack [_fillerId, _wav, _durationMs];
    GVAR(fillers) set [_voiceId, _list];
};
