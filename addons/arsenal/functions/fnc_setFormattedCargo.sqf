/*
    Author:
        Tim Beswick

    Description:
        Sets variable on crate containing single array of all gear.

    Parameter(s):
        0: Crate <OBJECT>
        1: Cargo <ARRAY>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_crate", "_cargo"];

private _formattedCargo = [];
if ("%ALL" in _cargo) then {
    _formattedCargo append ["%ALL"];
} else {
    _formattedCargo append (_cargo select 0);
    _formattedCargo append (_cargo select 1);
    _formattedCargo append (_cargo select 2);
    _formattedCargo append (_cargo select 3);
};

_crate setvariable [QGVAR(formattedCargo), _formattedCargo, true];
publicvariable QGVAR(formattedCargo);
