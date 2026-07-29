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
params ["_npc"];
if (isNull _npc) exitWith {};

private _voiceId = _npc getVariable [QGVAR(voiceId), ""];
private _list = GVAR(fillers) getOrDefault [_voiceId, []];
if (_list isEqualTo []) exitWith {};

(selectRandom _list) params ["_fillerId", "_wav"];
GVAR(fillerCounter) = GVAR(fillerCounter) + 1;
[format ["%1_filler_%2", netId _npc, GVAR(fillerCounter)], _npc, _wav] call FUNC(playClip);
