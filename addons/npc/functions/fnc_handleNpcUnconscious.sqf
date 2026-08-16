#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Handles ACE unconsciousness for a registered NPC. Player-caused uncon is
        permanently terminal. Other uncon stops speech while the unit is down.
        A guarded source stays terminal on any uncon.

    Parameter(s):
        0: NPC <OBJECT>
        1: Unconscious <BOOL>
        2: Player caused <BOOL>

    Return Value:
        None

    Example:
        [_npc, true, true] call uksf_npc_fnc_handleNpcUnconscious
*/
if (!isServer) exitWith {};
params ["_npc", "_active", ["_playerCaused", false, [false]]];
if (isNull _npc) exitWith {};

private _npcId = netId _npc;
private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if !(_npcId in _registered) exitWith {};

private _profile = _npc getVariable [QGVAR(interactionProfile), "conversation"];
private _terminal = _npc getVariable [QGVAR(playerDropped), false]
    || {_profile isEqualTo "guarded"}
    || {_active && {_playerCaused}};

if (_active && {_playerCaused}) then {
    _npc setVariable [QGVAR(playerDropped), true, true];
};

if (_terminal) exitWith {
    _npc setVariable [QGVAR(talkable), false, true];
    [_npcId] call FUNC(cancelNpc);
    [_npcId, false] call FUNC(setTalkerList);
    TRACE_3("npc uncon terminal",_npcId,_profile,_playerCaused);
};

if (_active) exitWith {
    [_npcId] call FUNC(cancelNpc);
    _npc setVariable [QGVAR(talkable), false, true];
    [_npcId, false] call FUNC(setTalkerList);
    TRACE_1("npc uncon paused speech",_npcId);
};

if !(_npc getVariable [QGVAR(playerDropped), false]) then {
    if !(_npcId in (missionNamespace getVariable [QGVAR(mutedNetIds), []])) then {
        _npc setVariable [QGVAR(talkable), true, true];
        [_npcId, true] call FUNC(setTalkerList);
    };
};
