#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles whether the group can support friendly units

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/

params ["_logic"];

if (!local _logic) exitWith {};

private _object = attachedTo _logic;

switch (true) do {
    case (isNull _object || {!(_object isKindOf "CAManBase")}): {
        ["Place on a unit"] call ace_zeus_fnc_showMessage;
    };
    case (isPlayer _object): {
        ["Unit must be AI"] call ace_zeus_fnc_showMessage;
    };
    case (!(alive _object)): {
        ["Unit must be alive"] call ace_zeus_fnc_showMessage;
    };
    default {
        private _state = _object getVariable [QGVAR(hasRadio), true];
        if (!_state) then {
            _object setVariable [QGVAR(hasRadio), true, true];
            ["Unit will support"] call ace_common_fnc_displayTextStructured;
        } else {
            _object setVariable [QGVAR(hasRadio), false, true];
            ["Unit won't support"] call ace_common_fnc_displayTextStructured;
        };
    };
};

deleteVehicle _logic;
