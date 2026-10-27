#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Handles an action in the radio presets manager
        Presets are stored in the profile as [name, radio data]

    Parameter(s):
        0: Presets display <DISPLAY>
        1: Action, one of "refresh", "select", "save", "load", "delete" <STRING>

    Return Value:
        None

    Example:
        [_display, "save"] call uksf_radios_fnc_presetsAction
*/
params ["_display", "_action"];

private _list = _display displayCtrl IDC_RADIO_PRESETS_LIST;
private _nameControl = _display displayCtrl IDC_RADIO_PRESETS_NAME;
private _presets = profileNamespace getVariable [QGVAR(presets), []];
private _selected = _list lbData lbCurSel _list;
private _selectedIndex = _presets findIf {_x#0 == _selected};
private _status = "";

private _storePresets = {
    profileNamespace setVariable [QGVAR(presets), _presets];
    saveProfileNamespace;
};

switch (_action) do {
    case "select": {
        _nameControl ctrlSetText _selected;
        private _details = "";
        if (_selectedIndex != -1) then {
            private _radioData = _presets#_selectedIndex#1;
            private _pttOrder = _radioData apply {_x#4};
            _pttOrder sort true;
            private _lines = _radioData apply {
                _x params ["_type", "_channel", "_volume", "_ear", "_pttIndex"];
                private _pttKey = (_pttOrder find _pttIndex) + 1;
                format [
                    "<t font='PuristaMedium'>%1</t><br/>Channel %2, %3, volume %4%%, %5",
                    getText (EGVAR(common,configWeapons) >> _type >> "displayName"),
                    _channel,
                    ["both ears", "left ear", "right ear"] select ((["LEFT", "RIGHT"] find _ear) + 1),
                    round (_volume * 100),
                    ["no PTT key", format ["PTT %1", _pttKey]] select (_pttKey <= 3)
                ]
            };
            _details = _lines joinString "<br/><br/>";
        };
        (_display displayCtrl IDC_RADIO_PRESETS_DETAILS) ctrlSetStructuredText parseText _details;
    };
    case "save": {
        private _name = trim ctrlText _nameControl;
        if (_name == "") exitWith {_status = "Enter a preset name"};
        private _radioData = [acre_player] call FUNC(serializeRadios);
        if (_radioData isEqualTo []) exitWith {_status = "You have no radios to save"};
        private _index = _presets findIf {_x#0 == _name};
        if (_index == -1) then {
            _presets pushBack [_name, _radioData];
        } else {
            _presets set [_index, [_name, _radioData]];
        };
        call _storePresets;
        _selected = _name;
        _status = format ["Saved %1", _name];
    };
    case "load": {
        if (_selectedIndex == -1) exitWith {_status = "Select a preset"};
        [_presets#_selectedIndex#1] call FUNC(applyPreset);
        _status = format [["Loaded %1", "Loaded %1, applied when you close the arsenal"] select acre_sys_core_arsenalOpen, _selected];
    };
    case "delete": {
        if (_selectedIndex == -1) exitWith {_status = "Select a preset"};
        _presets deleteAt _selectedIndex;
        call _storePresets;
        _status = format ["Deleted %1", _selected];
        _selected = "";
    };
};

if (_action in ["select", "load"]) exitWith {
    if (_status != "") then {(_display displayCtrl IDC_RADIO_PRESETS_STATUS) ctrlSetText _status};
};

lbClear _list;
{
    _list lbSetData [_list lbAdd (_x#0), _x#0];
} forEach _presets;
lbSort _list;
(_display displayCtrl IDC_RADIO_PRESETS_STATUS) ctrlSetText _status;

private _row = -1;
for "_i" from 0 to (lbSize _list - 1) do {
    if (_list lbData _i == _selected) exitWith {_row = _i};
};
_list lbSetCurSel _row;
if (_row == -1) then {[_display, "select"] call FUNC(presetsAction)};
