#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Plays a random cached filler clip in the NPC's voice as a latency
        mask, anchored to the NPC. No-op if no fillers are cached for this voice yet.

    Parameter(s):
        0: NPC object <OBJECT>

    Return Value:
        None

    Example:
        [_npc] call uksf_npc_fnc_playFiller
*/
params ["_npc", ["_class", "s"]];
if (isNull _npc) exitWith { 0 };

private _voiceId = _npc getVariable [QGVAR(voiceId), ""];
private _list = GVAR(fillers) getOrDefault [_voiceId, []];
if (_list isEqualTo []) exitWith { 0 };

// s-set for a short wait, l-set for a long one. Fall back to the whole set rather than
// staying silent if only one class made it through the prerender.
private _pool = _list select { (_x#0) select [0, 1] isEqualTo _class };
if (_pool isEqualTo []) then { _pool = _list };

(selectRandom _pool) params ["_fillerId", "_wav", ["_durationMs", 0]];
GVAR(fillerCounter) = GVAR(fillerCounter) + 1;
[format ["%1_filler_%2", netId _npc, GVAR(fillerCounter)], _npc, _wav] call FUNC(playClip);

// The reply waits for the filler to finish rather than cutting it off, so the whole
// pipeline needs to know when the mouth is free again.
private _duration = (_durationMs / 1000) max 0.1;
private _endTime = diag_tickTime + _duration;
GVAR(fillerBusyUntil) set [netId _npc, _endTime];

// A filler is speech, so it moves the mouth like speech does.
GVAR(talkingUntil) set [netId _npc, _endTime];
_npc setRandomLip true;
[{
    params ["_npc", "_npcId", "_endTime"];
    if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > _endTime) exitWith {}; // the reply took the mouth over
    if (!isNull _npc) then { _npc setRandomLip false };
}, [_npc, netId _npc, _endTime], _duration] call CBA_fnc_waitAndExecute;

_duration
