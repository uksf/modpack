#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Opens a streamed reply on the extension and releases any frames held while
        a filler finished sounding.
*/
params ["_clipId", "_npc", ["_wait", 0], ["_npcId", "", [""]], ["_turnId", "", [""]]];

[{
    params ["_clipId", "_npc", "_npcId", "_turnId"];
    if ([_npcId, _turnId] call FUNC(isTurnCancelled)) exitWith {
        GVAR(streamHeld) deleteAt _clipId;
        GVAR(streamingClips) deleteAt _clipId;
    };
    if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
        GVAR(streamHeld) deleteAt _clipId;
        GVAR(streamingClips) deleteAt _clipId;
    };
    if !(_clipId in GVAR(streamingClips)) exitWith { GVAR(streamHeld) deleteAt _clipId; };

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

    { "uksf" callExtension ["audioFeed", [_clipId, _x]]; } forEach (GVAR(streamHeld) getOrDefault [_clipId, []]);
    GVAR(streamHeld) deleteAt _clipId;

    GVAR(streamStart) set [_clipId, diag_tickTime + GVAR(speechPrebuffer)];
    [{
        params ["_npc"];
        if (!isNull _npc) then { _npc setRandomLip true };
    }, [_npc], GVAR(speechPrebuffer)] call CBA_fnc_waitAndExecute;
}, [_clipId, _npc, _npcId, _turnId], _wait] call CBA_fnc_waitAndExecute;
