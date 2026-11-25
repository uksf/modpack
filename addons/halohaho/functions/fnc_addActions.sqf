#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Adds ace interactions for halo/haho

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_halohaho_fnc_addActions
*/

private _fnc_children = {
    params ["", "_player"];

    private _actions = [];

    private _action = [QGVAR(connectOxygen), "Connect Oxygen", "", {
        params ["", "_player"];

        [_player] call FUNC(connectOxygen);
    }, {!GVAR(oxygenConnected) && {[_player, QGVAR(airSupply)] call ace_common_fnc_hasItem}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(disconnectOxygen), "Disconnect Oxygen", "", {
        call FUNC(disconnectOxygen);
        "Oxygen disconnected" call CBA_fnc_notify;
        DEBUG("Oxygen disconnected");
    }, {GVAR(oxygenConnected)}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

private _action = [QGVAR(halohaho), "HALO/HAHO", "", {}, {isPlayer _player && {goggles _player == HALOHAHO_MASK || GVAR(oxygenConnected)}}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
