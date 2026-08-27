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
private _factsRevealed = if (_disclosed isEqualTo "") then {["None"]} else {_disclosedIds};
private _factAllowed = if (_eligible isEqualTo "") then {"None"} else {_eligible};
private _factsHeldBack = if (_blocked isEqualTo []) then {["None"]} else {_blocked};
private _speechItems = ["idle", "waiting", "filler", "speaking", "streaming"];
private _bandItems = ["closed", "guarded", "engaged", "cooperative"];
private _cooperation = (_state getOrDefault ["cooperation", ""]) call _fnc_escape;

private _fnc_stateSpec = {
    [
        ["heading", "Current status"],
        ["leds", [["Alive", alive _npc], ["Can talk", _talkable], ["Looking at this NPC", _npc isEqualTo GVAR(targetNpc)]]],
        ["row", ["Speech", _audio]],
        ["strip", [_speechItems, _audio]],
        ["row", ["Last mood", (_state getOrDefault ["mood", _npc getVariable [QGVAR(personaMood), ""]]) call _fnc_escape]],
        ["row", ["Last gesture", (_state getOrDefault ["emote", ""]) call _fnc_escape]],
        ["divider", ""],
        ["heading", "Conversation progress"],
        ["row", ["Cooperation", _cooperation]],
        ["strip", [_bandItems, _cooperation]],
        ["row", ["Warning", _warning]],
        ["row", ["Conversation", _conversation]],
        ["row", ["Facts revealed", ""]],
        ["chip", _factsRevealed]
    ]
};

private _fnc_exchangeSpec = {
    [
        ["heading", "Address check"],
        ["row", ["Spoken to", (_state getOrDefault ["addressDecision", ""]) call _fnc_address]],
        ["divider", ""],
        ["heading", "Player intent"],
        ["row", ["Heard as", (_state getOrDefault ["tag", ""]) call _fnc_escape]],
        ["row", ["Topic", (_state getOrDefault ["topicSlot", ""]) call _fnc_escape]],
        ["row", ["Concern addressed", (_state getOrDefault ["addressesConcern", false]) call _fnc_yesNo]],
        ["row", ["Clear", (!(_state getOrDefault ["ambiguous", false])) call _fnc_yesNo]],
        ["row", ["Why", (_state getOrDefault ["reason", ""]) call _fnc_escape]],
        ["divider", ""],
        ["heading", "Information"],
        ["row", ["Fact allowed", _factAllowed call _fnc_escape]],
        ["row", ["Facts held back", ""]],
        ["chip", _factsHeldBack],
        ["divider", ""],
        ["heading", "Decision evidence"],
        ["row", ["", (_state getOrDefault ["evidence", ""]) call _fnc_escape]],
        ["divider", ""],
        ["heading", "Response"],
        ["row", ["AI used", (_state getOrDefault ["provider", ""]) call _fnc_escape]],
        ["row", ["Understanding", (format ["%1 ms", _state getOrDefault ["classifyMs", 0]]) call _fnc_escape]],
        ["row", ["Reply", (format ["%1 ms", _state getOrDefault ["replyMs", 0]]) call _fnc_escape]]
    ]
};

private _entries = +(_state getOrDefault ["transcript", []]);
reverse _entries;
private _transcriptSpec = [];
{
    _x params ["_time", "_who", "_text"];
    _transcriptSpec pushBack ["transcript", [
        [_time, "HH:MM:SS"] call BIS_fnc_secondsToString,
        [_who] call FUNC(consoleEscape),
        [_text] call FUNC(consoleEscape),
        (_forEachIndex % 2) isEqualTo 0
    ]];
} forEach _entries;
if (_transcriptSpec isEqualTo []) then {
    _transcriptSpec = [["row", ["", "No consumed speech yet."]]];
};

(_display displayCtrl IDC_CONSOLE_TITLE) ctrlSetText (_npc getVariable [QGVAR(personaName), name _npc]);
private _profileCtrl = _display displayCtrl IDC_CONSOLE_PROFILE;
_profileCtrl ctrlSetText _profile;
_profileCtrl ctrlSetBackgroundColor [0.08, 0.1, 0.12, 1];
if (_profile isEqualTo "guarded") then {
    _profileCtrl ctrlSetTextColor [1, 0.83, 0.42, 1];
} else {
    _profileCtrl ctrlSetTextColor [0.58, 0.77, 0.99, 1];
};

[_display, _display displayCtrl IDC_CONSOLE_STATE_BODY, call _fnc_stateSpec] call FUNC(consoleRenderInspector);
[_display, _display displayCtrl IDC_CONSOLE_EXCHANGE_BODY, call _fnc_exchangeSpec] call FUNC(consoleRenderInspector);
[_display, _display displayCtrl IDC_CONSOLE_TRANSCRIPT_BODY, _transcriptSpec] call FUNC(consoleRenderInspector);
(_display displayCtrl IDC_CONSOLE_RESET) ctrlEnable (alive _npc);
(_display displayCtrl IDC_CONSOLE_MUTE) ctrlEnable _talkable;
(_display displayCtrl IDC_CONSOLE_UNMUTE) ctrlEnable (!_talkable && {alive _npc} && {!(_npc getVariable [QGVAR(playerDropped), false])});
