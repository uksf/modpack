#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts statemachine for civilian vehicle stop

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        Nothing
*/
params ["_vehicle"];

if !(local _vehicle) exitWith {};

GVAR(stop_statemachine_vehicles) pushBack _vehicle;

if !(isNull GVAR(stop_statemachine)) exitWith {
    [_vehicle, GVAR(stop_statemachine), QGVAR(stop_state_enter), QGVAR(stop_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(stop_statemachine) = [GVAR(stop_statemachine_vehicles), true] call CBA_statemachine_fnc_create;

call FUNC(addStopStates);
call FUNC(addStopTransitions);
call FUNC(addStopEventTransitions);
