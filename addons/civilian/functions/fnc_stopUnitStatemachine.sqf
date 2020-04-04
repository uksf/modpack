#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes civilian from units statemachine

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if !(local _unit) exitWith {};

if !(isNull GVAR(unit_statemachine)) exitWith {
    [_unit, GVAR(unit_statemachine), QGVAR(unit_state_exit), QGVAR(unit_state_exit)] call CBA_statemachine_fnc_manualTransition;
};
