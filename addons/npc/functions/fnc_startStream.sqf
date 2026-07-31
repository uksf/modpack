#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Opens a streamed reply on the extension and releases any frames held while
        a filler finished sounding. Playback, the mouth and the clip's start time are all
        set here, so a reply that waited behind a filler still has its lips in step with
        its own audio rather than with the moment the first frame arrived.

    Parameter(s):
        0: Clip id <STRING>
        1: NPC object <OBJECT>
        2: Seconds to wait before opening <NUMBER>

    Return Value:
        None

    Example:
        [_clipId, _npc, 0.4] call uksf_npc_fnc_startStream
*/
params ["_clipId", "_npc", ["_wait", 0]];

[{
    params ["_clipId", "_npc"];
    if (isNull _npc) exitWith { GVAR(streamHeld) deleteAt _clipId; };
    if !(_clipId in GVAR(streamingClips)) exitWith { GVAR(streamHeld) deleteAt _clipId; }; // superseded while waiting

    // Only now supersede whatever this NPC was playing: doing it when the frame arrived
    // would have cut the filler short, which is the thing being avoided.
    { if ((_x#1) isEqualTo _npc) then { "uksf" callExtension ["audioStop", [_x#0]]; }; } forEach GVAR(active);
    GVAR(active) = GVAR(active) select { (_x#1) isNotEqualTo _npc };

    private _delta = (getPosASL _npc) vectorDiff ((call FUNC(listenerPose)) # 0);
    private _vol = [_npc, 1] call FUNC(acreVol);
    "uksf" callExtension ["audioPlay", [_clipId, _delta#0, _delta#1, _delta#2, _vol, 0]];
    GVAR(active) pushBack [_clipId, _npc, 1];
    if (!GVAR(tickRunning)) then {
        GVAR(tickRunning) = true;
        [FUNC(tick), 0, []] call CBA_fnc_addPerFrameHandler;
    };

    // Release what arrived while the filler played, in order.
    { "uksf" callExtension ["audioFeed", [_clipId, _x]]; } forEach (GVAR(streamHeld) getOrDefault [_clipId, []]);
    GVAR(streamHeld) deleteAt _clipId;

    GVAR(streamStart) set [_clipId, diag_tickTime + SPEECH_PREBUFFER];
    // The extension holds the clip until its prebuffer fills, so the mouth starts when the
    // sound does, not when the clip was opened.
    [{
        params ["_npc"];
        if (!isNull _npc) then { _npc setRandomLip true };
    }, [_npc], SPEECH_PREBUFFER] call CBA_fnc_waitAndExecute;
}, [_clipId, _npc], _wait] call CBA_fnc_waitAndExecute;
