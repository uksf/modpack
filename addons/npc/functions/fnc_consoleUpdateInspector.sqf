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

private _fnc_escape = {[_this] call FUNC(consoleEscape)};
private _fnc_yesNo = {["No", "Yes"] select _this};
private _fnc_heading = {format ["<t color='#cbd5e1'>%1</t><br/>", _this]};
private _fnc_row = {
    params ["_label", "_value"];
    format ["<t color='#94a3b8'>%1</t> <t color='#ffffff' size='0.95'>%2</t><br/>", _label, _value]
};

private _fnc_speech = {
    switch (_this) do {
        case "filler": {"Filler"};
        case "speaking": {"Speaking"};
        case "waiting": {"Waiting"};
        case "streaming": {"Streaming"};
        default {"Idle"};
    }
};

private _fnc_address = {
    switch (_this) do {
        case "answer": {"This NPC"};
        case "stay_silent": {"Not this NPC"};
        case "ask_the_brain": {"Uncertain - checking with AI"};
        default {"None"};
    }
};

private _talkable = _npc getVariable [QGVAR(talkable), false];
private _warning = if (_state getOrDefault ["pendingWarning", false]) then {"Threat warning active"} else {"None"};
private _conversation = if (_state getOrDefault ["burned", false]) then {"Ended"} else {"Open"};
private _factsRevealed = if (_disclosed isEqualTo "") then {"None"} else {_disclosed};
private _factAllowed = if (_eligible isEqualTo "") then {"None"} else {_eligible};
private _factsHeldBack = if (_blocked isEqualTo []) then {"None"} else {_blocked joinString ","};

private _fnc_state = {
    private _lines = [
        "Current status" call _fnc_heading,
        ["Alive", (alive _npc) call _fnc_yesNo] call _fnc_row,
        ["Can talk", _talkable call _fnc_yesNo] call _fnc_row,
        ["Looking at this NPC", (_npc isEqualTo GVAR(targetNpc)) call _fnc_yesNo] call _fnc_row,
        ["Speech", _audio call _fnc_speech] call _fnc_row,
        ["Last mood", (_state getOrDefault ["mood", _npc getVariable [QGVAR(personaMood), ""]]) call _fnc_escape] call _fnc_row,
        ["Last gesture", (_state getOrDefault ["emote", ""]) call _fnc_escape] call _fnc_row,
        "<br/>",
        "Conversation progress" call _fnc_heading,
        ["Cooperation", (_state getOrDefault ["cooperation", ""]) call _fnc_escape] call _fnc_row,
        ["Warning", _warning] call _fnc_row,
        ["Conversation", _conversation] call _fnc_row,
        ["Facts revealed", _factsRevealed call _fnc_escape] call _fnc_row
    ];
    _lines joinString ""
};

private _fnc_exchange = {
    private _reason = (_state getOrDefault ["reason", ""]) call _fnc_escape;
    private _evidence = (_state getOrDefault ["evidence", ""]) call _fnc_escape;
    private _lines = [
        "Address check" call _fnc_heading,
        ["Spoken to", (_state getOrDefault ["addressDecision", ""]) call _fnc_address] call _fnc_row,
        "<br/>",
        "Player intent" call _fnc_heading,
        ["Heard as", (_state getOrDefault ["tag", ""]) call _fnc_escape] call _fnc_row,
        ["Topic", (_state getOrDefault ["topicSlot", ""]) call _fnc_escape] call _fnc_row,
        ["Concern addressed", (_state getOrDefault ["addressesConcern", false]) call _fnc_yesNo] call _fnc_row,
        ["Clear", (!(_state getOrDefault ["ambiguous", false])) call _fnc_yesNo] call _fnc_row,
        ["Why", _reason] call _fnc_row,
        "<br/>",
        "Information" call _fnc_heading,
        ["Fact allowed", _factAllowed call _fnc_escape] call _fnc_row,
        ["Facts held back", _factsHeldBack call _fnc_escape] call _fnc_row,
        "<br/>",
        "Decision evidence" call _fnc_heading,
        format ["<t color='#ffffff' size='0.95'>%1</t><br/><br/>", _evidence],
        "Response" call _fnc_heading,
        ["AI used", (_state getOrDefault ["provider", ""]) call _fnc_escape] call _fnc_row,
        ["Understanding", format ["%1 ms", _state getOrDefault ["classifyMs", 0]]] call _fnc_row,
        ["Reply", format ["%1 ms", _state getOrDefault ["replyMs", 0]]] call _fnc_row
    ];
    _lines joinString ""
};

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

private _fnc_setStructured = {
    params ["_idc", "_markup"];
    private _control = _display displayCtrl _idc;
    if ((_control getVariable [QGVAR(lastMarkup), ""]) isEqualTo _markup) exitWith {};
    _control setVariable [QGVAR(lastMarkup), _markup];
    _control ctrlSetStructuredText parseText _markup;
};

(_display displayCtrl IDC_CONSOLE_TITLE) ctrlSetText (_npc getVariable [QGVAR(personaName), name _npc]);
(_display displayCtrl IDC_CONSOLE_PROFILE) ctrlSetText _profile;
[IDC_CONSOLE_DETAILS, call _fnc_state] call _fnc_setStructured;
[IDC_CONSOLE_PIPELINE, call _fnc_exchange] call _fnc_setStructured;
[IDC_CONSOLE_TRANSCRIPT, _lines joinString ""] call _fnc_setStructured;
(_display displayCtrl IDC_CONSOLE_RESET) ctrlEnable (alive _npc);
(_display displayCtrl IDC_CONSOLE_MUTE) ctrlEnable _talkable;
(_display displayCtrl IDC_CONSOLE_UNMUTE) ctrlEnable (!_talkable && {alive _npc} && {!(_npc getVariable [QGVAR(playerDropped), false])});
