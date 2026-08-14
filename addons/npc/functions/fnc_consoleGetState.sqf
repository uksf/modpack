#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Returns the local debug state for an NPC, creating the empty state when needed.
*/
params ["_npcOrId"];

private _npcId = if (_npcOrId isEqualType "") then {_npcOrId} else {netId _npcOrId};
private _state = GVAR(consoleStates) getOrDefault [_npcId, createHashMap];
if !(_npcId in GVAR(consoleStates)) then {
    GVAR(consoleStates) set [_npcId, _state];
};
_state
