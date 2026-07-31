#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Dispatches npc_filler / npc_audio commands received from the API via
        the extension command channel. Reassembles chunked base64 audio (buffer-by-index,
        mirroring persistence load). On completion, distributes the full WAV to clients.

    Parameter(s):
        0: Type <STRING>   (from QEGVAR(api,command))
        1: Args <ARRAY>

    Return Value:
        None

    Example:
        ["npc_filler", _args] call uksf_npc_fnc_onApiCommand
*/
params ["_type", "_args"];

switch (_type) do {
    case "npc_filler": {
        _args params ["_npcId", "_voiceId", "_fillerId", "_index", "_total", "_chunk", "_durationMs"];
        private _key = format ["filler|%1|%2", _npcId, _fillerId];
        private _wav = [_key, _index, _total, _chunk] call FUNC(reassemble);
        if (isNil "_wav") exitWith {};
        TRACE_3("npc_filler complete, distributing to all clients",_npcId,_fillerId,_durationMs);
        // Held so a player who connects after registration still gets the fillers; without
        // this the mask only ever reached whoever was already in the mission.
        private _cached = GVAR(fillerCache) getOrDefault [_voiceId, []];
        if (_cached findIf { _x#0 isEqualTo _fillerId } == -1) then {
            _cached pushBack [_fillerId, _npcId, _wav, _durationMs];
            GVAR(fillerCache) set [_voiceId, _cached];
        };
        // Distribute to ALL clients to cache (played instantly on utterance-finalise).
        [QGVAR(fillerChunkSink), ALL_PLAYERS, ["filler", _npcId, _voiceId, _fillerId, _durationMs], _wav] call FUNC(pushClipChunks);
    };
    case "npc_audio": {
        _args params ["_npcId", "_turnId", "_index", "_total", "_chunk", "_durationMs"];
        private _key = format ["audio|%1|%2", _npcId, _turnId];
        private _wav = [_key, _index, _total, _chunk] call FUNC(reassemble);
        if (isNil "_wav") exitWith {};
        private _npc = objectFromNetId _npcId;
        if (isNull _npc) exitWith { TRACE_1("npc_audio for unknown netId",_npcId); };
        TRACE_3("npc_audio complete, distributing to nearby clients",_npcId,_turnId,_durationMs);
        // Distribute to nearby clients to play, anchored to the NPC.
        private _targets = allPlayers select { _x distance _npc <= GVAR(audioRange) };
        // header now ["audio", npcId, turnId, durationMs, offsetMs]; live broadcast = 0 offset.
        [QGVAR(audioChunkSink), _targets, ["audio", _npcId, _turnId, _durationMs, 0], _wav] call FUNC(pushClipChunks);
        GVAR(activeClips) set [_npcId, [_turnId, _wav, diag_tickTime, _durationMs]];
    };
    case "npc_audio_frame";
    case "npc_audio_end": {
        [_type, _args] call FUNC(onStreamFrame);
    };
    case "npc_turn_cancel": {
        // The API dropped this turn (addressed to someone else, or the brain declined).
        // The filler loop runs on the CLIENT, so the cancel has to travel there — clearing
        // the server's own copy left the player listening to a loop nothing would stop.
        _args params ["_npcId"];
        TRACE_1("turn cancelled, telling clients",_npcId);
        [QGVAR(turnCancelSink), [_npcId], ALL_PLAYERS] call CBA_fnc_targetEvent;
    };
};
