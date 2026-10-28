#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Weather app, which shows the light, sky, wind, and ACE weather at the player's position.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_weatherOpen
*/
params ["", "_group"];

[_group, "cTab_RscText", [0.03, 0.03, 0.6, 0.08], "Weather"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(weatherInfo), [_group, [0.03, 0.13, 0.94, 0.84]] call FUNC(createInfo)];
[_group, [0.72, 0.02, 0.25, 0.1], "Refresh", {call FUNC(weatherRefresh)}] call FUNC(createButton);

call FUNC(weatherRefresh);
