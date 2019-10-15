#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Paste loadout from global variable to unit

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
    case (!(alive _object)): {
        ["Unit must be alive"] call ace_zeus_fnc_showMessage;
    };
    default {
        if (GVAR(loadout) isEqualTo "") then {
            ["Copy a loadout first"] call ace_common_fnc_displayTextStructured;
        } else {
            _object setUnitLoadout GVAR(loadout);
            ["Loadout pasted"] call ace_common_fnc_displayTextStructured;
        };
    };
};

deleteVehicle _logic;
