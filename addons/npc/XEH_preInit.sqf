#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// [[clipId, npc], ...] currently-playing clips tracked by the tick handler.
GVAR(active) = [];
GVAR(tickRunning) = false;

// Client gate state: the NPC the local player is currently addressing (or objNull),
// and whether the ACRE mic capture gate is currently open.
GVAR(targetNpc) = objNull;
GVAR(micGateOpen) = false;

// Raised locally with [unit, text, uttId, time] when the local player's speech
// is transcribed. Forwards to the server if the player is addressing a talkable NPC.
[QGVAR(transcript), { _this call FUNC(onTranscriptGated); }] call CBA_fnc_addEventHandler;

// Head-turn handler — registered unconditionally so it runs on the server AND any
// headless client that owns NPCs. CBA_fnc_targetEvent routes the headTurn event to
// the machine where the NPC is local; doWatch is Argument-Local so it must execute there.
[QGVAR(headTurn), { _this call FUNC(headTurn); }] call CBA_fnc_addEventHandler;

// Client chunk-receive buffers and filler cache — registered everywhere;
// the CBA events only fire on the machines targeted by the server.
GVAR(clipRxBuffers) = createHashMap;
GVAR(clipRxBufferTimes) = createHashMap;
GVAR(fillers) = createHashMap;
GVAR(fillerCounter) = 0;
[QGVAR(audioChunkSink),  { ["audio",  _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;
[QGVAR(fillerChunkSink), { ["filler", _this] call FUNC(onClipChunk); }] call CBA_fnc_addEventHandler;

// Server: utterance room state, debounce timers, last-speaker objects,
// and API-command receive buffers.
if (isServer) then {
    GVAR(rooms) = createHashMap;
    GVAR(roomTimers) = createHashMap;
    GVAR(lastSpeaker) = createHashMap;
    [QGVAR(utterance), { _this call FUNC(onUtterance); }] call CBA_fnc_addEventHandler;
    GVAR(rxBuffers) = createHashMap;
    GVAR(rxBufferTimes) = createHashMap;
    [QEGVAR(api,command), { _this call FUNC(onApiCommand); }] call CBA_fnc_addEventHandler;
};

#include "initSettings.inc.sqf"

ADDON = true;
