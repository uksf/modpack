#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Debounce elapsed for an NPC room — batch the pending utterances
        into a npc_turn and send to the API, then clear the room.

    Parameter(s):
        0: npcId <STRING>

    Return Value:
        None

    Example:
        ["2:4"] call uksf_npc_fnc_flushRoom
*/
params ["_npcId"];

private _room = GVAR(rooms) getOrDefault [_npcId, []];
if (_room isEqualTo []) exitWith {};
GVAR(rooms) set [_npcId, []];

private _newTurns = _room apply {
    _x params ["_speakerId", "_text", "_t"];
    createHashMapFromArray [["speakerId", _speakerId], ["text", _text], ["t", _t]]
};

private _turnId = format ["%1_%2", _npcId, round (diag_tickTime * 1000)];

["npc_turn", createHashMapFromArray [
    ["npcId", _npcId],
    ["sessionId", EGVAR(api,sessionId)],
    ["turnId", _turnId],
    ["newTurns", _newTurns]
]] call EFUNC(api,sendEvent);
TRACE_2("flushed room -> npc_turn",_npcId,count _newTurns);
