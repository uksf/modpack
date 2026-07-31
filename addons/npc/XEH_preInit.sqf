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
// When each NPC's filler stops sounding, and the frames held until it does.
GVAR(fillerBusyUntil) = createHashMap;
GVAR(streamHeld) = createHashMap;
// Until when a filler still counts as an early guess (short noise) rather than cover for a
// wait that is already long (drawn-out noise).
GVAR(fillerEarlyUntil) = createHashMap;
[QGVAR(streamFrameSink), { _this call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;
[QGVAR(streamEndSink),   { [_this#0, _this#1, -1, ""] call FUNC(onStreamFrameClient); }] call CBA_fnc_addEventHandler;

// Server: utterance room state, debounce timers, last-speaker objects,
// and API-command receive buffers.
if (isServer) then {
    GVAR(rooms) = createHashMap;
    GVAR(roomTimers) = createHashMap;
    GVAR(lastSpeaker) = createHashMap;
GVAR(watchUntil) = createHashMap;
    [QGVAR(utterance), { _this call FUNC(onUtterance); }] call CBA_fnc_addEventHandler;
    GVAR(rxBuffers) = createHashMap;
    GVAR(rxBufferTimes) = createHashMap;
    [QEGVAR(api,command), { _this call FUNC(onApiCommand); }] call CBA_fnc_addEventHandler;
    // Active audio clips for mid-clip resync: npcId -> [turnId, wav, dispatchTime, durationMs].
    GVAR(activeClips) = createHashMap;
    [QGVAR(requestClip), { _this call FUNC(onRequestClip); }] call CBA_fnc_addEventHandler;
    // Open streamed turns for mid-clip joiners: npcId -> [nextSeq, [pcm frames so far]].
    GVAR(activeStreams) = createHashMap;
};

#include "initSettings.inc.sqf"

ADDON = true;
