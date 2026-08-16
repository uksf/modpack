#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Dispatches npc_filler / npc_audio commands received from the API via
        the extension command channel.
*/
params ["_type", "_args"];

switch (_type) do {
    case "npc_filler": {
        _args params ["_npcId", "_voiceId", "_fillerId", "_index", "_total", "_chunk", "_durationMs"];
        if (_total > CLIP_CHUNKS_MAX || {_index < 0} || {_index >= _total}) exitWith {};
        private _key = format ["filler|%1|%2", _npcId, _fillerId];
        private _wav = [_key, _index, _total, _chunk] call FUNC(reassemble);
        if (isNil "_wav") exitWith {};
        TRACE_3("npc_filler complete, distributing to all clients",_npcId,_fillerId,_durationMs);
        private _cached = GVAR(fillerCache) getOrDefault [_voiceId, []];
        if (_cached findIf { _x#0 isEqualTo _fillerId } == -1) then {
            _cached pushBack [_fillerId, _npcId, _wav, _durationMs];
            GVAR(fillerCache) set [_voiceId, _cached];
        };
        [QGVAR(fillerChunkSink), ALL_PLAYERS, ["filler", _npcId, _voiceId, _fillerId, _durationMs], _wav] call FUNC(pushClipChunks);
    };
    case "npc_audio": {
        _args params ["_npcId", "_turnId", "_index", "_total", "_chunk", "_durationMs"];
        if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {};
        if (_total > CLIP_CHUNKS_MAX || {_index < 0} || {_index >= _total}) exitWith {};
        private _key = format ["audio|%1|%2", _npcId, _turnId];
        private _wav = [_key, _index, _total, _chunk] call FUNC(reassemble);
        if (isNil "_wav") exitWith {};
        private _npc = objectFromNetId _npcId;
        if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
            TRACE_1("npc_audio for unknown or terminal npc",_npcId);
        };
        TRACE_3("npc_audio complete, distributing to nearby clients",_npcId,_turnId,_durationMs);
        private _targets = ALL_PLAYERS select { _x distance _npc <= GVAR(audioRange) };
        [QGVAR(audioChunkSink), _targets, ["audio", _npcId, _turnId, _durationMs, 0], _wav] call FUNC(pushClipChunks);
        GVAR(activeClips) set [_npcId, [_turnId, _wav, diag_tickTime, _durationMs]];
        private _speaker = GVAR(lastSpeaker) getOrDefault [_npcId, objNull];
        if (!isNull _speaker) then { [_npc, _speaker] call FUNC(watchSpeaker); };
    };
    case "npc_audio_frame";
    case "npc_audio_end": {
        [_type, _args] call FUNC(onStreamFrame);
    };
    case "npc_guarded_state": {
        private _npcId = _args param [0, ""];
        private _turnId = GVAR(activeTurnIds) getOrDefault [_npcId, ""];
        if (_turnId isEqualTo "" || {[_npcId, _turnId] call FUNC(isTurnCancelled)}) exitWith {};
        [_args] call FUNC(onGuardedState);
    };
    case "npc_debug_state": {
        [_args] call FUNC(consoleOnDebugState);
    };
    case "npc_turn_cancel": {
        _args params ["_npcId", ["_turnId", "", [""]]];
        if (_turnId isEqualTo "") then {
            _turnId = GVAR(activeTurnIds) getOrDefault [_npcId, ""];
        };
        TRACE_2("turn cancelled, telling clients",_npcId,_turnId);
        if (_turnId isNotEqualTo "") then {
            [_npcId, _turnId] call FUNC(cancelTurn);
        };
    };
};
