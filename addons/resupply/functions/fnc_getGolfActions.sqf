#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Bridgford

    Description:
        Gets golf actions for container

    Parameter(s):
        0: Resupply container <OBJECT>

    Return Value:
        Array of actions <ARRAY>
*/
params ["_target"];

private _actions = [];

private _action = [QGVAR(reviewTypes), "Review Golf Boxes", "", {
    private _descriptions = GVAR(golfClasses) apply {[_x#1, _x#2] joinString " - "};

    private _text = format ["<t color='#fec400'>Available Golf Crates:</t><t><br/><br/>%1</t>", _descriptions joinString "<br/>"];
    private _structuredText = composeText [lineBreak, parseText _text];
    [_structuredText, 2 + (0.5 * count _descriptions), ACE_player, 18] call ace_common_fnc_displayTextStructured;
}, {true}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _target];

{
    _x params ["_class", "_name", "_description"];

    private _action = [format [QUOTE(GVAR(create)_%1), _name], _name, "", {
        params ["_container", "_player", "_actionParams"];
        _actionParams params ["_class", "_name"];

        [2, [_container, _class, _name, _player], {
            params ["_args"];
            _args params ["_container", "_class", "", "_player"];

            private _position = [_container, "_class", _player, 10, true] call ace_common_fnc_findUnloadPosition;
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
} forEach GVAR(golfClasses);

_actions
