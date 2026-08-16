#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Copies validated API telemetry into the local inspector state.
*/
params ["_npcId", "_provider", "_addressDecision", "_tag", "_topicSlot", "_addressesConcern", "_ambiguous", "_reason", "_evidence", "_classifyMs", "_replyMs", "_eligible", "_disclosed", ["_spoken", "", [""]]];

private _state = [_npcId, true] call FUNC(consoleGetState);
if !(_npcId in GVAR(consoleStates)) exitWith {};
_state set ["provider", _provider];
_state set ["addressDecision", _addressDecision];
_state set ["tag", _tag];
_state set ["topicSlot", _topicSlot];
_state set ["addressesConcern", _addressesConcern];
_state set ["ambiguous", _ambiguous];
_state set ["reason", _reason];
_state set ["evidence", _evidence];
_state set ["classifyMs", _classifyMs];
_state set ["replyMs", _replyMs];
_state set ["eligible", _eligible];
_state set ["disclosed", _disclosed];
_state set ["spoken", _spoken];

private _transcript = +(_state getOrDefault ["transcript", []]);
if (_addressDecision isEqualTo "answer" && {_state getOrDefault ["lastStt", ""] isNotEqualTo ""}) then {
    _transcript pushBack [serverTime, _state getOrDefault ["lastSpeakerName", "Player"], _state get "lastStt"];
    _state set ["lastStt", ""];
};
if (_spoken isNotEqualTo "") then {
    private _npc = objectFromNetId _npcId;
    private _name = if (isNull _npc) then {"NPC"} else {_npc getVariable [QGVAR(personaName), name _npc]};
    _transcript pushBack [serverTime, _name, _spoken];
};
if (count _transcript > 40) then {
    _transcript = _transcript select [count _transcript - 40, 40];
};
_state set ["transcript", _transcript];
