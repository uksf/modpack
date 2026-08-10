#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side. Scans all units for the uksf_npc_talkable attribute and
        registers each with the API broker (npc_register). npcId = netId.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_registerNpcs
*/

if (!isServer) exitWith {};

private _sessionId = EGVAR(api,sessionId);
if (isNil "_sessionId") exitWith { TRACE_1("no session id, skipping npc register",_sessionId); };

private _talkableCount = { _x getVariable [QGVAR(talkable), false] } count allUnits;
TRACE_3("registerNpcs start",_sessionId,count allUnits,_talkableCount);

private _registered = [];
{
    private _npc = _x;
    if !(_npc getVariable [QGVAR(talkable), false]) then { continue };
    // Registration refused: drop the talkable flag too, or the client gate keeps offering a
    // conversation the API has no session for.
    if !([_npc] call FUNC(registerNpc)) then {
        _npc setVariable [QGVAR(talkable), false, true];
        continue
    };
    _registered pushBack netId _npc;
} forEach allUnits;

missionNamespace setVariable [QGVAR(talkerNetIds), _registered, true];
