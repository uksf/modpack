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
if (_total < 1 || {_total > CLIP_CHUNKS_MAX} || {_index < 0} || {_index >= _total}) exitWith {};

private _key = format ["%1|%2", _kind, _header joinString "|"];
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
    _header params ["", "_npcId", "_turnId", "_durationMs", ["_offsetMs", 0]];
    if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};
    private _turnKey = [_npcId, _turnId] call FUNC(turnKey);
    if (_turnKey in GVAR(heardTurns)) exitWith {};

    private _npc = objectFromNetId _npcId;
    if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {};

    // Queue behind a sounding filler rather than cutting it off part-way.
    GVAR(pendingFiller) set [_npcId, 0]; // the reply is here; arm no more fillers
    private _wait = ((GVAR(fillerBusyUntil) getOrDefault [_npcId, 0]) - diag_tickTime) max 0;
    private _args = [_npc, _npcId, _turnId, _wav, _durationMs, _offsetMs];
    if (_wait > 0) exitWith {
        [{ _this call FUNC(playTurnClip); }, _args, _wait] call CBA_fnc_waitAndExecute;
    };

    _args call FUNC(playTurnClip);
};

// Filler: cache per voiceId, skip duplicate ids.
_header params ["", "_npcId", "_voiceId", "_fillerId", "_durationMs"];
private _list = GVAR(fillers) getOrDefault [_voiceId, []];
if (_list findIf { _x#0 isEqualTo _fillerId } == -1) then {
    _list pushBack [_fillerId, _wav, _durationMs];
    GVAR(fillers) set [_voiceId, _list];
    TRACE_3("filler cached",_voiceId,_fillerId,count _list);
};
