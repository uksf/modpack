#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Arms one filler for this turn and, if the reply still has not arrived when
        it finishes, arms another after a short pause.
*/
params ["_npc", "_token", "_delay", ["_played", 0]];

[{
    params ["_npc", "_token", "_played"];
    if (isNull _npc) exitWith {};
    private _npcId = netId _npc;
    if ((GVAR(pendingFiller) getOrDefault [_npcId, 0]) isNotEqualTo _token) exitWith {};
    if (_played >= GVAR(fillerMaxPerTurn)) exitWith {};

    if (random 1 < GVAR(fillerChance)) then {
        private _class = ["l", "s"] select (diag_tickTime < (GVAR(fillerEarlyUntil) getOrDefault [_npcId, 0]));
        private _duration = [_npc, _class] call FUNC(playFiller);
        if (_duration > 0) then {
            [_npc, _token, _duration + GVAR(fillerGapMin) + random GVAR(fillerGapSpread), _played + 1] call FUNC(scheduleFiller);
        };
    } else {
        [_npc, _token, GVAR(fillerGapMin) + random GVAR(fillerGapSpread), _played + 1] call FUNC(scheduleFiller);
    };
}, [_npc, _token, _played], _delay] call CBA_fnc_waitAndExecute;
