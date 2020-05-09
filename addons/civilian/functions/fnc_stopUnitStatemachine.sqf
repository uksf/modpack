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
    private _id = GVAR(unit_statemachine) getVariable "cba_statemachine_ID";
    private _currentState = _unit getVariable ("cba_statemachine_state" + str _id);

    [_unit, GVAR(unit_statemachine), _currentState, QGVAR(unit_state_exit)] call CBA_statemachine_fnc_manualTransition;
};
