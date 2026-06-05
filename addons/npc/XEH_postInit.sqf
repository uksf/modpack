#include "script_component.hpp"

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
            call FUNC(registerNpcs);
        }
    ] call CBA_fnc_waitUntilAndExecute;

    // Sweep stale partial API-command reassembly buffers (a lost chunk would otherwise wedge one forever).
    [{ [GVAR(rxBuffers), GVAR(rxBufferTimes), 30, "rx"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;
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

// Per-frame proximity/facing gate: picks the talkable NPC the player is addressing
// and drives the ACRE mic capture gate on the rising/falling edge.
[FUNC(gateTick), 0.2, []] call CBA_fnc_addPerFrameHandler;

// Sweep stale partial clip-receive buffers (a lost chunk would otherwise wedge one forever).
[{ [GVAR(clipRxBuffers), GVAR(clipRxBufferTimes), 30, "clip"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;
