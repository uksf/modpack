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

GVAR(vehicle_statemachine_vehicles) pushBack _vehicle;

if !(isNull GVAR(vehicle_statemachine)) exitWith {
    [_vehicle, GVAR(vehicle_statemachine), QGVAR(vehicle_state_enter), QGVAR(vehicle_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(vehicle_statemachine) = [{GVAR(vehicle_statemachine_vehicles)}, true] call CBA_statemachine_fnc_create;

call FUNC(addVehicleStates);
call FUNC(addVehicleTransitions);
call FUNC(addVehicleEventTransitions);
