#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fills the Eden Voice picker from the website voice list the extension has cached.
        The chosen voice stays selected. A voice that is not on the website stays in the
        list, marked, so opening the attributes never changes a mission.

    Parameter(s):
        0: Voice combo <CONTROL>

    Return Value:
        List status: "ready", "pending" or "error" <STRING>

    Example:
        [_combo] call uksf_npc_fnc_edenVoiceFill
*/
params ["_combo"];

private _current = if (lbSize _combo > 0) then {
    _combo lbData lbCurSel _combo
} else {
    _combo getVariable [QGVAR(voiceValue), ""]
};
if (_current == "") then {_current = DEFAULT_VOICE};

private _response = ("uksf" callExtension ["npcVoices", []]) select 0;
// An empty answer means the extension did not load; parseSimpleArray would log an error.
private _parsed = if (_response select [0, 1] == "[") then {parseSimpleArray _response} else {[]};
_parsed params [["_status", "error", [""]], ["_voices", [], [[]]], ["_error", "the UKSF extension did not answer", [""]]];

lbClear _combo;
private _index = _combo lbAdd "Default voice";
_combo lbSetData [_index, DEFAULT_VOICE];
_combo lbSetTextRight [_index, DEFAULT_VOICE];

{
    _x params ["_voiceId", "_name"];
    if (_voiceId != DEFAULT_VOICE) then {
        _index = _combo lbAdd _name;
        _combo lbSetData [_index, _voiceId];
        _combo lbSetTextRight [_index, _voiceId];
    };
} forEach _voices;

private _selected = -1;
for "_i" from 0 to (lbSize _combo - 1) do {
    if (_combo lbData _i == _current) exitWith {_selected = _i};
};
if (_selected < 0) then {
    _selected = _combo lbAdd ([format ["%1 (not on the website)", _current], _current] select (_status != "ready"));
    _combo lbSetData [_selected, _current];
    _combo lbSetTextRight [_selected, _current];
    if (_status == "ready") then {_combo lbSetColor [_selected, [1, 0.6, 0.2, 1]]};
};
_combo lbSetCurSel _selected;

_combo ctrlSetTooltip (switch (_status) do {
    case "ready": {"Voices from the UKSF website NPC voice manager. The NPC changes mood automatically."};
    case "pending": {"Loading the voice list from the UKSF website..."};
    default {format ["Could not load the voice list from the UKSF website (%1). The current voice is kept.", _error]};
});

_status
