#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Debounce elapsed for an NPC room — batch the pending utterances
        into a npc_turn and send to the API, then clear the room.
*/
params ["_npcId"];

private _npc = objectFromNetId _npcId;
if (isNull _npc || {!alive _npc} || {!(_npc getVariable [QGVAR(talkable), false])}) exitWith {
    GVAR(rooms) deleteAt _npcId;
};

private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if !(_npcId in _registered) exitWith {
    GVAR(rooms) deleteAt _npcId;
};

private _room = GVAR(rooms) getOrDefault [_npcId, []];
if (_room isEqualTo []) exitWith {};
GVAR(rooms) set [_npcId, []];

private _newTurns = _room apply {
    _x params ["_speakerId", "_text", "_t"];
    createHashMapFromArray [["speakerId", _speakerId], ["text", _text], ["t", _t]]
};

private _gazeAddressed = (_room findIf { _x param [3, false] }) != -1;
private _turnId = format ["%1_%2", _npcId, round (diag_tickTime * 1000)];
GVAR(activeTurnIds) set [_npcId, _turnId];

["npc_turn", createHashMapFromArray [
    ["npcId", _npcId],
    ["sessionId", EGVAR(api,sessionId)],
    ["turnId", _turnId],
    ["gazeAddressed", _gazeAddressed],
    ["newTurns", _newTurns]
]] call EFUNC(api,sendEvent);
TRACE_2("flushed room -> npc_turn",_npcId,count _newTurns);
