#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Drones app panel.
        The list shows the friendly drones. A click on the map sets the task point. The buttons task the selected drone.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_droneOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.92, 0.08], "Drones"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(droneList), [_group, QGVAR(listBox), [0.04, 0.11, 0.92, 0.33]] call FUNC(createCtrl)];
uiNamespace setVariable [QGVAR(droneInfo), [_group, [0.04, 0.46, 0.92, 0.22]] call FUNC(createInfo)];

{
    _x params ["_text", "_task", "_rect"];
    [_group, _rect, _text, compile format ["['%1'] call %2", _task, QFUNC(droneSend)]] call FUNC(createButton);
} forEach [
    ["Observe point", "observe", [0.04, 0.7, 0.44, 0.09]],
    ["Escort me", "escort", [0.52, 0.7, 0.44, 0.09]],
    ["Hold", "hold", [0.04, 0.81, 0.44, 0.09]],
    ["Return", "return", [0.52, 0.81, 0.44, 0.09]]
];

APP_CTRL(droneList) ctrlAddEventHandler ["LBSelChanged", {call FUNC(droneRefresh)}];

[_map, {
    params ["_position"];
    GVAR(dronePoint) = _position;
    call FUNC(droneRefresh);
}] call FUNC(addMapClickHandler);

private _sides = call cTab_fnc_getPlayerSides;
GVAR(drones) = allUnitsUAV select {alive _x && {side _x in _sides}};
{
    APP_CTRL(droneList) lbAdd format ["%1 (%2)", getText (configOf _x >> "displayName"), (cTab_player distance2D _x) call FUNC(formatDistance)];
} forEach GVAR(drones);
APP_CTRL(droneList) lbSetCurSel ([-1, 0] select (GVAR(drones) isNotEqualTo []));

call FUNC(droneRefresh);
