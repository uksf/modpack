#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches active tab in uncon dialog. Updates container visibility + button colour.

    Parameter(s):
        0: Tab name <STRING> — "spectator" | "health" | "settings"

    Return Value:
        None

    Example:
        ["health"] call uksf_medical_fnc_switchTab
*/
params ["_tab"];

private _enabled = switch (_tab) do {
    case "spectator": { GVAR(showSpectator) };
    case "health": { GVAR(showHealth) };
    default { true };
};

if (!_enabled) exitWith {
    private _fallback = if (GVAR(showHealth) && {_tab == "spectator"}) then { "health" } else { "settings" };
    [_fallback] call FUNC(switchTab);
};

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

GVAR(currentTab) = _tab;

(_display displayCtrl IDC_CONTAINER_SPECTATOR) ctrlShow (_tab == "spectator");
(_display displayCtrl IDC_CONTAINER_HEALTH) ctrlShow (_tab == "health");
(_display displayCtrl IDC_CONTAINER_SETTINGS) ctrlShow (_tab == "settings");

private _buttonMap = createHashMapFromArray [
    ["spectator", IDC_TAB_SPECTATOR_BTN],
    ["health", IDC_TAB_HEALTH_BTN],
    ["settings", IDC_TAB_SETTINGS_BTN]
];

{
    private _btn = _display displayCtrl _y;
    if (_x == _tab) then {
        _btn ctrlSetBackgroundColor [0.3, 0.3, 0.3, 0.9];
    } else {
        _btn ctrlSetBackgroundColor [0.15, 0.15, 0.15, 0.85];
    };
} forEach _buttonMap;

(_display displayCtrl IDC_TAB_SPECTATOR_BTN) ctrlEnable GVAR(showSpectator);
(_display displayCtrl IDC_TAB_HEALTH_BTN) ctrlEnable GVAR(showHealth);

if (_tab == "settings") then {
    [] call FUNC(settingsTabBuild);
};
