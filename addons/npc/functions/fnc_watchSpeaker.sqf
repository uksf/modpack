#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Turns the NPC to face the player who just spoke and keeps it facing them
        while they keep talking. The NPC is released when the hold runs out.

    Parameter(s):
        0: NPC <OBJECT>
        1: Speaker <OBJECT>

    Return Value:
        None

    Example:
        [_npc, player] call uksf_npc_fnc_watchSpeaker
*/
params ["_npc", "_speaker"];
if (isNull _npc || {isNull _speaker} || {!alive _npc}) exitWith {};

private _npcId = netId _npc;
private _sameTarget = (GVAR(watchTarget) getOrDefault [_npcId, objNull]) isEqualTo _speaker;
private _remaining = (GVAR(watchUntil) getOrDefault [_npcId, 0]) - diag_tickTime;
if (_sameTarget && {_remaining > GVAR(watchHold) / 2}) exitWith {};

if (!_sameTarget) then {
    [QGVAR(doWatch), [_npc, _speaker], _npc] call CBA_fnc_targetEvent;
    GVAR(watchTarget) set [_npcId, _speaker];
};

private _until = diag_tickTime + GVAR(watchHold);
GVAR(watchUntil) set [_npcId, _until];
[{
    params ["_npc", "_npcId", "_until"];
    if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > _until) exitWith {};
    GVAR(watchTarget) deleteAt _npcId;
    GVAR(watchUntil) deleteAt _npcId;
    if (!isNull _npc) then {
        [QGVAR(doWatch), [_npc, objNull], _npc] call CBA_fnc_targetEvent;
    };
}, [_npc, _npcId, _until], GVAR(watchHold)] call CBA_fnc_waitAndExecute;
