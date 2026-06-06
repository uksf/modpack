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
        [QGVAR(audioChunkSink), _targets, ["audio", _npcId, _turnId, _durationMs], _wav] call FUNC(pushClipChunks);
        // Head-turn on the NPC owner; targetEvent routes to the owning machine.
        [QGVAR(headTurn), [_npc, GVAR(lastSpeaker) getOrDefault [_npcId, objNull], _durationMs], _npc] call CBA_fnc_targetEvent;
    };
};
