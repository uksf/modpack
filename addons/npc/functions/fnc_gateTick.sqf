#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Per-frame client gate. Decides which single NPC the local player is addressing.
        Candidates come from the replicated talkable list.
*/
params ["", "_idPFH"];

private _player = call CBA_fnc_currentUnit;
private _best = objNull;
private _bestScore = 1e9;
if (alive _player) then {
    private _forward = eyeDirection _player;
    private _eye = eyePos _player;
    private _scan = GVAR(gateScanRadius);
    {
        private _npc = objectFromNetId _x;
        if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) then { continue };
        if ((_player distance _npc) > _scan) then { continue };
        if !([_player, _npc] call FUNC(isInGate)) then { continue };
        private _toNpc = (eyePos _npc) vectorDiff _eye;
        private _score = 1 - (_forward vectorDotProduct (vectorNormalized _toNpc));
        if (_score < _bestScore) then { _bestScore = _score; _best = _npc; };
    } forEach (missionNamespace getVariable [QGVAR(talkerNetIds), []]);
};

private _current = GVAR(targetNpc);
private _currentHeld = !isNull _current
    && {alive _current}
    && {_current getVariable [QGVAR(talkable), false]}
    && {[_player, _current] call FUNC(isInGate)};
if (_currentHeld && {_best isNotEqualTo _current}) then {
    private _forward = eyeDirection _player;
    private _eye = eyePos _player;
    private _curScore = 1 - (_forward vectorDotProduct (vectorNormalized ((eyePos _current) vectorDiff _eye)));
    if (_bestScore < (_curScore - GVAR(gateSwitchMargin))) then {
        GVAR(targetCandidate) = GVAR(targetCandidate) + 1;
    } else {
        GVAR(targetCandidate) = 0;
    };
    if (GVAR(targetCandidate) < GVAR(gateSwitchFrames)) then {
        _best = _current;
    };
} else {
    GVAR(targetCandidate) = 0;
};

if (_best isEqualTo GVAR(targetNpc)) exitWith {};

GVAR(targetNpc) = _best;
TRACE_2("target npc",_best,_bestScore);
