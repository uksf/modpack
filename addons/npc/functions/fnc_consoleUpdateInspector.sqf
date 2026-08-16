#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Updates the open inspector from local and API-fed NPC state.
*/
private _display = uiNamespace getVariable [QGVAR(consoleInspector), displayNull];
private _npc = GVAR(consoleInspectorNpc);
if (isNull _display || {isNull _npc}) exitWith {};

private _npcId = netId _npc;
private _state = [_npcId, true] call FUNC(consoleGetState);
private _profile = _npc getVariable [QGVAR(interactionProfile), "conversation"];
private _disclosed = _state getOrDefault ["disclosed", ""];
private _eligible = _state getOrDefault ["eligible", ""];
private _disclosedIds = if (_disclosed isEqualTo "") then {[]} else {_disclosed splitString ","};
private _blocked = if (_profile isEqualTo "guarded") then {GUARDED_FACT_IDS - _disclosedIds - [_eligible]} else {[]};
private _audio = "idle";
if ((GVAR(fillerBusyUntil) getOrDefault [_npcId, 0]) > diag_tickTime) then {
    _audio = "filler";
} else {
    if ((GVAR(talkingUntil) getOrDefault [_npcId, 0]) > diag_tickTime) then {_audio = "speaking"};
};
if ((GVAR(pendingFiller) getOrDefault [_npcId, 0]) isNotEqualTo 0 && {_audio isEqualTo "idle"}) then {_audio = "waiting"};
if ((keys GVAR(streamingClips)) findIf {_x find _npcId isEqualTo 0} >= 0) then {_audio = "streaming"};

private _fnc_value = {[_this] call FUNC(consoleEscape)};
private _rows = [
    ["Profile", _profile],
    ["Talkable / alive", format ["%1 / %2", _npc getVariable [QGVAR(talkable), false], alive _npc]],
    ["Addressed", str (_npc isEqualTo GVAR(targetNpc))],
    ["Last STT", (_state getOrDefault ["lastStt", ""]) call _fnc_value],
    ["Address decision", _state getOrDefault ["addressDecision", ""]],
    ["Move / topic", format ["%1 / %2", _state getOrDefault ["tag", ""], _state getOrDefault ["topicSlot", ""]]],
    ["Concern / ambiguous", format ["%1 / %2", _state getOrDefault ["addressesConcern", false], _state getOrDefault ["ambiguous", false]]],
    ["Reason", (_state getOrDefault ["reason", ""]) call _fnc_value],
    ["Evidence", (_state getOrDefault ["evidence", ""]) call _fnc_value],
    ["Band / warning / burned", format ["%1 / %2 / %3", _state getOrDefault ["cooperation", ""], _state getOrDefault ["pendingWarning", false], _state getOrDefault ["burned", false]]],
    ["Mood / emote", format ["%1 / %2", _state getOrDefault ["mood", _npc getVariable [QGVAR(personaMood), ""]], (_state getOrDefault ["emote", ""]) call _fnc_value]],
    ["Eligible / blocked", format ["%1 / %2", _eligible, _blocked joinString ","]],
    ["Disclosed", _disclosed],
    ["Provider", _state getOrDefault ["provider", ""]],
    ["Classify / reply", format ["%1 / %2 ms", _state getOrDefault ["classifyMs", 0], _state getOrDefault ["replyMs", 0]]],
    ["Audio", _audio]
];

private _body = _rows apply {format ["<t color='#94a3b8'>%1:</t> <t color='#ffffff'>%2</t>", _x#0, _x#1]};
(_display displayCtrl IDC_CONSOLE_TITLE) ctrlSetText format ["NPC Console — %1", _npc getVariable [QGVAR(personaName), name _npc]];
(_display displayCtrl IDC_CONSOLE_DETAILS) ctrlSetStructuredText parseText (_body joinString "<br/><br/>");
(_display displayCtrl IDC_CONSOLE_RESET) ctrlEnable (_profile isEqualTo "guarded" && {alive _npc});
(_display displayCtrl IDC_CONSOLE_MUTE) ctrlEnable (_npc getVariable [QGVAR(talkable), false]);
(_display displayCtrl IDC_CONSOLE_UNMUTE) ctrlEnable (!(_npc getVariable [QGVAR(talkable), false]) && {alive _npc});
