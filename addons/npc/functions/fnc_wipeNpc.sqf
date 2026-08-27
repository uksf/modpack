#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Removes one NPC from every local list. Death is the only caller.
        The corpse stays in the world. The NPC system forgets it.

    Parameter(s):
        0: NPC <OBJECT>

    Return Value:
        None

    Example:
        [_npc] call uksf_npc_fnc_wipeNpc
*/
if (!isServer) exitWith {};
params ["_npc"];
if (isNull _npc) exitWith {};

private _npcId = netId _npc;
_npc setVariable [QGVAR(talkable), false, true];
[_npcId] call FUNC(cancelNpc);

private _registered = (missionNamespace getVariable [QGVAR(registeredNetIds), []]) - [_npcId];
missionNamespace setVariable [QGVAR(registeredNetIds), _registered, true];
private _muted = (missionNamespace getVariable [QGVAR(mutedNetIds), []]) - [_npcId];
missionNamespace setVariable [QGVAR(mutedNetIds), _muted, true];
[_npcId, false] call FUNC(setTalkerList);

private _pending = (missionNamespace getVariable [QGVAR(pendingRegister), []]) - [_npc];
missionNamespace setVariable [QGVAR(pendingRegister), _pending];
call FUNC(sttPublishNames);
TRACE_1("wiped dead npc",_npcId);
