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

private _fnc_row = {
    params ["_label", "_value"];
    format ["<t color='#94a3b8'>%1</t><br/><t color='#ffffff' size='0.95'>%2</t><br/><br/>", _label, _value]
};
private _fnc_value = {[_this] call FUNC(consoleEscape)};

private _identity = [
    ["Name", _npc getVariable [QGVAR(personaName), name _npc]],
    ["Profile", _profile],
    ["Talkable / alive", format ["%1 / %2", _npc getVariable [QGVAR(talkable), false], alive _npc]],
    ["Addressed", str (_npc isEqualTo GVAR(targetNpc))],
    ["Audio", _audio],
    ["Mood / emote", format ["%1 / %2", _state getOrDefault ["mood", _npc getVariable [QGVAR(personaMood), ""]], (_state getOrDefault ["emote", ""]) call _fnc_value]]
] apply { _x call _fnc_row };

private _pipeline = [
    ["Address decision", _state getOrDefault ["addressDecision", ""]],
    ["Move / topic", format ["%1 / %2", _state getOrDefault ["tag", ""], _state getOrDefault ["topicSlot", ""]]],
    ["Concern / ambiguous", format ["%1 / %2", _state getOrDefault ["addressesConcern", false], _state getOrDefault ["ambiguous", false]]],
    ["Band / warning / burned", format ["%1 / %2 / %3", _state getOrDefault ["cooperation", ""], _state getOrDefault ["pendingWarning", false], _state getOrDefault ["burned", false]]],
    ["Eligible / blocked", format ["%1 / %2", _eligible, _blocked joinString ","]],
    ["Disclosed", _disclosed],
    ["Provider", _state getOrDefault ["provider", ""]],
    ["Classify / reply", format ["%1 / %2 ms", _state getOrDefault ["classifyMs", 0], _state getOrDefault ["replyMs", 0]]],
    ["Reason", (_state getOrDefault ["reason", ""]) call _fnc_value],
    ["Evidence", (_state getOrDefault ["evidence", ""]) call _fnc_value]
] apply { _x call _fnc_row };

private _entries = +(_state getOrDefault ["transcript", []]);
reverse _entries;
private _lines = _entries apply {
    _x params ["_time", "_who", "_text"];
    format [
        "<t color='#64748b'>%1</t> <t color='#93c5fd'>%2</t><br/><t color='#e2e8f0'>%3</t><br/><br/>",
        [_time, "HH:MM:SS"] call BIS_fnc_secondsToString,
        [_who] call FUNC(consoleEscape),
        [_text] call FUNC(consoleEscape)
    ]
};
if (_lines isEqualTo []) then {
    _lines = ["<t color='#64748b'>No consumed speech yet.</t>"];
};

(_display displayCtrl IDC_CONSOLE_TITLE) ctrlSetText format ["NPC Console — %1", _npc getVariable [QGVAR(personaName), name _npc]];
(_display displayCtrl IDC_CONSOLE_DETAILS) ctrlSetStructuredText parseText (_identity joinString "");
(_display displayCtrl IDC_CONSOLE_PIPELINE) ctrlSetStructuredText parseText (_pipeline joinString "");
(_display displayCtrl IDC_CONSOLE_TRANSCRIPT) ctrlSetStructuredText parseText (_lines joinString "");
(_display displayCtrl IDC_CONSOLE_RESET) ctrlEnable (alive _npc);
(_display displayCtrl IDC_CONSOLE_MUTE) ctrlEnable (_npc getVariable [QGVAR(talkable), false]);
(_display displayCtrl IDC_CONSOLE_UNMUTE) ctrlEnable (!(_npc getVariable [QGVAR(talkable), false]) && {alive _npc} && {!(_npc getVariable [QGVAR(playerDropped), false])});
