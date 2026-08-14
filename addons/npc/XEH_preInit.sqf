#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// [[clipId, npc], ...] currently-playing clips tracked by the tick handler.
GVAR(active) = [];
GVAR(tickRunning) = false;

// Client gate state: the NPC the local player is currently addressing (or objNull),
// and whether the ACRE mic capture gate is currently open.
GVAR(targetNpc) = objNull;
// Frames the nearest rival has been clearly closer to the crosshair; the target only
// switches once it has held that lead, so a glance does not steal a turn mid-sentence.
GVAR(targetCandidate) = 0;
GVAR(micGateOpen) = false;

GVAR(consoleStates) = createHashMap;
GVAR(consoleCardsEnabled) = false;
GVAR(consoleCardsPFH) = -1;
GVAR(consoleInspectorNpc) = objNull;
GVAR(consoleInspectorPFH) = -1;

// Raised locally with [unit, text, uttId, time] when the local player's speech
// is transcribed. Forwards to the server if the player is addressing a talkable NPC.
[QGVAR(transcript), { _this call FUNC(onTranscriptGated); }] call CBA_fnc_addEventHandler;

// Head-turn runs on the NPC owner (server or HC); routed there via CBA_fnc_targetEvent.

// Clip receive buffers, filler cache, and per-NPC talking deadlines.
GVAR(clipRxBuffers) = createHashMap;
GVAR(clipRxBufferTimes) = createHashMap;
GVAR(fillers) = createHashMap;
GVAR(fillerCounter) = 0;
GVAR(talkingUntil) = createHashMap;

// Mid-clip resync: netIds currently in audio range (rising-edge request), per-NPC
// request debounce, and turns already heard (dedup so a resync never double-plays).
GVAR(nearTalkers) = [];
GVAR(lastRequest) = createHashMap;
GVAR(heardTurns) = createHashMap;
[QGVAR(audioChunkSink),  { ["audio",  _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;
[QGVAR(fillerChunkSink), { ["filler", _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;

// Streamed dynamic turns: frames feed the extension's open clip, end closes it.
// heardSeq dedupes frames by seq (a join replay and the live relay can overlap).
GVAR(streamingClips) = createHashMap;
GVAR(heardSeq) = createHashMap;
// Samples fed per open stream, so the mouth can run for the whole spoken line rather
// than stopping when the last frame lands (frames arrive faster than they play out).
GVAR(streamSamples) = createHashMap;
GVAR(streamStart) = createHashMap;
GVAR(fillerCache) = createHashMap;
// Pending filler token per NPC; the first audio frame stops any further filler being armed.
GVAR(pendingFiller) = createHashMap;
[QGVAR(turnCancelSink), { GVAR(pendingFiller) set [_this#0, 0]; }] call CBA_fnc_addEventHandler;
// When each NPC's filler stops sounding, and the frames held until it does.
GVAR(fillerBusyUntil) = createHashMap;
GVAR(streamHeld) = createHashMap;
// Until when a filler still counts as an early guess (short noise) rather than cover for a
// wait that is already long (drawn-out noise).
GVAR(fillerEarlyUntil) = createHashMap;
[QGVAR(streamFrameSink), { _this call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;
[QGVAR(streamEndSink),   { [_this#0, _this#1, -1, ""] call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;

// Guarded-source feedback, drawn above the NPC: the emote is the production signal, the
// state hint is test-only and stays off unless a fixture asks for it. Neither carries fact
// text, and neither is ever spoken. Both are keyed by netId with the object resolved once,
// so the per-frame draw does no lookup and holds no local scope.
GVAR(emotes) = createHashMap;
GVAR(stateHints) = createHashMap;
[QGVAR(guardedStateSink), {
    params ["_npcId", "_cooperation", "_pendingWarning", "_burned", "_disclosedFactIds", "_eligibleFactId", "_mood", "_emote", "_reason", "_evidence", "_classifierMs", "_replyMs"];
    _this call FUNC(consoleApplyGuardedState);
    private _npc = objectFromNetId _npcId;
    if (isNull _npc) exitWith {};
    if (_emote isNotEqualTo "" && {(call CBA_fnc_currentUnit) distance _npc <= GVAR(audioRange)}) then {
        GVAR(emotes) set [_npcId, [_npc, _emote, diag_tickTime + EMOTE_HOLD]];
    };
    if !(missionNamespace getVariable [QGVAR(showStateHint), false]) exitWith {};
    private _threat = [["clear", "warned"] select _pendingWarning, "burned"] select _burned;
    GVAR(stateHints) set [_npcId, [
        _npc,
        format ["%1 | %2 | %3 | disclosed %4 | eligible %5 | %6+%7ms", _cooperation, _threat, _mood, ["-", _disclosedFactIds] select (_disclosedFactIds isNotEqualTo ""), ["-", _eligibleFactId] select (_eligibleFactId isNotEqualTo ""), _classifierMs, _replyMs],
        ([_reason, _evidence] select { _x isNotEqualTo "" }) joinString " | ",
        diag_tickTime + HINT_HOLD
    ]];
}] call CBA_fnc_addEventHandler;
[QGVAR(debugStateSink), {_this call FUNC(consoleApplyDebugState)}] call CBA_fnc_addEventHandler;
[QGVAR(consoleClearStateSink), {GVAR(consoleStates) deleteAt (_this#0)}] call CBA_fnc_addEventHandler;
[QGVAR(consoleClearPendingSink), {
    private _state = [_this#0] call FUNC(consoleGetState);
    _state set ["pendingWarning", false];
    _state set ["eligible", ""];
    _state set ["tag", ""];
    _state set ["reason", ""];
    _state set ["evidence", ""];
}] call CBA_fnc_addEventHandler;
[QGVAR(consoleSttSink), {
    params ["_npcId", "_text", "_addressed"];
    private _state = [_npcId] call FUNC(consoleGetState);
    _state set ["lastStt", _text];
    _state set ["addressed", _addressed];
}] call CBA_fnc_addEventHandler;

// Server: utterance room state, debounce timers, last-speaker objects,
// and API-command receive buffers.
if (isServer) then {
    GVAR(rooms) = createHashMap;
    GVAR(roomTimers) = createHashMap;
    GVAR(lastSpeaker) = createHashMap;
    GVAR(watchUntil) = createHashMap;
    GVAR(cancelledNpcIds) = createHashMap;
    missionNamespace setVariable [QGVAR(registeredNetIds), [], true];
    missionNamespace setVariable [QGVAR(mutedNetIds), [], true];
    [QGVAR(utterance), { _this call FUNC(onUtterance); }] call CBA_fnc_addEventHandler;
    [QGVAR(consoleAction), { _this call FUNC(consoleServerAction); }] call CBA_fnc_addEventHandler;
    GVAR(rxBuffers) = createHashMap;
    GVAR(rxBufferTimes) = createHashMap;
    [QEGVAR(api,command), { _this call FUNC(onApiCommand); }] call CBA_fnc_addEventHandler;
    // Active audio clips for mid-clip resync: npcId -> [turnId, wav, dispatchTime, durationMs].
    GVAR(activeClips) = createHashMap;
    [QGVAR(requestClip), { _this call FUNC(onRequestClip); }] call CBA_fnc_addEventHandler;
    // Test reset: the fixture asks for one guarded source to be re-registered from scratch.
    // Registration is server work, so the request has to travel here rather than run client-side.
    //
    // Any client can raise this event with any netId, and a reset wipes cooperation, the
    // ledger and the NPC's history. So it does nothing at all unless the mission itself has
    // opted in on the server, and then only for a live guarded source: a forged reset aimed
    // at a conversation NPC or at a production mission's guarded source is dropped.
    [QGVAR(guardedReset), {
        params ["_npcId"];
        if !(missionNamespace getVariable [QGVAR(allowGuardedReset), false]) exitWith {
            WARNING_1("guarded reset refused: this mission does not enable it (%1)",_npcId);
        };
        private _npc = objectFromNetId _npcId;
        if (isNull _npc) exitWith { WARNING_1("guarded reset for unknown netId: %1",_npcId); };
        if !(_npc getVariable [QGVAR(talkable), false]) exitWith {
            WARNING_1("guarded reset refused: npc is not talkable (%1)",_npcId);
        };
        if ((_npc getVariable [QGVAR(interactionProfile), "conversation"]) isNotEqualTo "guarded") exitWith {
            WARNING_1("guarded reset refused: npc is not a guarded source (%1)",_npcId);
        };
        TRACE_1("guarded reset requested",_npcId);
        [_npc, true] call FUNC(registerNpc);
    }] call CBA_fnc_addEventHandler;
    // Open streamed turns for mid-clip joiners: npcId -> [nextSeq, [pcm frames so far]].
    GVAR(activeStreams) = createHashMap;
};

#include "initSettings.inc.sqf"

ADDON = true;
