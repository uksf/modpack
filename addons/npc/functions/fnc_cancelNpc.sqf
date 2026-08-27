#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Cancels every open turn for one NPC: the current room, the active turn,
        and any in-flight stream or complete clip.

    Parameter(s):
        0: NPC netId <STRING>

    Return Value:
        None

    Example:
        ["2:4"] call uksf_npc_fnc_cancelNpc
*/
if (!isServer) exitWith {};
params ["_npcId"];
if (_npcId isEqualTo "") exitWith {};

GVAR(rooms) deleteAt _npcId;
GVAR(roomTimers) deleteAt _npcId;

private _turnIds = [];
private _active = GVAR(activeTurnIds) getOrDefault [_npcId, ""];
if (_active isNotEqualTo "") then { _turnIds pushBackUnique _active };
private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo []) then { _turnIds pushBackUnique (_stream select 0) };
private _clip = GVAR(activeClips) getOrDefault [_npcId, []];
if (_clip isNotEqualTo []) then { _turnIds pushBackUnique (_clip select 0) };
if (_turnIds isEqualTo []) then {
    [QGVAR(turnCancelSink), [_npcId, ""], ALL_PLAYERS] call CBA_fnc_targetEvent;
    [GVAR(consoleClients), QGVAR(consoleClearPendingSink), [_npcId]] call EFUNC(common,streamClientsFanout);
} else {
    { [_npcId, _x] call FUNC(cancelTurn) } forEach _turnIds;
};
GVAR(lastSpeaker) deleteAt _npcId;
GVAR(watchUntil) deleteAt _npcId;
private _npc = objectFromNetId _npcId;
if (!isNull _npc) then {
    [QGVAR(doWatch), [_npc, objNull], _npc] call CBA_fnc_targetEvent;
};
