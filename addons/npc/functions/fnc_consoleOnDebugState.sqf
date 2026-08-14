#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates API debug telemetry and sends it only to authorised clients.
*/
if (!isServer) exitWith {};
params ["_args"];
if (!(_args isEqualType []) || {count _args < DEBUG_STATE_FIELDS}) exitWith {};

_args params [
    "_npcId", "_provider", "_addressDecision", "_tag", "_topicSlot", "_addressesConcern", "_ambiguous",
    "_reason", "_evidence", "_classifyMs", "_replyMs", "_eligible", "_disclosed"
];
if (_topicSlot isEqualType 0) then {_topicSlot = str _topicSlot};
private _strings = [_npcId, _provider, _addressDecision, _tag, _topicSlot, _reason, _evidence, _eligible, _disclosed];
if ((_strings findIf {!(_x isEqualType "")}) >= 0) exitWith {};
if (!(_addressesConcern isEqualType false) || {!(_ambiguous isEqualType false)}) exitWith {};
if (!(_classifyMs isEqualType 0) || {_classifyMs < 0} || {!(_replyMs isEqualType 0)} || {_replyMs < 0}) exitWith {};
if !(_addressDecision in ["", "answer", "stay_silent", "ask_the_brain", "none"]) exitWith {};

private _npc = objectFromNetId _npcId;
if (isNull _npc) exitWith {};
private _ids = [];
if (_eligible isNotEqualTo "") then {_ids pushBack _eligible};
if (_disclosed isNotEqualTo "") then {_ids append (_disclosed splitString ",")};
if ((_ids findIf {!(_x in GUARDED_FACT_IDS)}) >= 0) exitWith {};

for "_index" from 1 to GUARDED_FACT_COUNT do {
    private _fact = _npc getVariable [format ["%1%2", QGVAR(guardedFact), _index], ""];
    if (_fact isNotEqualTo "") then {
        if ((toLower _reason) find (toLower _fact) >= 0) then {_reason = "[redacted]"};
        if ((toLower _evidence) find (toLower _fact) >= 0) then {_evidence = "[redacted]"};
    };
};
private _knowledge = _npc getVariable [QGVAR(knowledge), ""];
if (_knowledge isNotEqualTo "") then {
    if ((toLower _reason) find (toLower _knowledge) >= 0) then {_reason = "[redacted]"};
    if ((toLower _evidence) find (toLower _knowledge) >= 0) then {_evidence = "[redacted]"};
};
_reason = _reason select [0, DEBUG_TEXT_MAX];
_evidence = _evidence select [0, DEBUG_TEXT_MAX];
private _targets = ALL_PLAYERS select {(getPlayerUID _x) in WHITELIST || {admin (owner _x) > 0}};
if (_targets isEqualTo []) exitWith {};
[QGVAR(debugStateSink), [_npcId, _provider, _addressDecision, _tag, _topicSlot, _addressesConcern, _ambiguous, _reason, _evidence, _classifyMs, _replyMs, _eligible, _disclosed], _targets] call CBA_fnc_targetEvent;
