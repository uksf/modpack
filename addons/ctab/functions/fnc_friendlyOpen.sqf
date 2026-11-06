#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Friendly app.
        The list shows each friendly group that cTab tracks, nearest first. Selecting a group shows its position and members and centres the map on it.
        While the app is open, the map labels tracked friendlies with their names and headings.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_friendlyOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.6, 0.08], "Friendly"] call FUNC(createCtrl);
[_group, [0.66, 0.02, 0.3, 0.08], "Refresh", {call FUNC(friendlyRefresh)}] call FUNC(createButton);
uiNamespace setVariable [QGVAR(friendlyList), [_group, QGVAR(listBox), [0.04, 0.11, 0.92, 0.3]] call FUNC(createCtrl)];
uiNamespace setVariable [QGVAR(friendlyInfo), [_group, [0.04, 0.43, 0.92, 0.55]] call FUNC(createInfo)];
uiNamespace setVariable [QGVAR(friendlyMap), _map];

APP_CTRL(friendlyList) ctrlAddEventHandler ["LBSelChanged", {
    params ["_list", "_index"];
    if (_index < 0) exitWith {};
    [GVAR(friendlyGroups) select (_list lbValue _index)] call FUNC(friendlyShow);
}];

call FUNC(friendlyRefresh);
