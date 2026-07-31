#include "script_component.hpp"

// Unfinished feature: no registration, no mic capture, no STT server, no per-frame
// handlers unless NPC_ENABLED is defined. See script_component.hpp.
#ifndef NPC_ENABLED
if (true) exitWith {};
#endif

// Server: register all talkable NPCs once the API session is ready. The API event
// channel (and EGVAR(api,sessionId)) only exists on a dedicated server, so NPC speech
// is dedicated-only — skip loudly elsewhere instead of waiting forever.
if (isServer) then {
    if (!isDedicated) exitWith {
        WARNING("NPC speech is dedicated-server only (no API session off-dedi); skipping NPC registration");
    };

    // Bounded wait so a never-arriving API session is diagnosable, not an infinite silent spin.
    GVAR(registerDeadline) = diag_tickTime + 60;
    [
        { !isNil {EGVAR(api,sessionId)} || {diag_tickTime > GVAR(registerDeadline)} },
        {
            if (isNil {EGVAR(api,sessionId)}) exitWith {
                WARNING("NPC register: API sessionId not set within 60s; NPCs were not registered");
            };
            TRACE_1("sessionId present, calling registerNpcs",EGVAR(api,sessionId));
            call FUNC(registerNpcs);
        }
    ] call CBA_fnc_waitUntilAndExecute;

    // Send the cached fillers to a joining client. Registration pushes them once, so a
    // player who connects later would otherwise never hear the latency mask.
    addMissionEventHandler ["PlayerConnected", {
        params ["", "", "_name", "_jip"];
        [{
            private _client = (allPlayers select { name _x isEqualTo (_this#0) }) param [0, objNull];
            if (isNull _client) exitWith {};
            {
                private _voiceId = _x;
                {
                    _x params ["_fillerId", "_npcId", "_wav", "_durationMs"];
                    [QGVAR(fillerChunkSink), [_client], ["filler", _npcId, _voiceId, _fillerId, _durationMs], _wav] call FUNC(pushClipChunks);
                } forEach (GVAR(fillerCache) get _voiceId);
            } forEach (keys GVAR(fillerCache));
            TRACE_1("pushed cached fillers to joining client",_this#0);
        }, [_name], 5] call CBA_fnc_waitAndExecute;
    }];

    // Sweep stale partial API-command reassembly buffers (a lost chunk would otherwise wedge one forever).
    [{ [GVAR(rxBuffers), GVAR(rxBufferTimes), 30, "rx"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;

    // Prune finished mid-clip-join clips so a dead/finished NPC's WAV doesn't linger in memory.
    [{
        private _now = diag_tickTime;
        {
            _y params ["", "", "_dispatchTime", "_durationMs"];
            if (_now - _dispatchTime > _durationMs / 1000) then { GVAR(activeClips) deleteAt _x };
        } forEach GVAR(activeClips);
    }, 10, []] call CBA_fnc_addPerFrameHandler;
};

// Client-only: the audio extension and player frame data only exist on a
// player client. Nothing to start until the first clip plays (the tick is
// lazily started by fnc_playClip).

if (!hasInterface) exitWith {};

// Route extension STT transcripts to the handler. The extension fires
// callback_data("uksf", "sttTranscript", "[uttId,""text""]").
addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name isEqualTo "uksf" && {_function isEqualTo "sttTranscript"}) then {
        _data call FUNC(onTranscript);
    };
}];

// Stand up the pipe server / callback pump.
call FUNC(sttStart);

// Open mic capture now and never close it. ACRE swallows the first transmission after
// its mic stream (re)opens — the same quirk as a first radio check — so opening here,
// before the player is near any NPC, keeps that first swallow off NPC dialogue wherever
// an earlier transmission can absorb it. Toggling the gate per approach re-armed the
// swallow and reliably ate the player's first words to an NPC.
GVAR(micGateOpen) = true;
[true] call acre_sys_core_fnc_setMicCaptureGate;

// Per-frame proximity/facing gate: picks the talkable NPC the player is addressing.
[FUNC(gateTick), 0.2, []] call CBA_fnc_addPerFrameHandler;

// Mid-clip resync: pull the in-flight clip when entering a talkable NPC's range.
[FUNC(proximityPull), 0.5, []] call CBA_fnc_addPerFrameHandler;

// Sweep stale partial clip-receive buffers (a lost chunk would otherwise wedge one forever).
[{ [GVAR(clipRxBuffers), GVAR(clipRxBufferTimes), 30, "clip"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;
