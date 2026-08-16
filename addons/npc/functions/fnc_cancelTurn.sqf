#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Cancels one NPC turn. Later audio, fillers, and delayed callbacks for that
        turn are dropped. Other turns for the same NPC stay live.

    Parameter(s):
        0: NPC netId <STRING>
        1: Turn id <STRING>

    Return Value:
        None

    Example:
        ["2:4", "2:4_123"] call uksf_npc_fnc_cancelTurn
*/
if (!isServer) exitWith {};
params ["_npcId", "_turnId"];
if (_npcId isEqualTo "" || {_turnId isEqualTo ""}) exitWith {};

GVAR(cancelledTurns) set [[_npcId, _turnId] call FUNC(turnKey), diag_tickTime];
if ((GVAR(activeTurnIds) getOrDefault [_npcId, ""]) isEqualTo _turnId) then {
    GVAR(activeTurnIds) deleteAt _npcId;
    GVAR(rooms) deleteAt _npcId;
    GVAR(roomTimers) deleteAt _npcId;
};

private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo [] && {(_stream select 0) isEqualTo _turnId}) then {
    GVAR(activeStreams) deleteAt _npcId;
};

private _clip = GVAR(activeClips) getOrDefault [_npcId, []];
if (_clip isNotEqualTo [] && {(_clip select 0) isEqualTo _turnId}) then {
    GVAR(activeClips) deleteAt _npcId;
};

[QGVAR(turnCancelSink), [_npcId, _turnId], ALL_PLAYERS] call CBA_fnc_targetEvent;
[GVAR(consoleClients), QGVAR(consoleClearPendingSink), [_npcId]] call EFUNC(common,streamClientsFanout);
TRACE_2("cancelled turn",_npcId,_turnId);
