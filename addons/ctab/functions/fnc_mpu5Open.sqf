#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the MPU-5 app, which sets the active talk group, the monitored talk groups, and the power of a carried MPU-5, and shows its mesh status.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_mpu5Open
*/

params ["", "_group"];

[_group, "cTab_RscText", [0.03, 0.02, 0.4, 0.08], "MPU-5"] call FUNC(createCtrl);

private _radios = call FUNC(mpu5Radios);
if (_radios isEqualTo []) exitWith {
    private _info = [_group, [0.03, 0.12, 0.94, 0.3]] call FUNC(createInfo);
    [_info, ["No MPU-5 carried."]] call FUNC(setInfo);
};
if !(GVAR(mpu5Radio) in _radios) then {
    GVAR(mpu5Radio) = _radios select 0;
};

[_group, [0.45, 0.02, 0.52, 0.08], _radios apply {[format ["MPU-5 %1", (_radios find _x) + 1], _x]}, GVAR(mpu5Radio), {
    params ["_radioId"];
    GVAR(mpu5Radio) = _radioId;
    call FUNC(mpu5Refresh);
}] call FUNC(createCombo);

[_group, "cTab_RscText", [0.03, 0.12, 0.25, 0.07], "Talk group"] call FUNC(createCtrl);
private _talkgroups = [];
for "_talkgroup" from 1 to MPU5_TALKGROUPS do {
    _talkgroups pushBack [[format ["TG %1", _talkgroup], "TG 16 emergency"] select (_talkgroup == MPU5_TALKGROUPS), _talkgroup];
};
uiNamespace setVariable [QGVAR(mpu5Talkgroup), [_group, [0.3, 0.12, 0.4, 0.07], _talkgroups, [GVAR(mpu5Radio)] call acre_api_fnc_getRadioChannel, {
    params ["_talkgroup"];
    if (_talkgroup != [GVAR(mpu5Radio)] call acre_api_fnc_getRadioChannel) then {
        [GVAR(mpu5Radio), _talkgroup] call acre_api_fnc_setRadioChannel;
    };
    call FUNC(mpu5Refresh);
}] call FUNC(createCombo)];

uiNamespace setVariable [QGVAR(mpu5Power), [_group, [0.74, 0.12, 0.23, 0.07], "Power", {
    private _on = [GVAR(mpu5Radio), "getOnOffState"] call acre_sys_data_fnc_dataEvent;
    [GVAR(mpu5Radio), "setOnOffState", 1 - _on] call acre_sys_data_fnc_dataEvent;
    call FUNC(mpu5Refresh);
}] call FUNC(createButton)];

[_group, "cTab_RscText", [0.03, 0.21, 0.6, 0.06], "Monitor talk groups"] call FUNC(createCtrl);
[_group, [0.74, 0.21, 0.23, 0.06], "Refresh", {call FUNC(mpu5Refresh)}] call FUNC(createButton);

private _buttons = [];
for "_talkgroup" from 1 to MPU5_TALKGROUPS - 1 do {
    private _index = _talkgroup - 1;
    private _button = [_group, [0.03 + (_index mod 8) * 0.1175, 0.28 + floor (_index / 8) * 0.09, 0.105, 0.08], str _talkgroup, {
        params ["_button"];
        private _talkgroup = _button getVariable QGVAR(talkgroup);
        private _monitors = [GVAR(mpu5Radio)] call acre_sys_mpu5_fnc_getMonitors;
        _monitors = [_monitors + [_talkgroup], _monitors - [_talkgroup]] select (_talkgroup in _monitors);
        [GVAR(mpu5Radio), _monitors] call acre_sys_mpu5_fnc_setMonitors;
        call FUNC(mpu5Refresh);
    }] call FUNC(createButton);
    _button setVariable [QGVAR(talkgroup), _talkgroup];
    _buttons pushBack _button;
};
uiNamespace setVariable [QGVAR(mpu5Monitors), _buttons];

uiNamespace setVariable [QGVAR(mpu5Info), [_group, [0.03, 0.47, 0.94, 0.5]] call FUNC(createInfo)];

call FUNC(mpu5Refresh);
