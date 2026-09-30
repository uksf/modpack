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

// Turn debounce is a silence gap. A mash after that gap is a new room.
// Hold it while this NPC still has a turn in flight so we do not double-call.
// A turn whose reply never arrives stops holding after TURN_HOLD_MAX_MS; the
// turn id ends in its start tick in ms.
private _activeTurnId = GVAR(activeTurnIds) getOrDefault [_npcId, ""];
if (
    _activeTurnId isNotEqualTo ""
    && {diag_tickTime * 1000 - parseNumber ((_activeTurnId splitString "_") select -1) < TURN_HOLD_MAX_MS}
) exitWith {
    TRACE_1("flush deferred, turn in flight",_npcId);
    private _retry = diag_tickTime;
    GVAR(roomTimers) set [_npcId, _retry];
    [{
        params ["_npcId", "_retry"];
        if ((GVAR(roomTimers) getOrDefault [_npcId, 0]) isEqualTo _retry) then {
            [_npcId] call FUNC(flushRoom);
        };
    }, [_npcId, _retry], GVAR(debounceSeconds)] call CBA_fnc_waitAndExecute;
};

GVAR(rooms) set [_npcId, []];

private _newTurns = _room apply {
    _x params ["_speakerId", "_text", "_t", "", ["_utt", ""]];
    createHashMapFromArray [["speakerId", _speakerId], ["text", _text], ["t", _t], ["utt", _utt]]
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
