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

private _action = [QGVAR(curatorLogin), QUOTE(Login), CURATOR_ICON, {[] call FUNC(curatorLogin)}, {CONDITION_LOGIN}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorLogout), QUOTE(Logout), CURATOR_ICON, {[] call FUNC(curatorLogout)}, {CONDITION_LOGOUT}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorsLock), QUOTE(Lock Curators), CURATOR_ICON, {[true] call FUNC(setCuratorsLocked)}, {CONDITION_LOCK}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorsUnlock), QUOTE(Unlock Curators), CURATOR_ICON, {[false] call FUNC(setCuratorsLocked)}, {CONDITION_UNLOCK}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

_action = [QGVAR(curatorKickAll), QUOTE(Kick All), CURATOR_ICON, {[true] call FUNC(curatorKick)}, {CONDITION_KICKALL}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], player];

{
    private _player = _x;
    if (_player != "") then {
        _action = [
            format [QGVAR(curatorKick_%1), _player],
            format ["Kick: %1", _player],
            CURATOR_ICON,
            {[false, ((_this select 2) select 0)] call FUNC(curatorKick)},
            {MULTIPLAYER_ADMIN_OR_WHITELISTED},
            {},
            [_player]
        ] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], player];
    };
} forEach GVAR(curatorPlayers);

_actions
