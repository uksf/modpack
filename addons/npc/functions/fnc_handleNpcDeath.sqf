#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Permanently ends a talkable NPC after death. Cancels in-flight work and
        removes the unit from the talkable list for every profile.
*/
if (!isServer) exitWith {};
params ["_npc"];
if (isNull _npc) exitWith {};

private _npcId = netId _npc;
private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if (!(_npc getVariable [QGVAR(talkable), false]) && {!(_npcId in _registered)}) exitWith {};

[_npc] call FUNC(wipeNpc);
TRACE_1("npc death, wiped",_npcId);
