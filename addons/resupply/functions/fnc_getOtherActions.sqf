#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Bridgford

    Description:
        Gets other actions for container

    Parameter(s):
        0: Resupply container <OBJECT>

    Return Value:
        Array of actions <ARRAY>
*/
params ["_target"];

private _actions = [];

{
    _x params ["_class", "_name", "_description"];

    private _action = [format [QUOTE(GVAR(create)_%1), _name], _name, "", {
        params ["_container", "_player", "_actionParams"];
        _actionParams params ["_class", "_name"];

        [2, [_container, _class, _name, _player], {
            params ["_args"];
            _args params ["_container", "_class", "", "_player"];

            private _position = [_container, _class, _player, 30, true] call ace_common_fnc_findUnloadPosition;
            if (_position isNotEqualTo []) then {
                createVehicle [_class, _position, [], 0, "CAN_COLLIDE"];
            } else {
                createVehicle [_class, _player, [], 0, "NONE"];
            };
        }, {
            params ["_args"];
            _args params ["", "_class", "_name"];

            hint format ["Failed to unload %1", _name];
        }, format ["Unloading %1 from container", _name]] call ace_common_fnc_progressBar;
    }, {true}, {}, [_class, _name]] call ace_interact_menu_fnc_createAction;

    _actions pushBack [_action, [], _target];
} forEach GVAR(otherClasses);

_actions
