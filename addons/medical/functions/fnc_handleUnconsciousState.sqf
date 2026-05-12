#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Dispatches dialog open / close based on ace_unconscious event.

    Parameter(s):
        0: Unit <OBJECT>
        1: Is unconscious <BOOL>

    Return Value:
        None

    Example:
        [_unit, _isUncon] call uksf_medical_fnc_handleUnconsciousState
*/
params ["_unit", "_isUncon"];

if (_unit != ACE_player) exitWith {};
if (!GVAR(modEnabled)) exitWith {};

if (_isUncon) exitWith {
    [] call FUNC(openDialog);
};

[] call FUNC(closeDialog);
