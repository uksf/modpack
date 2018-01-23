/*
    Author:
        Tim Beswick

    Description:
        Fully heals unit

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
    case (isNull _object): {
        ["Place on a unit"] call ace_zeus_fnc_showMessage;
    };
    case (!(alive _object)): {
        ["Unit must be alive"] call ace_zeus_fnc_showMessage;
    };
    default {
        [_object, _object] remoteExecCall ["ace_medical_fnc_treatmentAdvanced_fullHealLocal", _object];
        _object setDamage 0;
        ["Unit full healed"] call ace_common_fnc_displayTextStructured;
    };
};

deleteVehicle _logic;
