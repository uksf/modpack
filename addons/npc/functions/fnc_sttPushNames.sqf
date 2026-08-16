#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Push current NPC persona names into the STT decoder as a Whisper hint.
        Rebuilds from live units so a new or renamed NPC is picked up without
        a shipped word list.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttPushNames
*/
if (!hasInterface) exitWith {};

private _names = [];
{
    private _name = _x getVariable [QGVAR(personaName), ""];
    if (_name isNotEqualTo "") then { _names pushBackUnique _name };
} forEach allUnits;
_names sort true;
private _joined = _names joinString " ";
if (_joined isEqualTo GVAR(sttHint)) exitWith {};

GVAR(sttHint) = _joined;
"uksf" callExtension ["sttHint", [_joined]];
