#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Points the NPC at the player who just spoke to them: head track while the
        conversation runs, and a body turn first if the speaker is well outside the arc a
        head can cover. Fires on utterance, so the acknowledgement starts the moment the
        player talks, not when the reply lands. Held by a rolling deadline; every new
        utterance extends it, and the watch releases when the conversation lapses.

    Parameter(s):
        0: NPC object <OBJECT>
        1: Speaker object <OBJECT>

    Return Value:
        None

    Example:
        [_npc, _speaker] call uksf_npc_fnc_watchSpeaker
*/
params ["_npc", "_speaker"];
if (isNull _npc || {isNull _speaker} || {!alive _npc}) exitWith {};

private _npcId = netId _npc;
private _relDir = _npc getRelDir _speaker;

// Beyond the head's comfortable arc the body comes round first, in a few steps so it
// reads as a turn rather than a snap. disableAI MOVE stops walking, not setDir.
if (_relDir > 60 && {_relDir < 300}) then {
    private _targetDir = _npc getDir _speaker;
    private _startDir = getDir _npc;
    private _delta = ((_targetDir - _startDir + 540) % 360) - 180; // shortest way round
    for "_step" from 1 to 4 do {
        [{
            params ["_npc", "_dir"];
            if (!isNull _npc) then { _npc setDir _dir };
        }, [_npc, _startDir + _delta * _step / 4], _step * 0.15] call CBA_fnc_waitAndExecute;
    };
};

_npc doWatch _speaker;

// Rolling hold: each utterance pushes the deadline out; the watch only releases once
// nobody has spoken to this NPC for WATCH_HOLD seconds.
private _until = diag_tickTime + WATCH_HOLD;
GVAR(watchUntil) set [_npcId, _until];
[{
    params ["_npc", "_npcId", "_until"];
    if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > _until) exitWith {}; // conversation still going
    if (!isNull _npc) then { _npc doWatch objNull };
}, [_npc, _npcId, _until], WATCH_HOLD] call CBA_fnc_waitAndExecute;
