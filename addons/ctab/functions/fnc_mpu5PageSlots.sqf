#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the MPU-5 TX slot and monitor audio page.
        Each TX slot holds a talk group that the matching CBA key transmits on without changing the active talk group.
        Monitor audio sets the volume and ear of one monitored talk group.

    Parameter(s):
        0: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_group] call uksf_ctab_fnc_mpu5PageSlots
*/

params ["_group"];

private _talkgroups = [];
for "_talkgroup" from 1 to MPU5_TALKGROUPS do {
    _talkgroups pushBack [format ["TG %1", _talkgroup], _talkgroup];
};

private _slotCombos = [];
private _slots = [GVAR(mpu5Radio)] call acre_sys_mpu5_fnc_getTxSlots;
for "_slot" from 0 to 3 do {
    [_group, "cTab_RscText", [0.03 + (_slot mod 2) * 0.48, 0.12 + floor (_slot / 2) * 0.09, 0.2, 0.07], format ["TX slot %1", _slot + 1]] call FUNC(createCtrl);
    private _combo = [_group, [0.23 + (_slot mod 2) * 0.48, 0.12 + floor (_slot / 2) * 0.09, 0.24, 0.07], [["Off", 0]] + _talkgroups, _slots select _slot, {
        params ["_talkgroup", "_combo"];
        if (GVAR(mpu5Refreshing)) exitWith {};
        private _slots = [GVAR(mpu5Radio)] call acre_sys_mpu5_fnc_getTxSlots;
        _slots set [_combo getVariable QGVAR(slot), _talkgroup];
        [GVAR(mpu5Radio), _slots] call acre_sys_mpu5_fnc_setTxSlots;
        call FUNC(mpu5Refresh);
    }] call FUNC(createCombo);
    _combo setVariable [QGVAR(slot), _slot];
    _slotCombos pushBack _combo;
};
uiNamespace setVariable [QGVAR(mpu5Slots), _slotCombos];

[_group, "cTab_RscText", [0.03, 0.31, 0.6, 0.06], "Monitor audio"] call FUNC(createCtrl);
[_group, [0.03, 0.38, 0.2, 0.07], _talkgroups select [0, MPU5_TALKGROUPS - 1], GVAR(mpu5AudioTalkgroup), {
    params ["_talkgroup"];
    GVAR(mpu5AudioTalkgroup) = _talkgroup;
    call FUNC(mpu5Refresh);
}] call FUNC(createCombo);

private _applyAudio = {
    params ["", "_combo"];
    if (GVAR(mpu5Refreshing)) exitWith {};
    private _value = {
        params ["_combo"];
        (_combo getVariable QGVAR(values)) select (0 max lbCurSel _combo)
    };
    [GVAR(mpu5Radio), GVAR(mpu5AudioTalkgroup), [APP_CTRL(mpu5Volume)] call _value, [APP_CTRL(mpu5Ear)] call _value] call acre_sys_mpu5_fnc_setMonitorAudio;
    call FUNC(mpu5Refresh);
};
uiNamespace setVariable [QGVAR(mpu5Volume), [_group, [0.25, 0.38, 0.3, 0.07], [["Volume 100%", 1], ["Volume 75%", 0.75], ["Volume 50%", 0.5], ["Volume 25%", 0.25]], 1, _applyAudio] call FUNC(createCombo)];
uiNamespace setVariable [QGVAR(mpu5Ear), [_group, [0.57, 0.38, 0.4, 0.07], [["Ear: radio setting", -2], ["Ear: left", -1], ["Ear: both", 0], ["Ear: right", 1]], -2, _applyAudio] call FUNC(createCombo)];

uiNamespace setVariable [QGVAR(mpu5Info), [_group, [0.03, 0.47, 0.94, 0.5]] call FUNC(createInfo)];
