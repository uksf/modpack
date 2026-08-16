#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Copies validated API telemetry into the local inspector state.
*/
params ["_npcId", "_provider", "_addressDecision", "_tag", "_topicSlot", "_addressesConcern", "_ambiguous", "_reason", "_evidence", "_classifyMs", "_replyMs", "_eligible", "_disclosed"];

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
