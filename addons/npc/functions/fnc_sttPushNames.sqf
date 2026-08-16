#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Forwards the replicated NPC name list to the STT decoder.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttPushNames
*/
if (!hasInterface) exitWith {};

private _names = missionNamespace getVariable [QGVAR(sttNames), ""];
if (_names isEqualTo GVAR(sttHint)) exitWith {};

GVAR(sttHint) = _names;
"uksf" callExtension ["sttHint", [_names]];
