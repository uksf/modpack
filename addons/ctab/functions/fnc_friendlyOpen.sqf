#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Friendly app.
        The list shows each friendly group that cTab tracks, nearest first. Selecting a group shows its position and members.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_friendlyOpen
*/
params ["", "_group"];

uiNamespace setVariable [QGVAR(friendlyList), [_group, QGVAR(listBox), [0.02, 0.03, 0.4, 0.82]] call FUNC(createCtrl)];
uiNamespace setVariable [QGVAR(friendlyInfo), [_group, [0.45, 0.03, 0.53, 0.94]] call FUNC(createInfo)];
[_group, [0.02, 0.87, 0.4, 0.1], "Refresh", {call FUNC(friendlyRefresh)}] call FUNC(createButton);

APP_CTRL(friendlyList) ctrlAddEventHandler ["LBSelChanged", {
    params ["_list", "_index"];
    if (_index < 0) exitWith {};
    [GVAR(friendlyGroups) select (_list lbValue _index)] call FUNC(friendlyShow);
}];

call FUNC(friendlyRefresh);
