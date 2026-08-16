#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Adds or removes one NPC from the replicated talkable list. Register never
        unmutes: a muted id stays off the list until unmute.

    Parameter(s):
        0: NPC netId <STRING>
        1: Add <BOOL>

    Return Value:
        None

    Example:
        ["2:4", true] call uksf_npc_fnc_setTalkerList
*/
if (!isServer) exitWith {};
params ["_npcId", "_add"];

private _talkers = missionNamespace getVariable [QGVAR(talkerNetIds), []];
private _muted = missionNamespace getVariable [QGVAR(mutedNetIds), []];
if (_add) then {
    if (_npcId in _muted) exitWith {};
    _talkers pushBackUnique _npcId;
} else {
    _talkers = _talkers - [_npcId];
};
missionNamespace setVariable [QGVAR(talkerNetIds), _talkers, true];
