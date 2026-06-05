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

// Build a unique reassembly key from the kind + every header field.
private _key = format ["%1|%2", _kind, _header joinString "|"];
private _buf = GVAR(clipRxBuffers) getOrDefault [_key, []];
if (_buf isEqualTo []) then { _buf resize _total; };
_buf set [_index, _chunk];
GVAR(clipRxBuffers) set [_key, _buf];
GVAR(clipRxBufferTimes) set [_key, diag_tickTime];

// Wait until all chunks have arrived.
if (({!isNil "_x"} count _buf) < _total) exitWith {};
GVAR(clipRxBuffers) deleteAt _key;
GVAR(clipRxBufferTimes) deleteAt _key;
private _wav = _buf joinString "";

if (_kind isEqualTo "audio") exitWith {
    _header params ["", "_npcId", "_turnId", "_durationMs"];
    private _npc = objectFromNetId _npcId;
    if (isNull _npc) exitWith {};
    [format ["%1_%2", _npcId, _turnId], _npc, _wav] call FUNC(playClip);
    // Talking mouth: setRandomLip is Effect-Local, so each playing client sets it
    // (mirrors ACRE's remoteStartSpeaking). Stop it when the clip ends.
    _npc setRandomLip true;
    [{ (_this#0) setRandomLip false }, [_npc], (_durationMs / 1000) max 0.5] call CBA_fnc_waitAndExecute;
};

// filler — cache per voiceId; skip if this fillerId is already stored.
_header params ["", "_npcId", "_voiceId", "_fillerId", "_durationMs"];
private _list = GVAR(fillers) getOrDefault [_voiceId, []];
if (_list findIf { _x#0 isEqualTo _fillerId } == -1) then {
    _list pushBack [_fillerId, _wav, _durationMs];
    GVAR(fillers) set [_voiceId, _list];
};
