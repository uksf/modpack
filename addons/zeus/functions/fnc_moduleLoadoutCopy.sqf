/*
    Author:
        Tim Beswick

    Description:
        Copy loadout of unit to global variable

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

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
        GVAR(loadout) = getUnitLoadout _object;
        ["Loadout copied"] call ace_common_fnc_displayTextStructured;
    };
};

deleteVehicle _logic;
