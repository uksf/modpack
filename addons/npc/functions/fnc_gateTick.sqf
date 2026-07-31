#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Per-frame client gate. Decides which single NPC the local player is addressing, if
        any, and drives the ACRE mic capture gate on the rising/falling edge.

        Selection is by aim, not distance: among every talkable NPC inside its gate cone,
        the one nearest the crosshair centre wins, so two NPCs standing together never both
        capture — the one the player is actually looking at does. The current target is then
        held with stickiness: a brief glance at another NPC does not flip the target
        mid-sentence, only a clearly sustained change of aim does.

    Parameter(s):
        0: PFH args <ARRAY>
        1: PFH id <NUMBER>
*/
params ["", "_idPFH"];

private _player = call CBA_fnc_currentUnit;
private _best = objNull;
private _bestScore = 1e9;
if (alive _player) then {
    private _forward = eyeDirection _player;
    private _eye = eyePos _player;
    {
        if (_x getVariable [QGVAR(talkable), false] && {[_player, _x] call FUNC(isInGate)}) then {
            // Angular distance from the crosshair: lower is more directly looked at.
            private _toNpc = (eyePos _x) vectorDiff _eye;
            private _score = 1 - (_forward vectorDotProduct (vectorNormalized _toNpc));
            if (_score < _bestScore) then { _bestScore = _score; _best = _x; };
        };
    } forEach (_player nearEntities [["CAManBase"], GATE_SCAN_RADIUS]);
};

// Stickiness: keep the current target unless the rival is clearly closer to the crosshair
// centre and stays that way for a moment. Kills twitch when two NPCs stand close.
private _current = GVAR(targetNpc);
private _currentHeld = !isNull _current && {alive _current} && {[_player, _current] call FUNC(isInGate)};
if (_currentHeld && {_best isNotEqualTo _current}) then {
    // Both are in the gate: only switch once the rival has been clearly closer to the
    // crosshair for a run of frames, so a glance does not steal the turn.
    private _forward = eyeDirection _player;
    private _eye = eyePos _player;
    private _curScore = 1 - (_forward vectorDotProduct (vectorNormalized ((eyePos _current) vectorDiff _eye)));
    if (_bestScore < (_curScore - GATE_SWITCH_MARGIN)) then {
        GVAR(targetCandidate) = GVAR(targetCandidate) + 1;
    } else {
        GVAR(targetCandidate) = 0; // rival not clearly better: stay
    };
    if (GVAR(targetCandidate) < GATE_SWITCH_FRAMES) then {
        _best = _current; // not sustained yet — hold the current target
    };
} else {
    // Look away and the target releases at once. Holding it meant a player facing nobody
    // still had a target, and an unnamed question was answered by whoever they last faced.
    GVAR(targetCandidate) = 0;
};

if (_best isEqualTo GVAR(targetNpc)) exitWith {};

GVAR(targetNpc) = _best;
TRACE_2("target npc",_best,_bestScore);
