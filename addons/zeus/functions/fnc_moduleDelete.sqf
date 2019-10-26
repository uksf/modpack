#include "script_component.hpp"
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
params ["_logic"];

if (!local _logic) exitWith {};

private _object = attachedTo _logic;

if (isNull _object) exitWith {["Place on an object"] call ace_zeus_fnc_showMessage;};
if (isPlayer _object) exitWith {["str_a3_cfgvehicles_moduleremotecontrol_f_errorPlayer"] call ace_zeus_fnc_showMessage;};

deleteVehicle _object;
deleteVehicle _logic;
