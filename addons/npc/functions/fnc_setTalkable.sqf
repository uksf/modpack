#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Marks a unit talkable or not. A newly talkable unit is queued for
        registration. Clearing talkable cancels work and drops the talker list
        entry without unregistering the API session.

    Parameter(s):
        0: Unit <OBJECT>
        1: Talkable <BOOL>

    Return Value:
        None

    Example:
        [_npc, true] call uksf_npc_fnc_setTalkable
*/
params ["_unit", "_talkable"];
if (isNull _unit) exitWith {};

if (!isServer) exitWith {
    [QGVAR(setTalkable), [_unit, _talkable]] call CBA_fnc_serverEvent;
};

if (!_talkable) exitWith {
    private _npcId = netId _unit;
    _unit setVariable [QGVAR(talkable), false, true];
    [_npcId] call FUNC(cancelNpc);
    [_npcId, false] call FUNC(setTalkerList);
};

if (_unit getVariable [QGVAR(playerDropped), false]) exitWith {};
_unit setVariable [QGVAR(talkable), true, true];
[_unit] call FUNC(onUnitInit);
