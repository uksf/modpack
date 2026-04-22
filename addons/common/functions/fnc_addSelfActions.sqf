#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace self interaction

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_common_fnc_addSelfActions
*/

private _fnc_children = {
    private _actions = [];

    private _action = [QGVAR(fpsNoPlayers), "No Players", "", {[1] call FUNC(fpsHudSetMode)}, {GVAR(fpsHudMode) != 1}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(fpsLowPlayers), "Low FPS Players", "", {[2] call FUNC(fpsHudSetMode)}, {GVAR(fpsHudMode) != 2}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(fpsAllPlayers), "All Players", "", {[3] call FUNC(fpsHudSetMode)}, {GVAR(fpsHudMode) != 3}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

private _action = [
    QGVAR(fpsAction),
    "FPS",
    "\A3\ui_f\data\gui\rsc\rscdisplayoptionsvideo\icon_performance.paa",
    {
        private _mode = if (GVAR(fpsHudMode) == 0) then { 1 } else { 0 };
        [_mode] call FUNC(fpsHudSetMode);
    },
    {ADMIN_OR_WHITELISTED},
    _fnc_children,
    [],
    {[0, 0, 0]},
    2,
    [false, false, false, false, false],
    {
        private _actionData = _this select 3;
        _actionData set [1, ["FPS Off", "FPS On"] select (GVAR(fpsHudMode) == 0)];
    }
] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
