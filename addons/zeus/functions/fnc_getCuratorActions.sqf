/*
    Author:
        Tim Beswick

    Description:
        Create and return curator actions

    Parameter(s):
        None

    Return Value:
        Array of actions <ARRAY>
*/
#include "script_component.hpp"

private _actions = [];

private _action = [
    QGVAR(curatorLogin), QUOTE(Login), CURATOR_ICON,
    {[] call FUNC(curatorLogin)},
    {!GVAR(curatorsLocked) && {!GVAR(curatorLogged)} && {(count GVAR(curatorObjects)) < GVAR(curatorsMax)}}
] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [
    QGVAR(curatorLogout), QUOTE(Logout), CURATOR_ICON,
    {[] call FUNC(curatorLogout)},
    {!GVAR(curatorsLocked) && {GVAR(curatorLogged)}}
] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [
    QGVAR(curatorsLock), QUOTE(Lock Curators), CURATOR_ICON,
    {[true] call FUNC(setCuratorsLocked)},
    {!GVAR(curatorsLocked) && {ADMIN_OR_HOST}}
] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [
    QGVAR(curatorsUnlock), QUOTE(Unlock Curators), CURATOR_ICON,
    {[false] call FUNC(setCuratorsLocked)},
    {GVAR(curatorsLocked) && {ADMIN_OR_HOST}}
] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [
    QGVAR(curatorKickAll), QUOTE(Kick All), CURATOR_ICON,
    {[true] call FUNC(curatorKick)},
    {(ADMIN_OR_HOST) && {!(GVAR(curatorObjects) isEqualTo [])}}
] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

{
    _action = [
        format [QGVAR(curatorKick_%1), _forEachIndex], format ["Kick: %1", (name (getAssignedCuratorUnit _x))], CURATOR_ICON,
        {[false, getAssignedCuratorUnit _x] call FUNC(curatorKick)},
        {ADMIN_OR_HOST}
    ] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], player];
} forEach GVAR(curatorObjects);

_actions
