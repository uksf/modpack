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
    if (_played >= FILLER_MAX_PER_TURN) exitWith {};

    // Each wait-point rolls its own small chance: most turns stay silent, a long wait
    // accumulates chances instead of guaranteeing a noise.
    if (random 1 < FILLER_CHANCE) then {
        // Inside the short window the wait might still resolve quickly, so the noise
        // promises little; past it the wait is real and earns the longer sound.
        private _class = ["l", "s"] select (diag_tickTime < (GVAR(fillerEarlyUntil) getOrDefault [_npcId, 0]));
        private _duration = [_npc, _class] call FUNC(playFiller);
        if (_duration > 0) then {
            [{ _this call FUNC(scheduleFiller); }, [_npc, _token, _played + 1], _duration + FILLER_GAP_MIN + random FILLER_GAP_SPREAD] call CBA_fnc_waitAndExecute;
        };
    } else {
        [_npc, _token, FILLER_GAP_MIN + random FILLER_GAP_SPREAD, _played + 1] call FUNC(scheduleFiller);
    };
}, [_npc, _token, _played], _delay] call CBA_fnc_waitAndExecute;
