#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the MPU-5 app header, with the page and radio selectors, then the selected page.
        Pages set the talk groups and power, the TX slots and monitor audio, or the radio over IP gateway and bridge.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_mpu5Open
*/

params ["", "_group"];

private _radios = call FUNC(mpu5Radios);
if (_radios isEqualTo []) exitWith {
    [_group, "cTab_RscText", [0.03, 0.02, 0.4, 0.08], "MPU-5"] call FUNC(createCtrl);
    private _info = [_group, [0.03, 0.12, 0.94, 0.3]] call FUNC(createInfo);
    [_info, ["No MPU-5 carried."]] call FUNC(setInfo);
};
if !(GVAR(mpu5Radio) in _radios) then {
    GVAR(mpu5Radio) = _radios select 0;
};

private _pages = [["Talk groups", "talkgroups"], ["TX slots and audio", "slots"], ["Gateway and bridge", "gateway"]];
[_group, [0.03, 0.02, 0.4, 0.08], _pages, GVAR(mpu5Page), {
    params ["_page", "_combo"];
    GVAR(mpu5Page) = _page;
    [{
        params ["_display"];
        if (isNull _display || {GVAR(currentApp) != "mpu5"}) exitWith {};
        [_display] call FUNC(closeContent);
        [_display, "mpu5"] call FUNC(openApp);
    }, [ctrlParent _combo]] call CBA_fnc_execNextFrame;
}] call FUNC(createCombo);

[_group, [0.45, 0.02, 0.52, 0.08], _radios apply {[format ["MPU-5 %1", (_radios find _x) + 1], _x]}, GVAR(mpu5Radio), {
    params ["_radioId"];
    GVAR(mpu5Radio) = _radioId;
    call FUNC(mpu5Refresh);
}] call FUNC(createCombo);

switch (GVAR(mpu5Page)) do {
    case "slots": {[_group] call FUNC(mpu5PageSlots)};
    case "gateway": {[_group] call FUNC(mpu5PageGateway)};
    default {[_group] call FUNC(mpu5PageTalkgroups)};
};

call FUNC(mpu5Refresh);
