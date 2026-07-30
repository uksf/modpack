#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Arms one filler for this turn and, if the reply still has not arrived when
        it finishes, arms another after a short pause. A cold model or a slow route can
        leave the player standing in silence for many seconds, and one grunt at the front
        of that does not cover it. Stops as soon as the reply's first audio frame lands,
        which clears the turn's token.

    Parameter(s):
        0: NPC object <OBJECT>
        1: Turn token <NUMBER>
        2: Delay before this filler <NUMBER>
        3: Fillers already played this turn <NUMBER>

    Return Value:
        None

    Example:
        [_npc, _token, 2.2, 0] call uksf_npc_fnc_scheduleFiller
*/
params ["_npc", "_token", "_delay", ["_played", 0]];

[{
    params ["_npc", "_token", "_played"];
    if (isNull _npc) exitWith {};
    private _npcId = netId _npc;
    if ((GVAR(pendingFiller) getOrDefault [_npcId, 0]) isNotEqualTo _token) exitWith {}; // reply arrived

    private _duration = [_npc] call FUNC(playFiller);
    if (_duration <= 0) exitWith {}; // nothing cached for this voice
    _played = _played + 1;
    if (_played >= FILLER_MAX_PER_TURN) exitWith {};

    // Wait out the clip, then leave a natural gap before considering another.
    private _next = _duration + FILLER_GAP_MIN + random FILLER_GAP_SPREAD;
    [_npc, _token, _next, _played] call FUNC(scheduleFiller);
}, [_npc, _token, _played], _delay] call CBA_fnc_waitAndExecute;
