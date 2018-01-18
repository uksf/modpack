/*
    Author:
        Tim Beswick, Alganthe

    Description:
        Force delete object

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
        ["Place on an object"] call ace_zeus_fnc_showMessage;
    };
    case (isPlayer _object): {
        ["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;
    };
    default {
        deleteVehicle _object;
    };
};

deleteVehicle _logic;
