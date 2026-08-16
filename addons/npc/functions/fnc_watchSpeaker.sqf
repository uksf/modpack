#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Points the NPC at the player who just spoke to them. Deadline stays
        on the server; doWatch runs on the unit owner at fire time.
*/
params ["_npc", "_speaker"];
if (isNull _npc || {isNull _speaker} || {!alive _npc}) exitWith {};

private _npcId = netId _npc;
[QGVAR(doWatch), [_npc, _speaker], _npc] call CBA_fnc_targetEvent;

private _until = diag_tickTime + GVAR(watchHold);
GVAR(watchUntil) set [_npcId, _until];
[{
    params ["_npc", "_npcId", "_until"];
    if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > _until) exitWith {};
    if (!isNull _npc) then {
        [QGVAR(doWatch), [_npc, objNull], _npc] call CBA_fnc_targetEvent;
    };
}, [_npc, _npcId, _until], GVAR(watchHold)] call CBA_fnc_waitAndExecute;
