#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side. Registers every queued talkable NPC once the API session exists.

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

private _queue = missionNamespace getVariable [QGVAR(pendingRegister), []];
TRACE_2("registerNpcs start",_sessionId,count _queue);

{
    private _npc = _x;
    if (isNull _npc || {!alive _npc}) then { continue };
    if !(_npc getVariable [QGVAR(talkable), false]) then { continue };
    if !([_npc] call FUNC(registerNpc)) then {
        _npc setVariable [QGVAR(talkable), false, true];
    };
} forEach _queue;

missionNamespace setVariable [QGVAR(pendingRegister), []];
