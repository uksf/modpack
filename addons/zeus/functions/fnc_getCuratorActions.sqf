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

private _action = [QGVAR(curatorLogin), QUOTE(Login), CURATOR_ICON, {[] call FUNC(curatorLogin)}, {((ADMIN_OR_HOST) || !GVAR(curatorsLocked)) && (isNull (getAssignedCuratorLogic player)) && ((count GVAR(curatorObjects)) < GVAR(curatorsMax))}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorLogout), QUOTE(Logout), CURATOR_ICON, {[] call FUNC(curatorLogout)}, {((ADMIN_OR_HOST) || !GVAR(curatorsLocked)) && (!isNull (getAssignedCuratorLogic player))}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorsLock), QUOTE(Lock Curators), CURATOR_ICON, {[true] call FUNC(setCuratorsLocked)}, {!GVAR(curatorsLocked) && (ADMIN_OR_HOST)}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorsUnlock), QUOTE(Unlock Curators), CURATOR_ICON, {[false] call FUNC(setCuratorsLocked)}, {GVAR(curatorsLocked) && (ADMIN_OR_HOST)}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorKickAll), QUOTE(Kick All), CURATOR_ICON, {[true] call FUNC(curatorKick)}, {(ADMIN_OR_HOST) && isMultiplayer && (!(GVAR(curatorObjects) isEqualTo []))}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

{
    private _curator = _x;
    if (!isNull (getAssignedCuratorUnit _curator)) then {
        _action = [
            format [QGVAR(curatorKick_%1), _curator],
            format ["Kick: %1", (name (getAssignedCuratorUnit _curator))],
            CURATOR_ICON,
            {[false, getAssignedCuratorUnit (_this select 2 select 0)] call FUNC(curatorKick)},
            {(ADMIN_OR_HOST) && isMultiplayer},
            {},
            [_curator]
        ] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], player];
    };
    false
} count GVAR(curatorObjects);

_actions
