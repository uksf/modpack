#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Builds the turn-scoped key used for cancel tombstones and delayed callbacks.

    Parameter(s):
        0: NPC netId <STRING>
        1: Turn id <STRING>

    Return Value:
        Key <STRING>

    Example:
        ["2:4", "2:4_123"] call uksf_npc_fnc_turnKey
*/
params ["_npcId", "_turnId"];

format ["%1|%2", _npcId, _turnId]
