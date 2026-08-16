#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Rebuilds the replicated STT name list from registered NPCs
        and publishes it when it changes.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttPublishNames
*/
if (!isServer) exitWith {};

private _names = [];
{
    private _npc = objectFromNetId _x;
    if (isNull _npc) then { continue };
    private _name = _npc getVariable [QGVAR(personaName), ""];
    if (_name isNotEqualTo "") then { _names pushBackUnique _name };
} forEach (missionNamespace getVariable [QGVAR(registeredNetIds), []]);
_names sort true;

private _joined = _names joinString " ";
if (_joined isEqualTo (missionNamespace getVariable [QGVAR(sttNames), ""])) exitWith {};
missionNamespace setVariable [QGVAR(sttNames), _joined, true];
