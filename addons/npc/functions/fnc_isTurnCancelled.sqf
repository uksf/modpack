#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Returns whether this NPC/turn pair has been cancelled.

    Parameter(s):
        0: NPC netId <STRING>
        1: Turn id <STRING>

    Return Value:
        Cancelled <BOOL>

    Example:
        ["2:4", "2:4_123"] call uksf_npc_fnc_isTurnCancelled
*/
params ["_npcId", "_turnId"];
if (_turnId isEqualTo "") exitWith {false};

([_npcId, _turnId] call FUNC(turnKey)) in GVAR(cancelledTurns)
