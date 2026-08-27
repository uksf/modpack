#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Unit-owned init. Queues a talkable NPC for registration. Does not set the
        talkable flag; Eden or script already owns that.

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        None

    Example:
        [_unit] call uksf_npc_fnc_onUnitInit
*/
params ["_unit"];
if (!isServer) exitWith {};
if (isNull _unit || {!(_unit isKindOf "CAManBase")} || {!alive _unit}) exitWith {};
if !(_unit getVariable [QGVAR(talkable), false]) exitWith {};

private _queue = missionNamespace getVariable [QGVAR(pendingRegister), []];
_queue pushBackUnique _unit;
missionNamespace setVariable [QGVAR(pendingRegister), _queue];
if (isNil {EGVAR(api,sessionId)}) exitWith {};
if ([_unit] call FUNC(registerNpc)) then {
    private _remaining = (missionNamespace getVariable [QGVAR(pendingRegister), []]) - [_unit];
    missionNamespace setVariable [QGVAR(pendingRegister), _remaining];
};
