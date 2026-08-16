#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Points the NPC's head at the player who just spoke. Deadline stays
        on the server; lookAt runs on the unit owner at fire time.
*/
params ["_npc", "_speaker"];
if (isNull _npc || {isNull _speaker} || {!alive _npc}) exitWith {};

private _npcId = netId _npc;
if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > diag_tickTime && {
    (GVAR(watchTarget) getOrDefault [_npcId, objNull]) isEqualTo _speaker
}) exitWith {};
[QGVAR(doWatch), [_npc, _speaker], _npc] call CBA_fnc_targetEvent;
GVAR(watchTarget) set [_npcId, _speaker];

private _until = diag_tickTime + GVAR(watchHold);
GVAR(watchUntil) set [_npcId, _until];
[{
    params ["_npc", "_npcId", "_until"];
    if ((GVAR(watchUntil) getOrDefault [_npcId, 0]) > _until) exitWith {};
    GVAR(watchTarget) deleteAt _npcId;
    if (!isNull _npc) then {
        [QGVAR(doWatch), [_npc, objNull], _npc] call CBA_fnc_targetEvent;
    };
}, [_npc, _npcId, _until], GVAR(watchHold)] call CBA_fnc_waitAndExecute;
